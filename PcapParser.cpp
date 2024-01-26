#include "PcapParser.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdint>
#include <vector>
#include <chrono>

#ifdef _WIN32
#include <winsock2.h>

#pragma comment(lib,"Ws2_32.lib")
#else
#include <netinet/in.h>
#endif


uint16_t swap_endian16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

uint32_t swap_endian32(uint32_t val) {
    return ((val << 24) & 0xff000000) |
        ((val << 8) & 0x00ff0000) |
        ((val >> 8) & 0x0000ff00) |
        ((val >> 24) & 0x000000ff);
}



PcapParser::PcapParser(const std::string& filename) {
    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
}

void PcapParser::parseGlobalHeader() {
    file.read(reinterpret_cast<char*>(&globalHeader), sizeof(PcapGlobalHeader));
    if (file.gcount() != sizeof(PcapGlobalHeader)) {
        throw std::runtime_error("Failed to read global header");
    }
}

void PcapParser::parse() {
    parseGlobalHeader();

    auto start = std::chrono::high_resolution_clock::now();
    int itr = 0;
    while (!file.eof()) {
        parsePacket();

        ++itr;
        if (itr % 100000 == 0) {
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            std::cout << "itr=" << itr << " Time taken for 100000 iterations: " << duration.count() << " milliseconds" << std::endl;
            start = std::chrono::high_resolution_clock::now();
        }
    }
}

void PcapParser::setPayloadParser(PayloadParserFunc parser) {
    payloadParser = parser;
}

void PcapParser::setPcapFilter(PcapFilterFunc filter) {
    pcapFilter = filter;
}

void PcapParser::parsePacket() {
    PcapPacketHeader packetHeader;

    file.read(reinterpret_cast<char*>(&packetHeader), sizeof(PcapPacketHeader));
    if (file.gcount() != sizeof(PcapPacketHeader)) {
        // end of file or reading error
        return;
    }

    std::vector<char> packetData(packetHeader.incl_len);
    file.read(packetData.data(), packetHeader.incl_len);

    if (file.gcount() != static_cast<std::streamsize>(packetHeader.incl_len)) {
        throw std::runtime_error("Failed to read package data");
    }

    switch (globalHeader.network) {
    case 1: // Ethernet
        processPayload(packetData.data(), packetData.size());
        break;
    case 105: // IEEE 802.11 Wireless LAN
        break;
    case 101: // Raw IP
        break;
    default:  // Unsupported data link type
        break;
    }
}

void PcapParser::processPayload(const char* packet, size_t packetLength) {
    auto ethHeader = reinterpret_cast<const EthernetHeader*>(packet);
    size_t ethernetHeaderLength = sizeof(EthernetHeader);

    if (ntohs(ethHeader->etherType) != 0x0800) return; // only IPv4
    
    auto ipHeader = reinterpret_cast<const IPv4Header*>(packet + ethernetHeaderLength);
    size_t ipHeaderLength = (ipHeader->versionAndHeaderLength & 0x0F) * 4;

    struct in_addr srcAddr;
    srcAddr.s_addr = ntohl(ipHeader->srcAddr);
    struct in_addr destAddr;
    destAddr.s_addr = ntohl(ipHeader->destAddr);
    
    if (ipHeader->protocol == 6) { // TCP
        auto tcpHeader = reinterpret_cast<const TCPHeader*>(packet + ethernetHeaderLength + ipHeaderLength);
        size_t tcpHeaderLength = (tcpHeader->dataOffset >> 4) * 4;

        const char* payload = packet + ethernetHeaderLength + ipHeaderLength + tcpHeaderLength;
        size_t payloadLength = packetLength - (ethernetHeaderLength + ipHeaderLength + tcpHeaderLength);

        doPayloadParsing(payload, payloadLength);
    }
    else if (ipHeader->protocol == 17) { // UDP
        auto udpHeader = reinterpret_cast<const UDPHeader*>(packet + ethernetHeaderLength + ipHeaderLength);
                
        if (!doPcapFilter(ipHeader, udpHeader)) return;

        size_t udpHeaderLength = 8; 

        const char* payload = packet + ethernetHeaderLength + ipHeaderLength + udpHeaderLength;
        size_t payloadLength = ntohs(udpHeader->length) - udpHeaderLength;

        auto destPort = ntohs(udpHeader->destPort);
        auto srcPort = ntohs(udpHeader->srcPort);
        auto length = ntohs(udpHeader->length);
        auto checksum = ntohs(udpHeader->checksum);

        doPayloadParsing(payload, payloadLength);
    }
    else {
        // not implemented
    }
}

bool PcapParser::doPcapFilter(const IPv4Header* ipHeader, const UDPHeader* udpHeader) {
    if (!pcapFilter) return true;
    return pcapFilter(ipHeader, udpHeader);
}

void PcapParser::doPayloadParsing(const char* packet, size_t packetLength) {
    if (!payloadParser) return;
    payloadParser(packet, packetLength);
}

void PcapParser::parseEthernetHeader(const char* packet) {
    
    auto ethHeader = reinterpret_cast<const EthernetHeader*>(packet);
    
    std::cout << "Source MAC: ";
    for (int i = 0; i < 6; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)ethHeader->srcMac[i];
        if (i < 5) std::cout << ":";
    }
    
    std::cout << ", Destination MAC: ";
    for (int i = 0; i < 6; i++) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)ethHeader->destMac[i];
        if (i < 5) std::cout << ":";
    }
    
    std::cout << ", EtherType: " << std::hex << ntohs(ethHeader->etherType) << std::endl;
    
}

void PcapParser::parseIPv4Header(const char* packet) {
    auto ipHeader = reinterpret_cast<const IPv4Header*>(packet + sizeof(EthernetHeader));

    struct in_addr srcAddr;
    srcAddr.s_addr = ipHeader->srcAddr;

    struct in_addr destAddr;
    destAddr.s_addr = ipHeader->destAddr;

    std::cout << "Source IP: " << inet_ntoa(srcAddr) << ", Destination IP: " << inet_ntoa(destAddr) << std::endl;
}

void PcapParser::checkEndianess() {
    if (globalHeader.magic_number == 0xa1b2c3d4) {
        isBigEndian = true;
    }
    else if (globalHeader.magic_number == 0xd4c3b2a1) {
        isBigEndian = false;
    }
    else {
        throw std::runtime_error("Unsupported file format");
    }
}

uint32_t PcapParser::convertEndian32(uint32_t val) {
    return isBigEndian ? val : swap_endian32(val);
}

uint16_t PcapParser::convertEndian16(uint16_t val) {
    return isBigEndian ? val : swap_endian16(val);
}


#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <functional>
#include "PcapScheme.h"

class PcapParser {
public:
    using PcapFilterFunc = std::function<bool(const IPv4Header* ipHeader, const UDPHeader* udpHeader)>;
    using PayloadParserFunc = std::function<void(const char*, size_t)>;

    PcapParser(const std::string& filename);
    void parse();
    void setPcapFilter(PcapFilterFunc filter);
    void setPayloadParser(PayloadParserFunc parser);

private:
    std::ifstream file;
    PcapGlobalHeader globalHeader;
    PcapFilterFunc pcapFilter;
    PayloadParserFunc payloadParser;
    bool isBigEndian;

    uint32_t convertEndian32(uint32_t val);
    uint16_t convertEndian16(uint16_t val);
    void checkEndianess();
    void parseGlobalHeader();
    void parseEthernetHeader(const char* packet);
    void parseIPv4Header(const char* packet);
    void parsePacket();
    void processPayload(const char* packet, size_t packetLength);
    void doPayloadParsing(const char* packet, size_t packetLength);
    bool doPcapFilter(const IPv4Header* ipHeader, const UDPHeader* udpHeader);
};


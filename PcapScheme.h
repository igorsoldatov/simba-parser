#pragma once

struct UDPHeader {
    uint16_t srcPort;
    uint16_t destPort;
    uint16_t length;
    uint16_t checksum;
};

struct TCPHeader {
    uint16_t srcPort;         // Source Port
    uint16_t destPort;        // Destination Port
    uint32_t seqNumber;       // Sequence Number
    uint32_t ackNumber;       // Acknowledgment Number (if ACK set)
    uint8_t  dataOffset;      // Data offset (4 bits) + Reserved (3 bits) + NS flag (1 bit)
    uint8_t  flags;           // CWR, ECE, URG, ACK, PSH, RST, SYN, FIN (1 bit each)
    uint16_t window;          // Window size
    uint16_t checksum;        // Checksum
    uint16_t urgentPointer;   // Urgent pointer (if URG set)
    // Optional TCP header options follow...
};

struct EthernetHeader {
    uint8_t destMac[6];
    uint8_t srcMac[6];
    uint16_t etherType;
};

struct IPv4Header {
    uint8_t versionAndHeaderLength;
    uint8_t tos;
    uint16_t totalLength;
    uint16_t identification;
    uint16_t flagsAndFragmentOffset;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t srcAddr;
    uint32_t destAddr;
    // Options and padding...
};


struct PcapGlobalHeader {
    uint32_t magic_number;   // Magic number, ������������ ��� ����������� ������� ����� � ������� ������
    uint16_t version_major;  // �������� ����� ������
    uint16_t version_minor;  // �������������� ����� ������
    int32_t  thiszone;       // ��������� ��������� ���� � ��������
    uint32_t sigfigs;        // �������� ��������� �����
    uint32_t snaplen;        // ������������ ����� ����������� �������
    uint32_t network;        // ��� �������� ���������
};


struct PcapPacketHeader {
    uint32_t ts_sec;         // ��������� ����� (�������)
    uint32_t ts_usec;        // ��������� ����� (������������)
    uint32_t incl_len;       // ����� ������, ����������� � �����
    uint32_t orig_len;       // �������� ����� ������
};
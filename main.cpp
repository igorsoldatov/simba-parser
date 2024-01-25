#include "PcapParser.h"
#include "SimbaDecoder.h"

int main(int argc, char* argv[])
{
    std::string pcapDumpFile;
    std::string outputFile;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-p" || arg == "--pcap_dump_file") && i + 1 < argc) {
            pcapDumpFile = argv[++i];
        }
        else if ((arg == "-o" || arg == "--out") && i + 1 < argc) {
            outputFile = argv[++i];
        }
    }

    if (pcapDumpFile.empty() || outputFile.empty()) {
        std::cerr << "Usage: " << std::endl << " -p [pcap file] " << std::endl << " -o [output file]" << std::endl;
        return 1;
    }

    std::cout << "Start processing file: " << pcapDumpFile << std::endl;
    SimbaDecoder decoder(outputFile);
    decoder.setSbeFilter(
        [](const SBEHeader* sbeHeader) {
            return sbeHeader->templateID == 15 || sbeHeader->templateID == 16 || sbeHeader->templateID == 17;
        }
    );

	PcapParser parser(pcapDumpFile);
    parser.setPcapFilter(
        [](const IPv4Header* ipHeader, const UDPHeader* udpHeader) {
            return true;
        }
    );
    parser.setPayloadParser(
        [&decoder](const char* payload, size_t payloadLength) {
            decoder.DecodePackage(payload, payloadLength);
        }
    );
    parser.parse();

	return 0;
}

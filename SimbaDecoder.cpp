#include <iostream>
#include <bit>
#include "SimbaDecoder.h"
#include "json.h"
#include "base64encoder.h"

SimbaDecoder::SimbaDecoder(const std::string& outputFilePath) {
    outputFile.open(outputFilePath, std::ios::out);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open output file.");
    }
    outputFile << "[";
}

SimbaDecoder::~SimbaDecoder() {
    if (outputFile.is_open()) {
        outputFile << "]";
        outputFile.close();
    }
}

void SimbaDecoder::setSbeFilter(SbeFilterFunc filter) {
    sbeFilter = filter;
}

bool SimbaDecoder::doSbeFilter(const SBEHeader* sbeHeader) {
    if (!sbeFilter) return true;
    return sbeFilter(sbeHeader);
}

void SimbaDecoder::addJson(const std::string& json) {
    if (!outputFile.is_open()) return;
    outputFile << json << std::endl;
}

std::string SimbaDecoder::DecodePackageToJson(const char* payload, size_t payloadLength) {
    std::stringstream json;

    auto marketHeader = reinterpret_cast<const MarketDataPacketHeader*>(payload);
    int offset = MarketDataPacketHeader::size;
    json << toJson(marketHeader) << ",";

    if (marketHeader->msgFlags & MsgFlags::IncrementalPacketFlag) {
        auto incrHeader = reinterpret_cast<const IncrementalPacketHeader*>(payload + offset);
        offset += IncrementalPacketHeader::size;
        json << toJson(incrHeader) << ",";
    }

    while (payloadLength - offset >= SBEHeader::size) {
        auto sbeHeader = reinterpret_cast<const SBEHeader*>(payload + offset);
        offset += SBEHeader::size;

        if (!doSbeFilter(sbeHeader)) break;

        json << toJson(sbeHeader) << ", ";

        if (sbeHeader->templateID == 15) { // OrderUpdate
            auto orderUpd = reinterpret_cast<const OrderUpdate*>(payload + offset);
            offset += OrderUpdate::size;
            json << toJson(orderUpd) << ", ";
        }
        else if (sbeHeader->templateID == 16) { // OrderExecution
            auto orderExe = reinterpret_cast<const OrderExecution*>(payload + offset);
            offset += OrderExecution::size;
            json << toJson(orderExe) << ", ";
        }
        else if (sbeHeader->templateID == 17) { // OrderBookSnapshot
            auto orderBookSnapshot = reinterpret_cast<const OrderBookSnapshot*>(payload + offset);
            offset += OrderBookSnapshot::size;
            auto groupSize = reinterpret_cast<const GroupSize*>(payload + offset);
            offset += GroupSize::size;

            std::vector<const OrderBookSnapshotEntry*> entries;
            for (size_t i = 0; i < groupSize->numInGroup; ++i) {
                auto entry = reinterpret_cast<const OrderBookSnapshotEntry*>(payload + offset);
                offset += OrderBookSnapshotEntry::size;
                entries.push_back(entry);
            }

            json << toJson(orderBookSnapshot, entries) << ", ";
        }
        else {
            // not implemented
            break;
        }
    }
        
    return json.str();
}

void SimbaDecoder::DecodePackage(const char* payload, size_t payloadLength) {
    addJson(DecodePackageToJson(payload, payloadLength));
}
#pragma once
#include <fstream>
#include <vector>
#include <functional>
#include <cstdint>
#include "SimbaScheme.h"

class SimbaDecoder {
public:
    using SbeFilterFunc = std::function<bool(const SBEHeader* sbeHeader)>;

    SimbaDecoder(const std::string& outputFilePath);
    ~SimbaDecoder();
    std::string DecodePackageToJson(const char* payload, size_t payloadLength);
    void DecodePackage(const char* payload, size_t payloadLength);
    void setSbeFilter(SbeFilterFunc filter);

private:
    SbeFilterFunc sbeFilter;
    std::ofstream outputFile;

    bool doSbeFilter(const SBEHeader* sbeHeader);
    void addJson(const std::string& json);
};
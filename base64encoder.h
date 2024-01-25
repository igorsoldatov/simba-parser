#pragma once
#include <string>
#include <vector>

std::string base64Encode(const char* buf, size_t size);

std::string base64Encode(const std::vector<char>& buf);

std::vector<char> base64Decode(const std::string& encoded_string);

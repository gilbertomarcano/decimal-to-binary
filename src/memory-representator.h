#pragma once
// Class that show how binary numbers of different types are represented in memory
class MemoryRepresentator
{
private:
    static const std::string get_bits(const std::string& bin);
    static const std::string get_integer_part(const std::string& bin);
    static const std::string memory_structure(std::string& bin);

public:
    static const std::string to_memory(const int& number);
    static const std::string to_memory(const float& number);

};

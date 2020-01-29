#pragma once
// Class that show how binary numbers of different types are represented in memory
class MemoryRepresentator
{
private:
    static void set_byte_size(std::string& bin, const unsigned int bytes);
    static void change_endianness(std::string& bin);
    static const std::string separate_bytes(const std::string& bin);
    static const std::string get_bits(const std::string& bin);
    static const std::string get_integer_part(const std::string& bin);
    static const std::string memory_structure(std::string& bin);

public:
    static const std::string to_memory(const int& number);
    static const std::string to_memory(const float& number);
    static const std::string to_memory(const long& number);
    static const std::string to_memory(const long long& number);

};

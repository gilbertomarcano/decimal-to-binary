#pragma once
// Class that show how binary numbers of different types are represented in memory
class MemoryRepresentator
{
private:
    static void change_endianness(std::string& binary_string);
    static void separate_bytes(std::string& binary_string);
    //static const std::string memory_structure(std::string& binary_string);

public:
    static const std::string to_memory(bin& binary);

    static const std::string to_memory(const int number);
    static const std::string to_memory(const unsigned int number);

    static const std::string to_memory(const long number);
    static const std::string to_memory(const unsigned long number);

    static const std::string to_memory(const long long number);
    static const std::string to_memory(const unsigned long long number);

    static const std::string to_memory(const float number);



};

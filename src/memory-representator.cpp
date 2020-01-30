#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"


/*
********************************
*
*   Private member functions
*
********************************
*/

/**
* Change the order of the bytes within a binary representation of a number
* @param bin the binary string to be reordered
*/
void MemoryRepresentator::change_endianness(std::string& binary_string)
{
    std::string byte("");
    std::string new_bin("");

    for (const char& bit : binary_string)
    {
        byte += bit;
        if (byte.size() == 8)
        {
            new_bin = byte + new_bin;
            byte = "";
            continue;
        }
    }

    binary_string = new_bin;
}

void MemoryRepresentator::separate_bytes(std::string& binary_string)
{
    std::string separated_bytes("");
    for (int i = 0, size = binary_string.size(); i < size; i++)
    {
        separated_bytes += binary_string[i];
        if ((i + 1) % 8 == 0 && i != 0)
        {
            separated_bytes += " ";
        }
    }

    binary_string = separated_bytes;
}

// get how a binary number is represented in memory
//const std::string MemoryRepresentator::memory_structure(std::string& binary_string)
//{
//    change_endianness();
//    return separate_bytes(binary);
//}

/*
********************************
*
*   Public member functions
*
********************************
*/

const std::string MemoryRepresentator::to_memory(bin& binary)
{
    std::string binary_string = binary.get_binary_string();
    change_endianness(binary_string);
    separate_bytes(binary_string);
    return binary_string;
}

//// Get the memory representation of a int data type
//const std::string MemoryRepresentator::to_memory(const int number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}
//
//// Get the memory representation of an unsigned int data type
//const std::string MemoryRepresentator::to_memory(const unsigned int number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}
//
//// Get the memory representation of a long data type
//const std::string MemoryRepresentator::to_memory(const long number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}
//
//// Get the memory representation of an unsigned long data type
//const std::string MemoryRepresentator::to_memory(const unsigned long number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}
//
//// Get the memory representation of a long long data type
//const std::string MemoryRepresentator::to_memory(const long long number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}
//
//// Get the memory representation of an unsigned long long data type
//const std::string MemoryRepresentator::to_memory(const unsigned long long number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    return memory_structure(binary);
//}

//// Get the memory representation of a float data type
//const std::string MemoryRepresentator::to_memory(const float number)
//{
//    bin binary = BinaryConversor::to_bin(number);
//    binary.format_ieee754();
//    return memory_structure(binary);
//}

//// Get the memory representation of a long data type
//const std::string MemoryRepresentator::to_memory(const long& number)
//{
//    // Get the binary form of the integer
//    std::string bin = BinaryConversor::to_bin(number);
//    set_byte_size(bin, sizeof(long));
//
//    // Return the in-memory representation
//    return memory_structure(bin);
//}
//
//// Get the memory representation of a int data type
//const std::string MemoryRepresentator::to_memory(const long long& number)
//{
//    // Get the binary form of the integer
//    std::string bin = BinaryConversor::to_bin(number);
//    set_byte_size(bin, sizeof(long long));
//
//    // Return the in-memory representation
//    return memory_structure(bin);
//}
//
//
//// Get the memory representation of a float data type
//const std::string MemoryRepresentator::to_memory(const float& number)
//{
//    // Get the binary form of the float
//    std::string bin = BinaryConversor::to_bin(abs(number));
//
//    // Get the sign bit
//    std::string sign_bit = number < 0 ? "1" : "0";
//
//    // Get the exponent and fix the size to 1 byte if needed
//    std::string exponent = BinaryConversor::to_bin((int)(127 + get_binary_string(bin).size() - 1));
//    set_byte_size(exponent, 1);
//
//    // Get the bits of the binary number in order to avoid the float point
//    std::string bits = get_bits(bin);
//
//    // Get the mantissa from the bits of the binary number excepting the first one
//    std::string mantissa = std::string(bits.begin() + 1, bits.end());
//
//    // Set the size of the mantissa always to 23 bits
//    while (mantissa.size() < 23)
//    {
//        mantissa += "0";
//    }
//
//    // Get the binary form with the IEEE-754 standard form for floating point numbers
//    bin = std::string(sign_bit + exponent + mantissa);
//
//    // Return the in-memory representation
//    return memory_structure(bin);
//}

#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"

// 
/**
* Set the size of a binary string to a certain quantity of bytes
* @param bin the binary string
* @param bytes the size in bytes to be assigned to the binary string
*/
void MemoryRepresentator::set_byte_size(std::string& bin, const unsigned int bytes)
{
    while (bin.size() < bytes * 8)
    {
        bin = "0" + bin;
    }
}

/**
* Change the order of the bytes within a binary representation of a number
* @param bin the binary string to be reordered
*/
void MemoryRepresentator::change_endianness(std::string& bin)
{
    std::string byte("");
    std::string new_bin("");

    int size = bin.size();

    for (const char& bit : bin)
    {
        byte += bit;
        if (byte.size() == 8)
        {
            new_bin = byte + new_bin;
            byte = "";
            continue;
        }
    }

    bin = new_bin;
}

/**
* Get only the bits of a decimal binary number
* @return the bits concatenated in a string
*/
const std::string MemoryRepresentator::get_bits(const std::string& bin)
{
    std::string bits("");

    // Iterate over the binary number
    for (const char& bit : bin)
    {
        if (bit != '.')
        {
            bits += bit;
        }
    }

    return bits;
}

const std::string MemoryRepresentator::separate_bytes(const std::string& bin)
{
    std::string separated_bytes("");
    for (int i = 0, size = bin.size(); i < size; i++)
    {
        separated_bytes += bin[i];
        if ((i + 1) % 8 == 0 && i != 0)
        {
            separated_bytes += " ";
        }
    }
    return separated_bytes;
}

// Get the integer part of a binary number
const std::string MemoryRepresentator::get_integer_part(const std::string& bin)
{
    std::string bits("");

    for (const char& bit : bin)
    {
        if (bit != '.')
        {
            bits += bit;
            continue;
        }
        break;
    }

    return bits;
}

// Get how a binary number is represented in memory
const std::string MemoryRepresentator::memory_structure(std::string& bin)
{
    change_endianness(bin);
    return separate_bytes(bin);
}


// Get the memory representation of a int data type
const std::string MemoryRepresentator::to_memory(const int& number)
{
    // Get the binary form of the integer
    std::string bin = BinaryConversor::to_bin(number);
    set_byte_size(bin, sizeof(int));

    // Return the in-memory representation
    return memory_structure(bin);
}

// Get the memory representation of a long data type
const std::string MemoryRepresentator::to_memory(const long& number)
{
    // Get the binary form of the integer
    std::string bin = BinaryConversor::to_bin(number);
    set_byte_size(bin, sizeof(long));

    // Return the in-memory representation
    return memory_structure(bin);
}

// Get the memory representation of a int data type
const std::string MemoryRepresentator::to_memory(const long long& number)
{
    // Get the binary form of the integer
    std::string bin = BinaryConversor::to_bin(number);
    set_byte_size(bin, sizeof(long long));

    // Return the in-memory representation
    return memory_structure(bin);
}


// Get the memory representation of a float data type
const std::string MemoryRepresentator::to_memory(const float& number)
{
    // Get the binary form of the float
    std::string bin = BinaryConversor::to_bin(abs(number));

    // Get the sign bit
    std::string sign_bit = number < 0 ? "1" : "0";

    // Get the exponent and fix the size to 1 byte if needed
    std::string exponent = BinaryConversor::to_bin((int)(127 + get_integer_part(bin).size() - 1));
    set_byte_size(exponent, 1);

    // Get the bits of the binary number in order to avoid the float point
    std::string bits = get_bits(bin);

    // Get the mantissa from the bits of the binary number excepting the first one
    std::string mantissa = std::string(bits.begin() + 1, bits.end());

    // Set the size of the mantissa always to 23 bits
    while (mantissa.size() < 23)
    {
        mantissa += "0";
    }

    // Get the binary form with the IEEE-754 standard form for floating point numbers
    bin = std::string(sign_bit + exponent + mantissa);

    // Return the in-memory representation
    return memory_structure(bin);
}

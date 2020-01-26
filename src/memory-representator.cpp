#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"

// Get only the bits of a decimal binary number
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
    // Fill the size of the binary number until it's 32 bits long
    while (bin.size() < 32)
    {
        bin = "0" + bin;
    }

    // String that represents the memory form of the binary number
    std::string in_memory("");

    // A string that represents a byte
    std::string byte("");

    // Iterate over the binary number
    for (int i = 0; i < 33; i++)
    {
        // If not mod 8
        if (byte.size() == 7)
        {
            byte += bin[i];
            // Append the byte with the correct endianess and a white space
            in_memory = byte + " " + in_memory;
            // Clear the byte string
            byte = "";
        }
        else
        {
            // Append the bit to the byte string and continue with the loop
            byte += bin[i];
        }
    }

    return in_memory;
}

// Get the memory representation of a int data type
const std::string MemoryRepresentator::to_memory(const int& number)
{
    // Get the binary form of the integer
    std::string bin = BinaryConversor::to_bin(number);

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

    // Get the exponent
    std::string exponent = BinaryConversor::to_bin((int)(127 + get_integer_part(bin).size() - 1));

    // Set the size of the exponent always to 8 bits
    if (exponent.size() < 8)
    {
        exponent = "0" + exponent;
    }

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

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
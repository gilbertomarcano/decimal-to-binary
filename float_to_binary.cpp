#include <iostream>
#include "float_to_binary.h"

// Convert an int into its binary representation
std::string FloatToBinary::int_to_bin(int number)
{
    std::string bin("");

    while (number != 0)
    {
        // Get the mod
        int mod = number % 2;

        // Append a 1 or a 0 at the front of the binary string
        bin = mod ? "1" + bin : "0" + bin;

        // Update the number for the next iteration
        number /= 2;
    }

    return bin;
}

// Convert a decimal part into its binary representation
std::string FloatToBinary::dec_to_bin(float number)
{
    std::string bin("");

    while (number)
    {
        number *= 2;

        // Append a 1 or a 0 at the end of the binary string
        if (number >= 1)
        {
            bin += "1";
            // Update the number for the next iteration
            number--;
        }
        else
        {
            bin += "0";
        }
    }

    return bin;
}
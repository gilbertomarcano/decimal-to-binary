#include <iostream>

#include "binary-conversor.h"

const std::string& BinaryConversor::positive_int_to_bin(int number, std::string& bin)
{
    while (true)
    {
        // Get the mod
        int mod = number % 2;

        // Append a 0 or a 1 at the front of the binary string
        bin = mod ? "1" + bin : "0" + bin;

        // Update the number for the next iteration
        number /= 2;

        // Check for break the loop
        if (number == 0)
        {
            break;
        }
    }

    return bin;
}

const std::string& BinaryConversor::negative_int_to_bin(int number, std::string& bin)
{
    // Get the number in binary
    bin = positive_int_to_bin(number, bin);
    
    // Fill with 0 until size is 32 bits
    while (bin.size() < 32)
    {
        bin = "0" + bin;
    }

    // Invert the string
    invert_bin(bin);
    
    // Add 1 to the string
    add_one(bin);

    return bin;
}

const void BinaryConversor::invert_bin(std::string& bin)
{
    for (char& bit : bin)
    {
        bit = bit == '0' ? '1' : '0';
    }
}

const void BinaryConversor::add_one(std::string& bin)
{
    for (int i = bin.size() - 1; i > -1; i--)
    {
        if (bin[i] == '0')
        {
            bin[i] = '1';
            break;
        }
        bin[i] = '0';
    }
}

const int BinaryConversor::bin_to_int(const std::string& bin)
{
    int number = 0;

    for (int i = 0, size = bin.size(); i < size; i++)
    {
        number += bin[i] == '1' ? (int)pow(2, size - i - 1) : 0;
    }

    return number;
}

// Convert an int into its binary representation
const std::string BinaryConversor::to_bin(const int& number)
{
    std::string bin("");
    bin = number < 0 ? negative_int_to_bin(number, bin) : positive_int_to_bin(number, bin);
    return bin;
}






const std::string BinaryConversor::to_bin(const float& number)
{
    std::string integer_part = to_bin((int)number);
    std::string decimal_part("");
    decimal_part = decimal_to_bin(abs(number - (int)number), decimal_part);

    std::string bin(integer_part + "." + decimal_part);
    return bin;
}

const std::string& BinaryConversor::decimal_to_bin(float decimal, std::string& bin)
{
    while (true)
    {
        decimal *= 2;

        // Append a 1 or a 0 at the end of the binary string
        if (decimal >= 1)
        {
            bin += "1";
            // Update the number for the next iteration
            decimal--;
        }
        else
        {
            bin += "0";
        }
        
        // Check for breaking the loop
        if (!decimal)
        {
            break;
        }
    }
    return bin;
}






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
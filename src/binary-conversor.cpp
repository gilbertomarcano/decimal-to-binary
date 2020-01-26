#include <iostream>

#include "binary-conversor.h"

// Convert a positve integer to its binary representation
void BinaryConversor::positive_int_to_bin(int number, std::string& bin)
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
}

// Convert a negative integer in its binary representation
void BinaryConversor::negative_int_to_bin(int number, std::string& bin)
{
    // Get the number in binary
    positive_int_to_bin(number, bin);
    
    // Fill with 0 until size is 32 bits long
    while (bin.size() < 32)
    {
        bin = "0" + bin;
    }

    // Invert the binary number
    invert_bin(bin);
    
    // Add 1 to the binary number
    add_one(bin);
}

// Convert the one's into zero's and the zero's into one's in a binary string
void BinaryConversor::invert_bin(std::string& bin)
{
    for (char& bit : bin)
    {
        bit = bit == '0' ? '1' : '0';
    }
}

// Add a one in a binary string due binary sum
void BinaryConversor::add_one(std::string& bin)
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

// Convert the decimal part of a float into its binary representation
void BinaryConversor::decimal_to_bin(float decimal, std::string& bin)
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
}

// Get the binary representation of a signed int type number
const std::string BinaryConversor::to_bin(const int& number)
{
    std::string bin("");
    number < 0 ? negative_int_to_bin(number, bin) : positive_int_to_bin(number, bin);
    return bin;
}

// Get the binary representation of a signed float type number
const std::string BinaryConversor::to_bin(const float& number)
{
    // Get the integer part in binary
    std::string integer_part = to_bin((int)number);
    // Get the decimal part in binary
    std::string decimal_part("");
    decimal_to_bin(abs(number - (int)number), decimal_part);

    // Concatenate the string with the floating point
    std::string bin(integer_part + "." + decimal_part);
    return bin;
}


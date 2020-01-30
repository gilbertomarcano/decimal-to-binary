#include <iostream>

#include "binary-conversor.h"

/*
********************************
*
*   Private member functions
*
********************************
*/

std::string BinaryConversor::uint_to_bin(unsigned long long number)
{
    std::string binary_string("");

    while (true)
    {
        // Prepend a 0 or a 1 at the beggining of the binary string
        binary_string = number % 2 ? "1" + binary_string : "0" + binary_string;

        // Update the number for the next iteration
        number /= 2;

        // Check for break the loop
        if (number == 0)
        {
            break;
        }
    }

    return binary_string;
}

// Convert a positve 8 bits integer to its binary representation
bin BinaryConversor::uint8_to_bin(unsigned char number)
{
    return bin(uint_to_bin(number), sizeof(char));
}

// Convert a positve 16 bits integer to its binary representation
bin BinaryConversor::uint16_to_bin(unsigned short number)
{
    return bin(uint_to_bin(number), sizeof(short));
}

// Convert a positve 32 bits integer to its binary representation
bin BinaryConversor::uint32_to_bin(unsigned int number)
{
    return bin(uint_to_bin(number), sizeof(int));
}

// Convert a positve 64 bits integer to its binary representation
bin BinaryConversor::uint64_to_bin(unsigned long long number)
{
    return bin(uint_to_bin(number), sizeof(long long));
}

// Convert a negative integer in its binary representation
bin BinaryConversor::int16_to_bin(short number)
{
    // Get the number in binary
    bin binary = uint16_to_bin(abs(number));

    if (number >= 0)
    {
        return binary;
    }

    // Invert the binary number
    binary.inverse();

    // Add 1 to the binary number
    binary += bin("1", 1);

    return binary;
}

// Convert a negative integer in its binary representation
bin BinaryConversor::int32_to_bin(int number)
{
    // Get the number in binary
    bin binary = uint32_to_bin(abs(number));

    if (number >= 0)
    {
        return binary;
    }

    // Invert the binary number
    binary.inverse();

    // Add 1 to the binary number
    binary += bin("1", 1);
    
    return binary;
}

// Convert a negative integer in its binary representation
bin BinaryConversor::int64_to_bin(long long number)
{
    // Get the number in binary
    bin binary = uint64_to_bin(abs(number));

    if (number >= 0)
    {
        return binary;
    }

    // Invert the binary number
    binary.inverse();
    
    // Add 1 to the binary number
    std::string one("1");
    binary += bin("1", 1);

    return binary;
}

// Convert the decimal part of a float into its binary representation
std::string BinaryConversor::dec32_to_bin(float decimal)
{
    std::string fractional_binary("");
    while (true)
    {
        decimal *= 2;

        // Append a 1 or a 0 at the end of the binary string
        if (decimal >= 1)
        {
            fractional_binary.append("1");
            // Update the number for the next iteration
            decimal--;
        }
        else
        {
            fractional_binary.append("0");
        }
        
        // Check for breaking the loop
        if (!decimal)
        {
            break;
        }
    }

    return fractional_binary;
}

// Convert the decimal part of a float into its binary representation
std::string BinaryConversor::dec64_to_bin(double decimal)
{
    std::string fractional_binary("");
    while (true)
    {
        decimal *= 2;

        // Append a 1 or a 0 at the end of the binary string
        if (decimal >= 1)
        {
            fractional_binary.append("1");
            // Update the number for the next iteration
            decimal--;
        }
        else
        {
            fractional_binary.append("0");
        }

        // Check for breaking the loop
        if (!decimal)
        {
            break;
        }
    }

    return fractional_binary;
}

void set_mantissa_size(std::string& mantissa, unsigned short size)
{
    if (mantissa.size() < size)
    {
        while (mantissa.size() < size)
        {
            mantissa = mantissa + "0";
        }
    }
    else
    {
        int diff = mantissa.size() - size;
        mantissa = std::string(mantissa.begin(), mantissa.end() - diff);
    }
}

void set_exponent_size(std::string& exponent, unsigned short size)
{
    while (exponent.size() < size)
    {
        exponent = "0" + exponent;
    }
}

bin BinaryConversor::float64_to_bin(double number)
{
    std::string integer_part = uint_to_bin((int)abs(number));
    std::string fractional_part = dec64_to_bin(abs(number - (int)number));

    // Get the sign bit
    std::string sign_bit = number < 0 ? "1" : "0";

    // Get the exponent and fix the size to 11 bits if needed
    std::string exponent = uint_to_bin(1023 + integer_part.size() - 1);
    set_exponent_size(exponent, 11);

    // Get the mantissa from the bits of the binary number excepting the first one
    std::string binary_string(integer_part + fractional_part);
    std::string mantissa(binary_string.begin() + 1, binary_string.end());

    // Set the size of the mantissa always to 52 bits
    set_mantissa_size(mantissa, 52);

    // Get the binary representation of the IEEE-754 standard form for 64bits floating point numbers
    return bin(sign_bit + exponent + mantissa, sizeof(double));
}

bin BinaryConversor::float32_to_bin(float number)
{
    std::string integer_part = uint_to_bin((int)abs(number));
    std::string fractional_part = dec32_to_bin(abs(number - (int)number));

    // Get the sign bit
    std::string sign_bit = number < 0 ? "1" : "0";

    // Get the exponent and fix the size to 8 bits if needed
    std::string exponent = uint_to_bin(127 + integer_part.size() - 1);
    set_exponent_size(exponent, 8);


    // Get the mantissa from the bits of the binary number excepting the first one
    std::string binary_string(integer_part + fractional_part);
    std::string mantissa(binary_string.begin() + 1, binary_string.end());

    // Set the size of the mantissa always to 23 bits
    set_mantissa_size(mantissa, 23);


    // Get the binary representation of the IEEE-754 standard form for 32bits floating point numbers
    return bin(sign_bit + exponent + mantissa, sizeof(float));
}

/*
********************************
*
*   Public member functions
*
********************************
*/

const bin BinaryConversor::to_bin(const char number)
{
    return uint8_to_bin(number);
}

// Get the binary representation of a signed short type number
const bin BinaryConversor::to_bin(const short number)
{
    return int16_to_bin(number);
}

// Get the binary representation of a signed int type number
const bin BinaryConversor::to_bin(const unsigned short number)
{
    return uint16_to_bin(number);
}

// Get the binary representation of a signed int type number
const bin BinaryConversor::to_bin(const int number)
{
    return int32_to_bin(number);
}

// Get the binary representation of a unsigned int type number
const bin BinaryConversor::to_bin(const unsigned int number)
{
    return uint32_to_bin(number);
}

// Get the binary representation of a signed long type number
const bin BinaryConversor::to_bin(const long number)
{
    return int32_to_bin((int)number);
}

// Get the binary representation of a unsigned long type number
const bin BinaryConversor::to_bin(const unsigned long number)
{
    return uint32_to_bin((unsigned int)number);
}

// Get the binary representation of a signed long long type number
const bin BinaryConversor::to_bin(const long long number)
{
    return int64_to_bin(number);
}

// Get the binary representation of a unsigned long long type number
const bin BinaryConversor::to_bin(const unsigned long long number)
{
    return uint64_to_bin(number);
}

// Get the binary representation of a 32 bits float type number
const bin BinaryConversor::to_bin(const float number)
{
    return float32_to_bin(number);
}

// Get the binary representation of a 64 bits float type number
const bin BinaryConversor::to_bin(const double number)
{
    return float64_to_bin(number);
}



#pragma once
// Class that converts a decimal into its binary format
class BinaryConversor
{
private:
    static const std::string& positive_int_to_bin(int number, std::string& bin);
    static const std::string& negative_int_to_bin(int number, std::string& bin);
    static const std::string& decimal_to_bin(float decimal, std::string& bin);
    static const void invert_bin(std::string& bin);
    static const void add_one(std::string& bin);
public:
    
    static const std::string to_bin(const int& number);
    static const std::string to_bin(const float& number);
    

    static const int bin_to_int(const std::string& bin);

};


class FloatToBinary
{
public:

    // Convert an int into its binary representation
    static std::string int_to_bin(int number);

    // Convert a decimal part into its binary representation
    static std::string dec_to_bin(float number);

    // Get the digits of the binary number without point
    static std::string get_digits(std::string bin)
    {
        std::string digits("");
        for (unsigned int i = 0; i < bin.size(); i++)
        {
            if (bin[i] != '.')
            {
                digits += bin[i];
            }
        }

        return digits;
    }

public:

    // Member functions

    // Convert a decimal number into its binary representation
    static std::string to_bin(float number)
    {
        // Get the absolute value of the number
        float abs = number < 0 ? number * -1 : number;

        // Get the integer and the decimal part in binary of the number
        std::string integer_part = int_to_bin((int)abs);
        std::string decimal_part = dec_to_bin(abs - (int)abs);

        // Get the binary number
        std::string bin(integer_part);

        if (decimal_part != "")
        {
            bin.append("." + decimal_part);
        }

        return bin;
    }

    // Convert a decimal number into its standard IEEE-754 binary representation
    static std::string to_ieee754(float number)
    {
        // Get the sign bit
        std::string sign_bit = number < 0 ? "1" : "0";

        // Get the integer part of the binary number
        std::string integer_part = int_to_bin((int)number);
        // Get the exponent
        std::string exponent = int_to_bin(127 + integer_part.size() - 1);
        // Adjust the size of the exponent to 8 bits
        if (exponent.size() < 8)
        {
            exponent = "0" + exponent;
        }

        // Get the digits of the binary number
        std::string digits = get_digits(to_bin(number));
        // Get the mantissa from the digits of the binary number excluding the first one
        std::string mantissa(digits.begin() + 1, digits.end());
        // Adjust the size of the mantissa to 23 bits
        while (mantissa.size() < 23)
        {
            mantissa += "0";
        }

        // Get the binary IEEE-754 format representation
        std::string bin_ieee754(sign_bit + exponent + mantissa);

        return bin_ieee754;
    }

    /* Return a byte format of a binary number
        param bin should be in IEEE-754 binary representation
    */
    static std::string byte_format(std::string bin)
    {
        std::string format("");
        for (int i = 0; i < 32; i++)
        {
            if (i % 4 == 0 && i != 0)
            {
                format += " ";
            }
            format += bin[i];
        }

        return format;
    }

    /* Return a IEEE-754 format of a binary number
        param bin should be in IEEE-754 binary representation
    */
    static std::string ieee754_format(std::string bin)
    {
        std::string format("");
        for (int i = 0; i < 32; i++)
        {
            if (i == 1 || i == 9)
            {
                format += " ";
            }
            format += bin[i];
        }

        return format;
    }

};

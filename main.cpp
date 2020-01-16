/**First realease of the script that converts a float number into its binary representation
 * 
 * Released on 01/16/2020
 * */

#include <iostream>

#define print(msg) std::cout << msg << std::endl
#define str std::string

// Class that converts a decimal into its binary format
class FloatToBinary
{
private:

    // Convert an int into its binary representation
    static str int_to_bin(int number)
    {
        str bin("");

        while (number != 0)
        {
            // Get the mod
            int mod = number % 2;

            // Append a 1 or a 0 at the front of the binary string
            if (mod)
            {
                bin = "1" + bin;
            }
            else
            {
                bin = "0" + bin;
            }

            // Update the number for the next iteration
            number /= 2;
        }

        return bin;
    }

    // Convert a decimal part into its binary representation
    static str dec_to_bin(float number)
    {
        str bin("");

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

    // Get the digits of the binary number without point
    static str get_digits(str bin)
    {
        str digits("");
        for (int i = 0; i < bin.size(); i++)
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
    static str to_bin(float number)
    {
        // Get the absolute value of the number
        float abs = number < 0 ? number * -1 : number;
        
        // Get the integer and the decimal part in binary of the number
        str integer_part = int_to_bin((int)abs);
        str decimal_part = dec_to_bin(abs - (int)abs);

        // Get the binary number
        str bin = str(integer_part);

        if (decimal_part != "")
        {
            bin.append("." + decimal_part);
        }

        return bin;
    }

    // Convert a decimal number into its standard IEEE-754 binary representation
    static str to_ieee754(float number)
    {
        // Get the sign bit
        str sign_bit = number < 0 ? "1" : "0";

        // Get the integer part of the binary number
        str integer_part = int_to_bin((int)number);
        // Get the exponent
        str exponent = int_to_bin(127 + integer_part.size() - 1);
        // Adjust the size of the exponent to 8 bits
        if (exponent.size() < 8)
        {
            exponent = "0" + exponent;
        }

        // Get the digits of the binary number
        str digits = get_digits(to_bin(number));
        // Get the mantissa from the digits of the binary number excluding the first one
        str mantissa = str(digits.begin() + 1, digits.end());
        // Adjust the size of the mantissa to 23 bits
        while (mantissa.size() < 23)
        {
            mantissa += "0";
        }

        // Get the binary IEEE-754 format representation
        str bin_ieee754 = str(sign_bit + exponent + mantissa);

        return bin_ieee754;
    }

    /* Return a byte format of a binary number 
        param bin should be in IEEE-754 binary representation
    */
    static str byte_format(str bin)
    {
        str format("");
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
    static str ieee754_format(str bin)
    {
        str format("");
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

// Main class of the program
int main(void)
{
    // Prompt for number
    float number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    str bin = FloatToBinary::to_ieee754(number);
    print("Binary representation: " << bin);
    print("Byte format: " << FloatToBinary::byte_format(bin));
    print("IEEE-754 format:" << FloatToBinary::ieee754_format(bin));

    std::cin.get();
}
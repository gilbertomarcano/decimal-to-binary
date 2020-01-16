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
        str integer_part = int_to_bin((int)number);
        str decimal_part = dec_to_bin(number - (int)number);

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

};


// Main class of the program
int main(void)
{
    str b = FloatToBinary::to_ieee754(32.25);
    print(b);
    print(b.size());

    std::cin.get();
}
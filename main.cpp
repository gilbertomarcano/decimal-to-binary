#include <iostream>

#define print(msg) std::cout << msg << std::endl

#define str std::string


// Class that convert a float number into its different binary forms
class FloatToBin
{
private:

    // Delete a character in a binary number
    static str delete_char(str bin, char to_delete)
    {
        str new_bin("");
        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i] != to_delete)
            {
                new_bin += bin[i];
            }
        }

        return new_bin;
    }

    // Convert a int into its binary form
    static str int_to_bin(int number)
    {
        str bin("");

            while (true)
            {
                // Get the mod
                int mod = number % 2;

                // Append a 1 or a 0 at the front of the string
                if (mod)
                {
                    bin = "1" + bin;
                }
                else
                {
                    bin = "0" + bin;
                }

                // Update the number to the next iteration
                number /= 2;

                // Check for breaking the loop
                if (!number)
                {
                    break;
                }
            }
            
            return bin;
    }

    // Convert a decimal part into its binary form
    static str dec_to_bin(float number)
    {
        str bin("");

        while (true)
        {
            number *= 2;

            // Append a 1 or a 0 at the end of the string
            if (number >= 1)
            {
                bin += "1";
                // Update the number for the next iteration if needed
                number--;
            }
            else
            {
                bin += "0";
            }

            // Check for breaking the loop
            if (!number)
            {
                break;
            }
        }

        return bin;
    }


public:

    // Convert a float number into its binary form
    static str to_bin(float number)
    {
        // Get the integer and the decimal part of the number in binary
        str integer_part = int_to_bin((int)number);
        str decimal_part = dec_to_bin(number - (int)number);

        // Get and return the binary form
        str bin = str(integer_part);
        
        if (decimal_part != "0")
        {
            bin.append("." + decimal_part);
        }
        return bin;
    }

    // Convert a float number into its byte form
    static str to_byte(float number)
    {
        // Get the number in its bin form without the point
        str bin = to_ieee754(number);
        bin = delete_char(bin, ' ');

        // Adjust the size
        bin += "0";
        
        // Generate the number in byte form
        str byte("");

        for (int i = 0; i < 32; i++)
        {
            if (i % 4 == 0 && i != 0)
               {
                   byte += " "; 
               }
            
            byte += bin[i];
        }

        return byte;
    }

    // Convert a float number into its standard IEEE754 form
    static str to_ieee754(float number)
    {
        // Get the number in its bin form without the point
        str bin = to_bin(number);

        str integer_part("");
        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i] == '.')
            {
                break;
            }
            integer_part += bin[i];
        }

        bin = delete_char(bin, '.');

        // Get the sign level
        str sign_bit("");

        if (number < 0)
        {
            sign_bit = "1";
        }
        else
        {
            sign_bit = "0";
        }

        // Get the exponent in binary
        str exponent = to_bin(127 + integer_part.size() - 1);

        // Get the mantissa from the binary without the point excluding the first digit
        str mantissa = str(bin.begin() + 1, bin.end());

        // Adjust the size of the mantissa
        while (mantissa.size() < 23)
        {
            mantissa += "0";
        }

        // Get the IEEE 754 form
        str ieee754 = (sign_bit + " " + exponent + " " + mantissa);

        return ieee754;
    }
};


// Main function of the program
int main(void)
{
    float number;
    std::cout << "Enter a float number: ";
    std::cin >> number;
    print("binary:\t " << FloatToBin::to_bin(number));
    print("ieee754: " << FloatToBin::to_ieee754(number));
    print("byte:\t  " << FloatToBin::to_byte(number));
    
    std::cin.get();
}
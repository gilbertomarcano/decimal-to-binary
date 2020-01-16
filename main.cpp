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

public:

    // Member functions
    static str to_bin(float number)
    {
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
};


// Main class of the program
int main(void)
{
    print(FloatToBinary::to_bin(6.4));

    std::cin.get();
}
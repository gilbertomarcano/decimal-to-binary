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

public:

    // Member functions
    static str to_bin(float number)
    {
        str integer_part = int_to_bin((int)number);
        str decimal_part;

        return integer_part;
    }
};


// Main class of the program
int main(void)
{
    print(FloatToBinary::to_bin(5));

    std::cin.get();
}
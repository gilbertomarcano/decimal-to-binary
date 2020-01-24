/**First realease of the script that converts a float number into its binary representation
 *
 * Released on 01/16/2020
 * */

#include <iostream>
#include "float_to_binary.h"

#define print(msg) std::cout << msg << std::endl


// Main class of the program
int main(void)
{
    while (true)
    {
        // Prompt for number
        float number;
        std::cout << "Enter a number: ";
        std::cin >> number;

        std::string bin = FloatToBinary::to_ieee754(number);
        print("Binary representation: " << bin);
        print("Byte format: " << FloatToBinary::byte_format(bin));
        print("IEEE-754 format: " << FloatToBinary::ieee754_format(bin));

        // Prompt for exit
        char exit;
        std::cout << "Enter 0 exit, any other to repeat: ";
        std::cin >> exit;

        if (exit == '0') break;
    }
}
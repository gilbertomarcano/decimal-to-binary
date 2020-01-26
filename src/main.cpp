/**First realease of the script that converts a float number into its binary representation
 *
 * Released on 01/16/2020
 * Visual Studio project on 01/24/2020
 * Memory Representator included on 01/25/2020
 * */

#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"

#define print(msg) std::cout << msg << std::endl

// Main class of the program
int main(void)
{
    float f = 4.0f;
    print(MemoryRepresentator::to_memory(1.125f));
    print(MemoryRepresentator::to_memory(2.125f));
    print(MemoryRepresentator::to_memory(3.125f));
    print(MemoryRepresentator::to_memory(4.125f));
    print(MemoryRepresentator::to_memory(5.125f));
    print(MemoryRepresentator::to_memory(6.125f));


}
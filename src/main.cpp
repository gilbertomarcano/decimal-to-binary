/**First realease of the script that converts a float number into its binary representation
 *
 * Released on 01/16/2020
 * Visual Studio project on 01/24/2020
 * Memory Representator included on 01/25/2020
 * */

#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"


#include <typeinfo>

#define print(msg) std::cout << msg << std::endl

// Main class of the program
int main(void)
{
    int i = -18086;
    long j = -18086;

    float f = -1.0f;
    long long l = 3232424;
    print(MemoryRepresentator::to_memory(i));
    print(MemoryRepresentator::to_memory(l));
}
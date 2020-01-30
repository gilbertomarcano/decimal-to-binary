/**First realease of the script that converts a float number into its binary representation
 *
 * Released on 01/16/2020
 * Visual Studio project on 01/24/2020
 * Memory Representator included on 01/25/2020
 * */

#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"
#include "bin.h"

#define print(msg) std::cout << msg << std::endl

void homework();

// Main class of the program
int main(void)
{
    homework();
}

// Show the memory representation of the next values:
void homework()
{
    bin binary;

    // a. float f = 1.0;
    float f = 1.0;
    binary = BinaryConversor::to_bin(f);
    std::cout << "a. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // b. float g = -3125.3125
    float g = -3125.3125;
    binary = BinaryConversor::to_bin(g);
    std::cout << "b. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // c. int i = 27285297;
    int i = 27825297;
    binary = BinaryConversor::to_bin(i);
    std::cout << "c. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // d. int j = -27285297;
    int j = -27825297;
    binary = BinaryConversor::to_bin(j);
    std::cout << "d. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // e. long l = -18086;
    long l = -18086;
    binary = BinaryConversor::to_bin(l);
    std::cout << "e. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // f. float x = 27825297.0f;
    float x = 27825297.0f;
    binary = BinaryConversor::to_bin(x);
    std::cout << "f. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // g. char *p; *p = 'Z';
    char* p;
    char c;
    p = &c;
    *p = 'Z';
    binary = BinaryConversor::to_bin(*p);
    std::cout << "g. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // h. float f = 0x000FFFFF;
    float f1 = 0x000FFFFF;
    binary = BinaryConversor::to_bin(f1);
    std::cout << "h. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // i. short s  = -12040;
    short s = -12040;
    binary = BinaryConversor::to_bin(s);
    std::cout << "i. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // j. float x = -27825297.0f;
    float x1 = -27825297.0f;
    binary = BinaryConversor::to_bin(x1);
    std::cout << "j. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // k. int *p1; *p1 = 15678;
    int* p1;
    int i1;
    p1 = &i1;
    *p1 = 15678;
    binary = BinaryConversor::to_bin(*p1);
    std::cout << "k. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // l. float f = 0x000FFF9F. Show its base 10 formula
    float f2 = 0x000FFF9F;
    binary = BinaryConversor::to_bin(f2);
    std::cout << "l. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // m. short j = -19842;
    short s1 = -19842;
    binary = BinaryConversor::to_bin(s1);
    std::cout << "m. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // n. double x = -100036.875
    double dx = -100036.875;
    binary = BinaryConversor::to_bin(dx);
    std::cout << "n. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // o. char *p2; p2 = new char; *p = 'A';
    char* p2;
    p2 = new char;
    *p2 = 'A';
    binary = BinaryConversor::to_bin(*p2);
    std::cout << "o. " << MemoryRepresentator::to_memory(binary) << std::endl;

    // p. float f = 0x000FF0A1. Show its base 10 formula
    float f3 = 0x000FF0A1;
    binary = BinaryConversor::to_bin(f3);
    std::cout << "p. " << MemoryRepresentator::to_memory(binary) << std::endl;
}
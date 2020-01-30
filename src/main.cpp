/**First realease of the script that converts a float number into its binary representation
 *
 * First release on 01/16/2020
 * Visual Studio project on 01/24/2020
 * Memory Representator included on 01/25/2020
 * Bin class and second release on 01/30/2020
 * */

#include <iostream>

#include "binary-conversor.h"
#include "memory-representator.h"
#include "bin.h"

#define print(msg) std::cout << msg << std::endl

void homework();
void bar();

// Main class of the program
int main(void)
{
    homework();

    std::cin.get();
}

void bar()
{
    std::cout << "\n========================================================\n" << std::endl;
}

// Show the memory representation of the next values:
void homework()
{
    bin binary;

    // a. float f = 1.0;
    float f = 1.0f;
    binary = BinaryConversor::to_bin(f);
    std::cout << "a. float f = 1.0;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // b. float g = -3125.3125
    float g = -3125.3125;
    binary = BinaryConversor::to_bin(g);
    std::cout << "b. float g = -3125.3125;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();


    // c. int i = 27285297;
    int i = 27825297;
    binary = BinaryConversor::to_bin(i);
    std::cout << "c. int i = 27285297;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // d. int j = -27285297;
    int j = -27825297;
    binary = BinaryConversor::to_bin(j);
    std::cout << "d. int j = -27285297;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // e. long l = -18086;
    long l = -18086;
    binary = BinaryConversor::to_bin(l);
    std::cout << "e. long l = -18086;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // f. float x = 27825297.0f;
    float x = 27825297.0f;
    binary = BinaryConversor::to_bin(x);
    std::cout << "f. float x = 27825297;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // g. char *p; *p = 'Z';
    char* p;
    p = new char;
    *p = 'Z';
    binary = BinaryConversor::to_bin(*p);
    std::cout << "g. char *p; *p = 'Z';\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // h. float f = 0x000FFFFF;
    float f1 = 0x000FFFFF;
    binary = BinaryConversor::to_bin(f1);
    std::cout << "h. float f = 0x000FFFFF;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // i. short s  = -12040;
    short s = -12040;
    binary = BinaryConversor::to_bin(s);
    std::cout << "i. short s  = -12040;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // j. float x = -27825297.0f;
    float x1 = -27825297.0f;
    binary = BinaryConversor::to_bin(x1);
    std::cout << "j. float x = -27825297\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // k. int *p1; *p1 = 15678;
    int* p1;
    p1 = new int;
    *p1 = 15678;
    binary = BinaryConversor::to_bin(*p1);
    std::cout << "k. int *p; *p = 15678;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // l. float f = 0x000FFF9F. Show its base 10 formula
    float f2 = 0x000FFF9F;
    binary = BinaryConversor::to_bin(f2);
    std::cout << "l. float f = 0x000FFF9F;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // m. short j = -19842;
    short s1 = -19842;
    binary = BinaryConversor::to_bin(s1);
    std::cout << "m. short j = -19842;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // n. double x = -100036.875
    double dx = -100036.875;
    binary = BinaryConversor::to_bin(dx);
    std::cout << "n. double x = -100036.875;\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // o. char *p2; p2 = new char; *p = 'A';
    char* p2;
    p2 = new char;
    *p2 = 'A';
    binary = BinaryConversor::to_bin(*p2);
    std::cout << "o. char *p; p = new char; *p = 'A'\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();

    // p. float f = 0x000FF0A1. Show its base 10 formula
    float f3 = 0x000FF0A1;
    binary = BinaryConversor::to_bin(f3);
    std::cout << "p. float f = 0x000FF0A1\n\n" << MemoryRepresentator::to_memory(binary) << std::endl;
    bar();
}
#pragma once

#include "bin.h"
// Class that converts a decimal into its binary format
class BinaryConversor
{
private:
    static std::string uint_to_bin(unsigned long long number);
    static std::string dec32_to_bin(float decimal);
    static std::string dec64_to_bin(double decimal);


    static bin uint8_to_bin(unsigned char number);
    static bin uint16_to_bin(unsigned short number);
    static bin uint32_to_bin(unsigned int number);
    static bin uint64_to_bin(unsigned long long number);
    static bin int16_to_bin(short number);
    static bin int32_to_bin(int number);
    static bin int64_to_bin(long long number);
    static bin float32_to_bin(float number);
    static bin float64_to_bin(double number);

public:
    static const bin to_bin(const char number);

    static const bin to_bin(const short number);
    static const bin to_bin(const unsigned short number);

    static const bin to_bin(const int number);
    static const bin to_bin(const unsigned int number);

    static const bin to_bin(const long number);
    static const bin to_bin(const unsigned long number);

    static const bin to_bin(const long long number);
    static const bin to_bin(const unsigned long long number);

    static const bin to_bin(const float number);
    static const bin to_bin(const double number);

};
#pragma once
// Class that converts a decimal into its binary format
class BinaryConversor
{
private:
    static void positive_int_to_bin(int number, std::string& bin);
    static void negative_int_to_bin(int number, std::string& bin);
    static void decimal_to_bin(float decimal, std::string& bin);
    static void invert_bin(std::string& bin);
    static void add_one(std::string& bin);

public:
    static const std::string to_bin(const int& number);
    static const std::string to_bin(const float& number);
    
};
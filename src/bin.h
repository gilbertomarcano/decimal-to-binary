#pragma once
#include <iostream>

class bin
{
private:
	// Private member variables
	std::string binary_string;
	unsigned int _capacity;
	bool is_float;

	// Private member functions
	void append(std::string str);
	bool is_valid(const std::string& binary_string);
	void prepend(std::string str);
	void set_capacity(unsigned int bytes);

public:
	// Constructor
	bin();
	bin(std::string binary_string, unsigned int bytes);

	std::string get_binary_string();
	unsigned int capacity();

	void change_endianness();
	int size();
	void inverse();
	

	const bin& operator=(const bin& other);
	const bin operator+(const bin& other);
	const bin& operator+=(const bin& other);
	const char& operator[](int index);


	std::string to_string()
	{
		return binary_string;
	}
};


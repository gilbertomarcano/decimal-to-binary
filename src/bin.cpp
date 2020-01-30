#include "bin.h"

/*
********************************
*
*   Private member functions
*
********************************
*/

/*
	Inverse the one's and the zero's in the binary string 
*/
void bin::inverse()
{
	for (char& bit : binary_string)
	{
		bit = bit == '0' ? '1' : '0';
	}
}

bool bin::is_valid(const std::string& binary_string)
{
	for (const char& bit : binary_string)
	{
		if (bit == '0' || bit == '1')
			continue;
		return false;
	}

	return true;
}

/*
********************************
*
*   Public member functions
*
********************************
*/

bin::bin() : is_float(false), binary_string(""), _capacity(0) {}

bin::bin(std::string binary_string, unsigned int bytes)
	: is_float(false), binary_string(""), _capacity(0)
{
	if (is_valid(binary_string) && binary_string.size() <= bytes * 8)
	{
		this->binary_string = binary_string;
		set_capacity(bytes);
	}
	else
	{
		set_capacity(1);
	}
}

std::string bin::get_binary_string()
{
	return binary_string;
}

/**
* Set the size of a binary string to a certain quantity of bytes
* @param bytes the size in bytes to be assigned to the binary string
*/
void bin::set_capacity(unsigned int bytes)
{
	_capacity = bytes;
	while (binary_string.size() < _capacity * 8)
	{
		prepend("0");
	}

}

int bin::size()
{
	return binary_string.size();
}

void bin::append(std::string str)
{
	binary_string = binary_string + str;
}

void bin::prepend(std::string str)
{
	binary_string = str + binary_string;
}

unsigned int bin::capacity()
{
	return _capacity;
}

/*
********************************
*
*   Operators
*
********************************
*/

const bin& bin::operator=(const bin& other)
{
	this->binary_string = other.binary_string;
	this->_capacity = other._capacity;
	this->is_float = other.is_float;

	return *this;
}

const bin bin::operator+(const bin& other)
{
	std::string result("");
	int s = 0;

	int i = binary_string.size() - 1;
	int j = other.binary_string.size() - 1;
	while (i >= 0 || j >= 0 || s == 1)
	{
		// Comput sum of last digits and carry 
		s += ((i >= 0) ? binary_string[i] - '0' : 0);
		s += ((j >= 0) ? other.binary_string[j] - '0' : 0);

		// If current digit sum is 1 or 3, add 1 to result 
		result = char(s % 2 + '0') + result;

		// Compute carry 
		s /= 2;

		// Move to next digits 
		i--; j--;
	}
	// Check later if capacity of result is greater than original ones
	return bin(result, this->_capacity);
}

const bin& bin::operator+=(const bin& other)
{
	*this = *this + other;
	return *this;
}

const char& bin::operator[](int index)
{
	return binary_string[index];
}
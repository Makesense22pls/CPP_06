#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>

class ScalarConverter {
public:
	static void convert(const std::string &input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();


	//check
	static bool isvalidchar(double value);
	static bool isvalidint(double value);
	static bool parseinput(const std::string &input, double &value);

	//parse
	static bool parseChar(const std::string &input, double &value);
	static bool parseSpecial(const std::string &input, double &value);
	static bool parseFloat(const std::string &input, double &value);
	static bool parseDouble(const std::string &input, double &value);
	static bool parseInt(const std::string &input, double &value);
	
	//Print 
	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);

};











#endif
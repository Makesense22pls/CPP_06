#include "Scalar.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isvalidchar(double value) {
	return ((!std::isnan(value) && !std::isinf(value) && value >= 0 && value <= 127));
}

bool ScalarConverter::isvalidint(double value) {
	return ((!std::isnan(value) && !std::isinf(value) && value <= std::numeric_limits<int>::max() && 
	value >= std::numeric_limits<int>::min()));
}

bool ScalarConverter::parseChar(const std::string& input, double& value) {
	int size = input.length();
	if (size == 3 && input[0] == '\'' && input[2] == '\'') 
	{
		char c = input[1];
		value = static_cast<double>(c);
		return (true);
	}
	return (false);
}

bool ScalarConverter::parseinput(const std::string& input, double& value) {
	if (parseChar(input, value))
		return (true);
	if (parseSpecial(input, value))
		return (true);
	if (parseFloat(input, value))
		return (true);
	if (parseDouble(input, value))
		return (true);
	if (parseInt(input, value))
		return (true);
	return (false);
}
bool ScalarConverter::parseSpecial(const std::string& input, double& value) {
	if (input == "nan" || input == "nanf") 
	{
		value = strtod("nan", NULL);
		return (true);
	}
	if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff") 
	{
		value = strtod("inf", NULL);
		return (true);
	}
	if (input == "-inf" || input == "-inff") 
	{
		value = strtod("-inf", NULL);
		return (true);
	}
	return (false);
}


bool ScalarConverter::parseFloat(const std::string& input, double& value) {
	int size = input.length();
	if (size > 1 && input[size - 1] == 'f') 
	{
		int dotCount = 0;
		int i = (input[0] == '+' || input[0] == '-') ? 1 : 0;
		while (i < size - 1) {
			if (input[i] == '.')
				dotCount++;
			else if (!isdigit(input[i]))
				return (false);
			i++;
		}
		if (dotCount == 0 || dotCount == 1) {
			value = static_cast<double>(strtof(input.c_str(), NULL));
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::parseDouble(const std::string& input, double& value) {
	int size = input.length();
	if (input.find('.') != std::string::npos) {
		int dotCount = 0;
		int i = (input[0] == '+' || input[0] == '-') ? 1 : 0;
		while (i < size) {
			if (input[i] == '.')
				dotCount++;
			else if (!isdigit(input[i]))
				return (false);
			i++;
		}
		if (dotCount == 1) {
			value = strtod(input.c_str(), NULL);
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::parseInt(const std::string& input, double& value) {
	int size = input.length();
	int i = (input[0] == '+' || input[0] == '-') ? 1 : 0;
	if (i == size)
		return (false);
	while (i < size) {
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	value = strtol(input.c_str(), NULL, 10);
	return (true);
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f)) {
		if (f > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else if (f == static_cast<int>(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d)) {
		if (d > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else if (d == static_cast<int>(d))
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << d << std::endl;
}


void ScalarConverter::convert(const std::string& input) {
	double value = 0.0;
	
	if (!parseinput(input, value)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	if (isvalidchar(value)) {
		if (value < 32 || value > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			printChar(static_cast<char>(value));
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	
	if (isvalidint(value))
		printInt(static_cast<int>(value));
	else
		std::cout << "int: impossible" << std::endl;
	
	printFloat(static_cast<float>(value));
	printDouble(value);
}


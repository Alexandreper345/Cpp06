#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();

	static bool isPseudoLiteral(const std::string& value);
	static void convertChar(double num_double);
	static void convertInt(double num_double);
	static void convertFloat(double num_double);
	static void convertDouble(double num_double);
public:
	static void convert(const std::string& value);
};

#endif
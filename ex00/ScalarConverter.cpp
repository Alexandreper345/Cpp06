#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

void ScalarConverter::convert(const std::string value)
{
	double num_double = std::stod(value);
	
	if (std::isnan(num_double))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << num_double << std::endl;


	float num_float = static_cast<float>(num_double);
	
	if (std::isinf(num_float))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << num_float << std::endl;
	

	int	num_int = static_cast<int>(num_double);

	if (!isalnum(num_int))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << num_int << std::endl;


	if (num_int < 0 || num_int > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(num_int))
		std::cout << "char: Non displayble" << std::endl;
	else
		std::cout << "char:" << static_cast<char>(num_int) << std::endl;
}

ScalarConverter::~ScalarConverter()
{
}
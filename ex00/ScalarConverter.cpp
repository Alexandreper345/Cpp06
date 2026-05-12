#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter()
{
}

static bool isPseudoLiteral(const std::string& value)
{
	return (value == "nan" || value == "nanf" || value == "+inf" || value == "+inff" || value == "-inf" || value == "-inff");
}

static bool isChar(const std::string& value)
{
	return (value.length() == 1 && !std::isdigit(value[0]));
}

static void convertChar(double num_double)
{

	if (std::isnan(num_double) || std::isinf(num_double) || num_double > 127 || num_double < 0)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	char c = static_cast<char>(num_double);

	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void convertInt(double num_double)
{
	if (std::isnan(num_double) || std::isinf(num_double)
		|| num_double > INT_MAX || num_double < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(num_double) << std::endl;
}

static void convertFloat(double num_double)
{
	float num_float = static_cast<float>(num_double);
	
	if (std::isinf(num_float) && !std::isinf(num_double))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << num_float << "f" << std::endl;
}

static void convertDouble(double num_double)
{
	if (std::isnan(num_double))
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << num_double << std::endl;
}

void ScalarConverter::convert(const std::string& value)
{

	if (isPseudoLiteral(value))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (value[value.length() - 1] == 'f')
		{
			std::cout << "float: " << value << std::endl;
			std::cout << "double: " << value.substr(0, value.length() - 1) << std::endl;
		}
		else
		{
			std::cout << "float: " << value << "f" << std::endl;
			std::cout << "double: " << value << std::endl;
		}
		return ;
	}

	if (isChar(value))
	{
		double num_double = static_cast<double>(value[0]);
		convertChar(num_double);
		convertInt(num_double);
		convertFloat(num_double);
		convertDouble(num_double);
	}
	else
	{
		char* end;
		double num_double = std::strtod(value.c_str(), &end);

		if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0'))
		{
    		std::cout << "Invalid literal" << std::endl;
    		return ;
		}
		convertChar(num_double);
		convertInt(num_double);
		convertFloat(num_double);
		convertDouble(num_double);
	}
}

ScalarConverter::~ScalarConverter()
{
}
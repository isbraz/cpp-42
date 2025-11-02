#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter( const ScalarConverter& toCopy ) {
	(void)toCopy;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& toCopy ) {
	(void)toCopy;
	return *this;
}

static void print_char( double nbr ){
	std::cout << "char: ";

	if (nbr < std::numeric_limits<char>::min() ||
			nbr > std::numeric_limits<char>::max() || 
			std::isnan(nbr) || std::isinf(nbr)) {
		std::cout << "impossible";
	} else if (nbr < 32 || nbr > 126) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'" << static_cast<char>(nbr) << "'";
	}
	std::cout << std::endl;
}

static void print_int( double nbr ){
	std::cout << "int: ";
	if (nbr < std::numeric_limits<int>::min() ||
			nbr > std::numeric_limits<int>::max() || 
			std::isnan(nbr) || std::isinf(nbr)) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(nbr);
	}
	std::cout << std::endl;
}

static void print_float( double nbr ){
	std::cout << "float: ";
	float f = static_cast<float>(nbr);
	
	if (std::isnan(f)) {
		std::cout << "nanf";
	} else if (std::isinf(f)) {
		std::cout << (f > 0 ? "+inff" : "-inff");
	} else {
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	}
	std::cout << std::endl;
}

static void print_double( double nbr ){
	std::cout << "double: ";
	
	if (std::isnan(nbr)) {
		std::cout << "nan";
	} else if (std::isinf(nbr)) {
		std::cout << (nbr > 0 ? "+inf" : "-inf");
	} else {
		std::cout << std::fixed << std::setprecision(1) << nbr;
	}
	std::cout << std::endl;
}

static double stringToDouble( std::string& str ) {
	std::string temp = str;
	
	// Handle special values
	if (temp == "nan" || temp == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (temp == "+inf" || temp == "+inff")
		return std::numeric_limits<double>::infinity();
	if (temp == "-inf" || temp == "-inff")
		return -std::numeric_limits<double>::infinity();
	
	// Remove 'f' suffix if present
	if (!temp.empty() && temp[temp.size() - 1] == 'f') {
		temp.resize(temp.size() - 1);
	}
	
	char *endptr;
	double value = std::strtod(temp.c_str(), &endptr);
	
	if (*endptr != '\0') {
		return std::numeric_limits<double>::quiet_NaN();
	}
	return value;
}

void ScalarConverter::convert( std::string literal ) {
	double value;

	// Check for char literal: 'c'
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
		value = static_cast<double>(literal[1]);
	}
	// Single character without quotes
	else if (literal.length() == 1 && !isdigit(literal[0])) {
		value = static_cast<double>(literal[0]);
	}
	// Everything else (int, float, double)
	else {
		value = stringToDouble(literal);
	}
	
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}
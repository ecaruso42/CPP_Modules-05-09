#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input){
	char c;
	int i;
	float f;
	double d;

	if (input == "-inff" || input == "+inff" || input == "nanf") {
		f = static_cast<float>(std::atof(input.c_str()));
		d = static_cast<double>(f);
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << "" << std::endl;
        return;
	}
	if (input == "-inf" || input == "+inf" || input == "nan") {
        d = std::atof(input.c_str());
        std::cout << "char: impossible" << std::endl ;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d  << std::endl;
        return;
    }
	std::cout << input << std::endl;
	if (input.length() == 1 && input[0] < 0 && input[0] > 9){
		c = input[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float " << f << "f" << std::endl;
    	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
		std::cout << "ciao1\n";
		return;
	}

	i = std::atoi(input.c_str());
	if (i == 0 && input != "0"){
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
		std::cout << "ciao\n";
        return;
	}

	f = static_cast<float>(std::atof(input.c_str()));
    d = static_cast<double>(std::atof(input.c_str()));
    c = static_cast<char>(i);

	if (i >= 32 && i <= 126) {
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	(void) other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter(){
}
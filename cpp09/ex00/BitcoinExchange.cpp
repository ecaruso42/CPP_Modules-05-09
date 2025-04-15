#include "BitcoinExchange.hpp"

static bool isValidDate(std::string date){

}

void BitcoinExchange::parseIf(std::string fileName){
	std::ifstream file(fileName.c_str());
	if(!file){
		std::cerr << "Error: input file not found." << std::endl;
		std::exit(1);
	}
	std::cout << fileName << std::endl;
}

void BitcoinExchange::parseCsv(){
	std::ifstream file("data.csv");
	if(!file){
		std::cerr << "Error: csv file not found." << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)){
		std::stringstream ss(line);
		std::string date, valueStr;

		if (!getline(ss, date, ',') || !getline(ss, valueStr))
			continue;
		
		double value = std::atof(valueStr.c_str());
		if (isValidDate(date))
			_csvMap[date] = value;
	}
}

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	_csvMap = other._csvMap;
}

const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
	if (this != &other){
		_csvMap = other._csvMap;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){

}
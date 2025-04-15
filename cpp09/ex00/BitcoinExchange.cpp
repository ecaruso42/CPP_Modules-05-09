#include "BitcoinExchange.hpp"

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(std::string date){
	if(date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::stringstream ss(date);
	int y, m, d;
	char dash;
	int mlenght[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	ss >> y >> dash >> m >> dash >> d;
	int max_day = mlenght[m - 1];
	if (m == 2 && isLeapYear(y))
		max_day = 29;
	if(ss.fail() || y < 2009 || m < 1 || m > 12 || d < 1 || d > max_day)
		return false;
	return true;
}

static double getClosestRate(const std::map<std::string, double>& map, const std::string& date) {
	std::map<std::string, double>::const_iterator it = map.lower_bound(date);
	if (it == map.end() || it->first != date) {
		if (it == map.begin())
			return -1;
		--it;
	}
	return it->second;
}

void BitcoinExchange::parseIf(std::string fileName){
	std::ifstream file(fileName.c_str());
	if(!file){
		std::cerr << "Error: input file not found." << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)){
		if(line.empty())
			continue;
		std::stringstream ss(line);
		std::string date, valueStr;
		if (!getline(ss, date, '|') || !getline(ss, valueStr)){
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value;
		std::stringstream vs(valueStr);
		vs >> value;

		if (vs.fail() || value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > INT_MAX) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = getClosestRate(_csvMap, date);
		if (rate < 0) {
			std::cerr << "Error: no rate available for date " << date << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " 
		          << std::fixed << std::setprecision(2) << (rate * value) << std::endl;
	}
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
#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <iomanip>

class BitcoinExchange{

private:
	std::map<std::string, double> _csvMap;

public:
	void parseCsv();
	void parseIf(std::string fileName);

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	const BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
};

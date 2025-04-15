#include "BitcoinExchange.hpp"

int main(int argc, char** argv){
	if(argc != 2){
		std::cerr << "Error: argoument count not correct." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	
	btc.parseCsv();
	btc.parseIf(argv[1]);
	return 0;
}
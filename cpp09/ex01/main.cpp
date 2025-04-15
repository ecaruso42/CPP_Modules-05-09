#include "RPN.hpp"

int main(int argc, char** argv){
	if(argc != 2){
		std::cerr << "Error: invalid argoument count" << std::endl;
		return 1;
	}
	RPN RPN;
	RPN.doTheMath(argv[1]);
	return 0;
}
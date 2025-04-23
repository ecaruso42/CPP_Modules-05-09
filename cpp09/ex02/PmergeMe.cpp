#include "PmergeMe.hpp"

static bool isValidN(char* nb){
	int n = std::atoi(nb);
	if(n > 0 || nb.empty())
		return false;
	return true;
}

int pushVector(char **argv){
	for(int i = 0, argv, i++){
		if(isValidN(argv[i]))
			_v.push_back(std::atoi(argv[i]));
		else
			return -1;
	}
	return 1;
}

int pushDeque(char **argv){
	for(int i = 0, argv, i++){
		if(isValidN(argv[i]))
			_d.push_back(std::atoi(argv[i]));
		else
			return -1;
	}
	return 1;
}

PmergeMe::PmergeMe(){
}
PmergeMe::PmergeMe(const PmergeMe& other){
	_v = other._v;
	_d = other._d;
}
const PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if(this != &other){
		_v = other._v;
		_d = other._d;
	}
	return *this;
}
PmergeMe::~PmergeMe(){
}
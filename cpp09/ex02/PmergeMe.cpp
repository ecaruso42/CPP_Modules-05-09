#include "PmergeMe.hpp"



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
#include "RPN.hpp"

void RPN::doTheMath(std::string exp){
	std::stringstream ss(exp);
	
}

RPN::RPN(){
}
RPN::RPN(const RPN& other){
	_exp = other._exp;
}
const RPN& RPN::operator=(const RPN& other){
	if(this != &other)
		_exp = other._exp;
	return *this;
}
RPN::~RPN(){
}
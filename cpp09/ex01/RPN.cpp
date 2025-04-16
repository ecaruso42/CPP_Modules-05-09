#include "RPN.hpp"

void RPN::doTheMath(std::string exp){
	std::stringstream ss(exp);
	std::string token;

	while(ss >> token){
		if(token == "+" || token == "-" || token == "*" || token == "/"){
			if(_s.size() == 2){
				int a, b, c;

				b = _s.top();
				_s.pop();
				a = _s.top();
				_s.pop();
				if(token == "+")
					c = a + b;
				if(token == "-")
					c = a - b;
				if(token == "*")
					c = a * b;
				if(token == "/"){
					if (b == 0){
						std::cout << "Error: division by zero" << std::endl;
						return;
					}
					c = a / b;
				}
				_s.push(c);
			}
			else{
				std::cerr << "Error: invalid operation" << std::endl;
				return;
			}
		}
		else if(token.size() == 1 && isdigit(token[0])){
			int a;

			a = token[0] - '0';
			_s.push(a);
		}
		else{
			std::cerr << "Error: invalid operand or number" << std::endl;
			return;
		}
	}
	if (_s.size() != 1) {
		std::cerr << "Error: invalid expression" << std::endl;
		return;
	}
	std::cout << _s.top() << std::endl;
}

RPN::RPN(){
}
RPN::RPN(const RPN& other){
	_s = other._s;
}
const RPN& RPN::operator=(const RPN& other){
	if(this != &other)
		_s = other._s;
	return *this;
}
RPN::~RPN(){
}
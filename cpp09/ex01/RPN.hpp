#pragma once

#include <stack>
#include <iostream>
#include <sstream>

class RPN{
	private:
		std::stack<int> _exp;
	public:
		void doTheMath(std::string exp);

		RPN();
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);
		~RPN();
};
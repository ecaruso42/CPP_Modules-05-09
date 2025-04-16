#pragma once

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

class RPN{
	private:
		std::stack<int> _s;
	public:
		void doTheMath(std::string exp);

		RPN();
		RPN(const RPN& other);
		const RPN& operator=(const RPN& other);
		~RPN();
};
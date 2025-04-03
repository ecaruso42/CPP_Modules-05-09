#pragma once

#include <iostream>
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >

class MutantStack : std::stack<T>{
	public:
		MutantStack(){}
		MutantStack(const MutantStack& other){
			if (*this != other)
				*this = std::stack<T, Container>::operator=(other);
		}
		MutantStack& operator=(const MutantStack& other){
			if (*this != other)
				this->c = other.c;
			return *this;
		}
		~MutantStack(){}
};
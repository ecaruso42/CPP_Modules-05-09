#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

template<typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>{
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

		typedef typename Container::iterator iterator;

		iterator begin() { return this->c.begin(); }
    	iterator end() { return this->c.end(); }
};
#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe{
	private:
		std::vector<int> _v;
		std::deque<int> _d;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		const PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();
};
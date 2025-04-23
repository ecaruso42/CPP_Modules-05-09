#pragma once

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe{
	private:
		std::vector<int> _v;
		std::deque<int> _d;
	public:
		int pushVector(char **argv);
		int pushDeque(char **argv);

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		const PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();
};
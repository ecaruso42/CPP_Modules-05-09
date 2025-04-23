#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <ctime>

class PmergeMe{
	private:
		std::vector<int> _v;
		std::deque<int> _d;
	public:
		int pushVector(char **argv);
		int pushDeque(char **argv);
		void run();
		void printCont();

		template<typename T>
		void mergeInsertSort(T& container);

		PmergeMe();
		PmergeMe(const PmergeMe& other);
		const PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();
};
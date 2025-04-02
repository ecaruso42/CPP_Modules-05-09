#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	std::vector<int> _v;
	unsigned int _N;
public:
	void addNumber(int nb);
	int shortestSpan();
	int longestSpan();
	void addSequence(std::vector<int> v);

	Span(unsigned int n);
	Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
};


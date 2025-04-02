#include "Span.hpp"

void Span::addNumber(int nb){
	_v.push_back(nb);
}

int Span::shortestSpan(){
	int sSpan = std::numeric_limits<int>::max();
	std::sort(_v.begin(), _v.end());
	for (size_t i = 1; i < _v.size(); ++i) {
        sSpan = std::min(sSpan, _v[i] - _v[i - 1]);
	}
	return sSpan;
}
int Span::longestSpan(){
	std::sort(_v.begin(), _v.end());
	return (_v.back() - _v.front());
}

void Span::addSequence(std::vector<int> v){
	_v.insert(v.end(), v.begin(), v.end());
}

Span::Span(unsigned int n) : _N(n){
}

Span::Span(){
	this->_N = 0;
}

Span::Span(const Span& other){
	_N = other._N;
}

Span& Span::operator=(const Span& other){
	_N = other._N;
	return *this;
}

Span::~Span(){
}
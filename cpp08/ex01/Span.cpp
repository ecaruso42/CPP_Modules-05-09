#include "Span.hpp"

void Span::addNumber(int nb){
	if (_v.size() >= _N)
		throw std::runtime_error("Max number limit reached");
	_v.push_back(nb);
}

int Span::shortestSpan(){
	if (_v.size() < 2)
		throw std::runtime_error("Not enough numbers in the container");
	int sSpan = std::numeric_limits<int>::max();
	std::sort(_v.begin(), _v.end());
	for (size_t i = 1; i < _v.size(); ++i) {
        sSpan = std::min(sSpan, _v[i] - _v[i - 1]);
	}
	return sSpan;
}
int Span::longestSpan(){
	if (_v.size() < 2)
		throw std::runtime_error("Not enough numbers in the container");
	std::sort(_v.begin(), _v.end());
	return (_v.back() - _v.front());
}

void Span::addSequence(unsigned int count){
	if(count > 0 && count <= (_N + _v.size())) {
		std::vector<int> v;
		std::srand(std::time(0));
		for (unsigned int i = 0; i < count; i++){
			int randNb = std::rand() % count;
			v.push_back(randNb);
		}
		_v.insert(_v.end(), v.begin(), v.end());
	}
	else
		throw std::runtime_error("Count is less than 1 or is higher than maximum");
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
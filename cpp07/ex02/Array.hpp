#pragma once
#include "Array.tpp"
#include <iostream>

template<typename T> class Array {
	private:
		T* _data;
		unsigned int _size;
	public:
		Array(unsigned int n);
		Array();
		Array(const Array<T> &other);
		Array& operator=(const Array<T> &ohter);
		~Array();
};
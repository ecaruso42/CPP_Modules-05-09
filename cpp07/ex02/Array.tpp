#include "Array.hpp"

template <typename T> Array<T>::Array(unsigned int n) : _size(n){
	_data = new T[n];
}

template <typename T> Array<T>::Array() : _data(NULL), _size(0){
}

template <typename T> Array<T>::Array(const Array<T> &other) : _size(other._size){
	data = new T[n];
	for (unsigned int i = 0; i < _size; i++){
		data[i] = other.data[i];
	}
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T> &ohter){
	if (this != &other) {
		delete[] data;

		_size = other._size;
		data = new T[_size];
		for (unsigned int i = 0; i < _size; i++){
			data[i] = other.data[i];
		}
		return *this;
	}
}

template <typename T> Array<T>::~Array(){
	delete[] data;
}
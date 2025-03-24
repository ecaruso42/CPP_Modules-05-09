#pragma once
#include <iostream>

template<typename T> void iter(T* adrs, size_t len, void (*func)(T&)){
	for (size_t i = 0; i < len; i++){
		func(adrs[i]);
	}
}

template<typename T> void print(T& var){
	std::cout << var << "";
}

template<typename T> void makeit42print(T& var){
	var = 42;
	std::cout << static_cast<int>(var) << " ";
}
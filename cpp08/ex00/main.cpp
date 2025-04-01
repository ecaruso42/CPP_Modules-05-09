#include "easyfind.hpp"

int main(void){
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	int nb = 40;
	std::cout << "Searching occurence in a vector..." << std::endl;
	if (easyfind(v, nb) == 1){
		std::cout << "Vector Occurence Found! :D" << std::endl;
	}
	else
	std::cout << "Vector Occurence Not Found! :(" << std::endl;
	std::deque<int> dq;
	dq.push_back(20);
	dq.push_front(10);
	dq.push_back(30);
	std::cout << "Searching occurence in a deque..." << std::endl;
	if (easyfind(dq, nb) == 1){
		std::cout << "Deque Occurence Found! :D" << std::endl;
	}
	else
	std::cout << "Deque Occurence Not Found! :(" << std::endl;
	return 0;
}
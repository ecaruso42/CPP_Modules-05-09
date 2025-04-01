#include "easyfind.hpp"

template <typename T> int easyfind(T& container, int nb){
	for (size_t i = 0; i < container.size(); i++){
		if (container[i] == nb)
			return 1;
	}
	return -1;
}
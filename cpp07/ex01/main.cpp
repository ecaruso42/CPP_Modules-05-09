#include "iter.hpp"

int main(void){
	int array[] = {1, 2, 3, 4, 5};
	char str[] = "Hello World!";
	size_t len = sizeof(array) / sizeof(array[0]);
	size_t len2 = sizeof(str) / sizeof(str[0]) - 1;

	std::cout << "Array di int prima del MakeIt42® = ";
	iter(array, len, print);
	std::cout << "\nArray di int dopo il MakeIt42® = ";
	iter(array, len, makeit42print);


	std::cout << "\n\n";


	std::cout << "Array di char prima del MakeIt42® = ";
	iter(str, len2, print);
	std::cout << "\nArray di char dopo il MakeIt42® = ";
	iter(str, len2, makeit42print);
}
#include "Span.hpp"

int main(void){
	try{
		std::cout << "Test addNumber\n";

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "Test addSequence\n";

		Span sp1(10000);

		sp1.addSequence(10000);

		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;

	} catch(const std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
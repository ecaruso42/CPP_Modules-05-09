#include "PmergeMe.hpp"

int main(int argc, char** argv){
	if(argc < 2){
        std::cerr << "Error: argoument count not valid" << std::endl;
        return 1;
    }
	PmergeMe FJ;
    argv++;

	if(FJ.pushVector(argv) == -1){
		std::cerr << "Error: number in argoument is not correct" << std::endl;
		return 1;
	}
	if(FJ.pushDeque(argv) == -1){
		std::cerr << "Error: number in argoument is not correct" << std::endl;
		return 1;
	}
	FJ.run();
}
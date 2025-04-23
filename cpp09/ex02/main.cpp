#include "PmergeMe.hpp"

int main(int argc, char** argv){
	if(argc < 2){
        std::cerr << "Error: argoument count not valid" << std::endl;
        return 1;
    }
    argv++;
    pushVector(argv);
    pushDeque(argv);
}
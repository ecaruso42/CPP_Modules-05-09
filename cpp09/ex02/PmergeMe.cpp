#include "PmergeMe.hpp"

void PmergeMe::run(){
	std::cout << "Before: ";
	printCont();

	std::clock_t vStart = std::clock();
	mergeInsertSort(_v);
	std::clock_t vEnd = std::clock();

	std::clock_t dStart = std::clock();
	mergeInsertSort(_d);
	std::clock_t dEnd = std::clock();

	std::cout << "After: ";
	printCont();

	double vTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1000000;
	double dTime = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector: " << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _d.size() << " elements with std::deque: " << dTime << " us" << std::endl;
}

template<typename T>
void PmergeMe::mergeInsertSort(T& container){
	if(container.size() <= 1)
		return;

	T greaterNbs;
	T minorNbs;
	size_t n = container.size();

	for(size_t i = 0; i + 1 < n; i += 2){
		int a = container[i];
		int b = container[i + 1];
		if(a < b) 
			std::swap(a, b);
		greaterNbs.push_back(a);
		minorNbs.push_back(b);
	}
	if (n % 2 == 1) {
		minorNbs.push_back(container[n - 1]);
	}
	mergeInsertSort(greaterNbs);

	std::vector<size_t> jSequence;
    if (minorNbs.size() > 1) {
        size_t j0 = 0;
		size_t j1 = 1;
        jSequence.push_back(j1);
        while (1) {
            size_t j2 = j1 + 2 * j0;
            if (j2 >= minorNbs.size() || j2 <= j1)
                break;
            jSequence.push_back(j2);
            j0 = j1;
            j1 = j2;
        }
	}
	std::vector<bool>inserted(minorNbs.size(), false);
	for(size_t k = 0; k < jSequence.size(); ++k){
		size_t idx = jSequence[k];
		int val = minorNbs[idx];
		typename T::iterator pos = std::lower_bound(greaterNbs.begin(), greaterNbs.end(), val);
		greaterNbs.insert(pos, val);
		inserted[idx] = true;
	}
	for(size_t i = 0; i < minorNbs.size(); ++i){
		if(!inserted[i]){
			int val = minorNbs[i];
			typename T::iterator pos = std::lower_bound(greaterNbs.begin(), greaterNbs.end(), val);
			greaterNbs.insert(pos, val);
		}
	}
	container = greaterNbs;
}

void PmergeMe::printCont(){
	for (std::size_t i = 0; i < _v.size(); ++i) {
        std::cout << _v[i];
        if (i + 1 < _v.size()) std::cout << " ";
    }
    std::cout << "\n";
}

static bool isValidN(char* nb){
	int n = std::atoi(nb);
	if(n > 0 && nb)
		return true;
	return false;
}

int PmergeMe::pushVector(char **argv){
	for(int i = 0; argv[i] != NULL; i++){
		if(isValidN(argv[i]))
			_v.push_back(std::atoi(argv[i]));
		else
			return -1;
	}
	return 1;
}

int PmergeMe::pushDeque(char **argv){
	for(int i = 0; argv[i] != NULL; i++){
		if(isValidN(argv[i]))
			_d.push_back(std::atoi(argv[i]));
		else
			return -1;
	}
	return 1;
}

PmergeMe::PmergeMe(){
}
PmergeMe::PmergeMe(const PmergeMe& other){
	_v = other._v;
	_d = other._d;
}
const PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if(this != &other){
		_v = other._v;
		_d = other._d;
	}
	return *this;
}
PmergeMe::~PmergeMe(){
}
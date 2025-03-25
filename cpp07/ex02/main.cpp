#include "Array.hpp"

int main() {
    try {
        Array<int> arr1(5);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;

        std::cout << "Arr1: ";
        for (unsigned int i = 0; i < arr1.size(); i++)
            std::cout << arr1[i] << " ";
        std::cout << std::endl;

        Array<int> arr2 = arr1;
        arr2[1] = 99;
        std::cout << "Arr2 (copia modificata): ";
        for (unsigned int i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;

        Array<int> arr3;
        arr3 = arr1;
        arr3[2] = 77;
        std::cout << "Arr3 (dopo assegnazione da arr1): ";
        for (unsigned int i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;

        std::cout << "Accesso fuori dai limiti: " << arr1[10] << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Errore: " << e.what() << std::endl;
    }

    return 0;
}
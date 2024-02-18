#include <iostream>
#include <chrono>
#include <functional>
#include <random>

#include "include/sorting_library.h"
#include "timealgorithm.h"

int main() {
    std::cout << std::fixed << std::showpoint;
    std::cout.precision(9);
    print_version_number();

    int inOrderSize = 1000;
    int inOrderArray[inOrderSize];
    for(int i = 0; i < inOrderSize; i++){
        inOrderArray[i] = i;
    }

    std::function<void(int* array, int size)> sorters[5];
    sorters[0] = mystery01; //fast for large large sets and still seems to do many operations for in order sets while still being fast; merge sort
    sorters[1] = mystery02; //showing extremely slow with big unordered sets/ fast with big in order sets; optimized bubble sort
    sorters[2] = mystery03; //second slowest for large unordered sets and second fastest for large ordered sets; insertion sort
    sorters[3] = mystery04; //really slow with large in order sets; quick sort (grabs the maximum which is worst case; working with arrays so should be faster than merge)
    sorters[4] = mystery05; //extremely slow almost constant time with large unordered and ordered sets; selection sort


    // big unordered vs big in order
    for(int i = 0; i < 5; i++){
        timeAlgorithm(sorters[i], 1000);
        timeAlgorithm(sorters[i], inOrderArray, inOrderSize);
        std::cout << std::endl;
    }

    return 0;
}





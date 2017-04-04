#include <iostream>
#include "search.h"

int main() {
    int a[1000];
    for (int i = 0; i < 1000; i++) {
        a[i] = i + 1;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    srand((uint32_t)clock());
    int searchNum = 1 + rand()%1000;
    std::cout << "Searching for " << searchNum << " in array..." << std::endl;
    clock_t startTime = clock();
    int index = search::findIndexOfValueUsingBinarySearch(searchNum, a, 1000);
    clock_t endTime = clock();
    double numSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    if (index<0) {
        std::cout << "Non-recursive binary search could not find " << searchNum
                  << " in array." << std::endl;
    }
    else {
        std::cout << "Non-recursive binary search found " << searchNum
                  << " at index " << index
                  << " in "<< numSeconds
                  << " seconds." << std::endl;
    }

    startTime = clock();
    index = search::findIndexOfValueUsingSequentialSearch(searchNum, a, 1000);
    endTime = clock();
    numSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    if (index<0) {
        std::cout << "Sequential search could not find " << searchNum
                  << " in array." << std::endl;
    }
    else {
        std::cout << "Sequential search found " << searchNum
                  << " at index " << index
                  << " in "<< numSeconds
                  << " seconds." << std::endl;
    }

    return 0;
}
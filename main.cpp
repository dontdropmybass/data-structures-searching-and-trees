#include <iostream>

/// searches through an array for a value using a non-recursive binary search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int findIndexOfValueUsingBinarySearch(int searchValue, int* array, int arraySize) {
    int i = arraySize >> 1;
    int diff = i >> 1;
    for (int numberOfIterations = 0; numberOfIterations < arraySize; numberOfIterations++) {
        if (array[i]==searchValue) {
            return i;
        }
        else if (array[i]>searchValue) {
            i -= diff;
            diff = diff >> 1; // bit-shifting because it's quicker than dividing.
                              // i guess the compiler should probably do this instead of me.
                              // but my compiler apparently isn't nice enough to do that.
        }
        else {
            i += diff;
            diff = diff >> 1; // bit-shifting because it's quicker than dividing.
                              // i guess the compiler should probably do this instead of me.
                              // but my compiler apparently isn't nice enough to do that.
        }
    }
    return -1;
}

/// searches through an array for a value using a sequential search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int findIndexOfValueUsingSequentialSearch(int searchValue, int* array, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i]==searchValue) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[1000];
    for (int i = 0; i < 1000; i++) {
        a[i] = i;
        std::cout << i << " ";
    }
    std::cout << std::endl;
    srand((uint32_t)clock());
    int searchNum = rand()%1000;
    std::cout << "Searching for " << searchNum << " in array..." << std::endl;
    clock_t startTime = clock();
    int index = findIndexOfValueUsingBinarySearch(searchNum, a, 1000);
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
    index = findIndexOfValueUsingSequentialSearch(searchNum, a, 1000);
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
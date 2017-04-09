//
// Created by Alexander Cochrane on 2017-04-04.
//

#include "search.h"

/// searches through an array for a value using a non-recursive binary search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int search::findIndexOfValueUsingBinarySearch(int searchValue, int *array, int arraySize) {
    auto i = arraySize >> 1;
    auto diff = i >> 1;
    for (auto numberOfIterations = 0; numberOfIterations < arraySize; numberOfIterations++) {
        if (array[i]==searchValue) {
            return i;
        }
        else if (array[i]>searchValue) {
            i -= diff;
            diff = diff >> 1;   // bit-shifting because it's quicker than dividing.
                                // i guess the compiler should probably do this instead of me.
                                // but my compiler apparently isn't nice enough to do that.
        }
        else {
            i += diff;
            diff = diff >> 1;   // bit-shifting because it's quicker than dividing.
                                // i guess the compiler should probably do this instead of me.
                                // but my compiler apparently isn't nice enough to do that.
        }
        if (diff < 1) diff = 1;
    }
    return -1;
}

/// searches through an array for a value using a sequential search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int search::findIndexOfValueUsingSequentialSearch(int searchValue, int* array, int arraySize) {
    for (auto i = 0; i < arraySize; i++) {
        if (array[i]==searchValue) {
            return i;
        }
    }
    return -1;
}

/// searches through an array for a value using a recursive binary search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int search::findIndexOfValueUsingRecursiveBinarySearch(int searchValue, int *array, int start, int end) {
    int middle = (start + end) / 2;
    if(end < start) {
        return -1;
    }

    if(searchValue==array[middle]) {
        return middle;
    }
    else if(searchValue<array[middle]) {
        return findIndexOfValueUsingRecursiveBinarySearch(searchValue, array, start, middle - 1);
    }
    else {
        return findIndexOfValueUsingRecursiveBinarySearch(searchValue, array, middle + 1, end);
    }
}

/// searches through an array for a value using a recursive sequential search algorithm
/// \param searchValue : the value you are searching for
/// \param array : the array in which you are searching for the value
/// \param arraySize :
/// \return the index of the searchValue in the array, or -1 if it's not found
int search::findIndexOfValueUsingRecursiveSequentialSearch(int searchValue, int *array, int arraySize) {
    if (arraySize<1) return -1;
    else if (array[arraySize-1]==searchValue) return arraySize-1;
    else return findIndexOfValueUsingRecursiveSequentialSearch(searchValue, array, arraySize - 1);
}

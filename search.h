//
// Created by Alexander Cochrane on 2017-04-04.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_SEARCH_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_SEARCH_H


class search {
public:
    static int findIndexOfValueUsingBinarySearch(int searchValue, int* array, int arraySize);
    static int findIndexOfValueUsingSequentialSearch(int searchValue, int* array, int arraySize);
    static int findIndexOfValueUsingRecursiveBinarySearch(int searchValue, int* array, int start, int end);
    static int findIndexOfValueUsingRecursiveSequentialSearch(int searchValue, int* array, int arraySize);
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_SEARCH_H

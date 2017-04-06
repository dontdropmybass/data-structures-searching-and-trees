#include <iostream>
#include "search.h"
#include "bst.h"

int main() {
    // searching
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

    // now for the avl tree part

    bst searchtree;

    searchtree.Insert( 5 );
    searchtree.Insert( 3 );
    searchtree.Insert( 7 );
    searchtree.Insert( 2 );
    searchtree.Insert( 1 );
    searchtree.Insert( 4 );
    searchtree.Insert( 6 );
    searchtree.Insert( 8 );
    searchtree.Insert(10 );


    std::cout << searchtree << endl;
    std::cin.ignore();

    // test 2
    std::cout << "\n\nTest 2\n";
    std::cout << "-----\n";

    searchtree.Remove( std::to_string(7) );

    std::cout << searchtree << endl;
    std::cin.ignore();

    searchtree.Insert(7);
    std::cout << searchtree << endl;
    std::cin.ignore();

    searchtree.Insert(7);

    std::cout << searchtree << endl;

    std::cin.ignore();

    return 0;
}
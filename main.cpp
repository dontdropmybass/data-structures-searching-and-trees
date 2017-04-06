#include <iostream>
#include "search.h"
#include "bst.h"

int main() {
    // searching
    int a[1000];
    for (int i = 0; i < 1000; i++) {
        a[i] = i + 1;
    }
    std::cout << std::endl;
    srand((uint32_t)clock());
    std::cout << "Searching for 1000 different numbers..." << std::endl;
    clock_t startTime = clock();
    for (int searchNum = 0; searchNum < 1000; searchNum++)
        search::findIndexOfValueUsingBinarySearch(searchNum, a, 1000);
    clock_t endTime = clock();
    double numSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;
    std::cout << "Non-recursive binary search took " << numSeconds
              << " seconds." << std::endl;
    startTime = clock();
    for (int searchNum = 0; searchNum < 1000; searchNum++)
        search::findIndexOfValueUsingSequentialSearch(searchNum, a, 1000);
    endTime = clock();
    numSeconds = (endTime - startTime) / (double) CLOCKS_PER_SEC;

    std::cout << "Sequential search took " << numSeconds
              << " seconds." << std::endl;

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
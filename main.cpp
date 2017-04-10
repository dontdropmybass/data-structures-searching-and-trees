#include <iostream>
#include "avl.h"
#include "filehandler.h"
#include "linkedlist.h"
#include "search.h"

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

    avl tree = filehandler::loadIntoAVLTree(
            "/Users/alex/repos/data-structures-searching-and-trees/dictionary.txt"
            // TODO: make this relative so it'll work everywhere
    );

    std::cout << tree << std::endl;

    linkedlist ll = filehandler::loadIntoLinkedList(
            "/Users/alex/repos/data-structures-searching-and-trees/misspelled.txt"
            // TODO: make this relative so it'll work everywhere
    );

    std::string word;
    linkedlist::Node* node = ll.head;

    std::cout << "Words that are misspelled:" << std::endl;

    while (node != NULL) {
        word = node->data;
        if (!tree.search(word)) {
            std::cout << "\t" << word << std::endl;
        }
        node = node->next;
    }

    return 0;
}
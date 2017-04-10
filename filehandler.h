//
// Created by Alexander Cochrane on 2017-04-06.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H

#include <fstream>
#include <regex>
#include <stdlib.h>
#include "avl.h"
#include "linkedlist.h"

class filehandler {
public:
    static avl loadIntoAVLTree(std::string fileName);
    static linkedlist loadIntoLinkedList(std::string fileName);
    static std::string loadIntoString(std::string fileName);
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H

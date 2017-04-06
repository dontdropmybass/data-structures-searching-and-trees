//
// Created by Alexander Cochrane on 2017-04-06.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H

#include <fstream>
#include "bst.h"

class filehandler {
public:
    auto loadIntoAVLTree(char* fileName);
    auto loadIntoString(char* fileName);
    std::istream& safeGetLine(std::istream& is, std::string& t);
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_FILEHANDLER_H

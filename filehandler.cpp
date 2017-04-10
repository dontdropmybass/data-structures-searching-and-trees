//
// Created by Alexander Cochrane on 2017-04-06.
//

#include "filehandler.h"

//filehandler open code
avl filehandler::loadIntoAVLTree(std::string fileName) {
    avl searchtree;
    std::ifstream ifs(fileName);
    if (!ifs) {
        throw std::invalid_argument("Bad file");
    }
    std::string temp;
    while (!ifs.eof()) {
        getline(ifs, temp);
        searchtree.insert(temp);
    }
    ifs.close();
    return searchtree;
}

linkedlist filehandler::loadIntoLinkedList(std::string fileName) {
    linkedlist ll;
    std::ifstream ifs(fileName);
    if (!ifs) {
        throw std::invalid_argument("Bad file");
    }
    std::string temp;
    while (!ifs.eof()) {
        temp.clear();
        ifs >> temp;
        if (std::regex_match(temp, std::regex("([a-zA-Z]+)") )) {
            ll.add(temp);
        }
    }
    ifs.close();
    return ll;
}

std::string filehandler::loadIntoString(std::string fileName) {
    std::string out = "";

    std::ifstream ifs(fileName);
    if (!ifs) {
        throw std::invalid_argument("Bad file");
    }
    std::string temp;
    while (!ifs.eof()) {
        getline(ifs, temp);
        out += temp;
    }
    ifs.close();
    return out;
}
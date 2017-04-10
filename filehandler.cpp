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
    while (!ifs.eof()) {
        std::string temp;
        std::stringstream result;
        ifs >> temp;
        std::regex nonLetterCharacters("[^a-zA-Z]");
        std::regex_replace(std::ostream_iterator<char>(result), temp.begin(), temp.end(), nonLetterCharacters, "");

        ll.add(result.str());
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
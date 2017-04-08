//
// Created by Alexander Cochrane on 2017-04-06.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_BST_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_BST_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
    std::string data;
    Node* left;
    Node* right;

    Node() : data(""), left(NULL), right(NULL) {}
};

class bst {
public:
    Node* root;
    bst() : root(NULL) {}

    void Insert(std::string num);

    bool bst::search(std::string num, Node* &node);

    void Insert(int num);

    void Insert(std::string num, Node* &node);

    void Remove(std::string num);

    void PrintTree(ostream& output, Node* &node, int indent);

    friend ostream& operator<<( ostream &output, bst &searchtree );
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_BST_H

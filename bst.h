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

    Node* Insert(std::string num);

    int calcHeight(Node* &node);

    bool search(std::string num, Node* &node);

    void singleLeftRotation(Node* &node);

    void doubleLeftRotation(Node* &node);

    void singleRightRotation(Node* &node);

    void doubleRightRotation(Node* &node);

    Node* Insert(int num);

    Node* Insert(std::string num, Node* node);

    void Remove(std::string num);

    void PrintTree(ostream& output, Node* &node, int indent);

    friend ostream& operator<<( ostream &output, bst &searchtree );
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_BST_H

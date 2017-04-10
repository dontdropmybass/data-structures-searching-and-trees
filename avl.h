//
// Created by Alexander Cochrane on 2017-04-10.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_AVL_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_AVL_H

#include <iostream>
#include <iomanip>

class avl {
public:
    struct Node // the structure for representing tree nodes
    {
        std::string data;
        int height;
        Node* left;
        Node* right;
        Node(std::string d) { data = d; left = right = 0; height = 1; }
    };

    int height(Node* p);
    int balanceFactor(Node *p);
    void fixHeight(Node *p);
    Node* rotateRight(Node *p);
    Node* rotateLeft(Node *q);
    Node* balance(Node* p);
    Node* insert(Node* p, std::string data);
    Node* insert(std::string data);
    void printTree(std::ostream& output, Node *&node, int indent);
    friend std::ostream& operator<<( std::ostream &output, avl &tree );
private:
    Node* root;
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_AVL_H

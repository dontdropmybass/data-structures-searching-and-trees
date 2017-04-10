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
        int height = 1;
        Node* left = NULL;
        Node* right = NULL;
        Node(std::string data) {
            std::transform(data.begin(), data.end(), data.begin(), ::tolower);
            this->data = data;
        }
    };

    int height(Node* p);
    int balanceFactor(Node *p);
    void fixHeight(Node *p);
    Node* rotateRight(Node *p);
    Node* rotateLeft(Node *q);
    Node* balance(Node* p);
    Node* insert(Node* p, std::string data);
    Node* insert(std::string data);
    bool search(std::string data, Node* node);
    bool search(std::string data);
    void printTree(std::ostream& output, Node *&node, int indent);
    friend std::ostream& operator<<( std::ostream &output, avl &tree );
private:
    Node* root = NULL;
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_AVL_H

//
// Created by Alexander Cochrane on 2017-04-10.
//

#ifndef DATA_STRUCTURES_SEARCHING_AND_TREES_LINKEDLIS_H
#define DATA_STRUCTURES_SEARCHING_AND_TREES_LINKEDLIS_H

#include <stdio.h>
#include <stdexcept>
#include <string>

class linkedlist {
public:
    struct Node {
        Node* next = NULL;
        std::string data;
        Node(std::string data) {
            std::transform(data.begin(), data.end(), data.begin(), ::tolower);
            this->data = data;
        }
    };
    Node* head = NULL;
    void add(std::string data);
    void insert(int position, std::string data);
    void remove(int position);
    Node* get(int position);
    int length();
};


#endif //DATA_STRUCTURES_SEARCHING_AND_TREES_LINKEDLIS_H

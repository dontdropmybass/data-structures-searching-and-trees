//
// Created by Alexander Cochrane on 2017-04-10.
//

#include "linkedlist.h"

void linkedlist::add(std::string data) {
    if (this->head==NULL) {
        this->head = new Node(data);
    }
    Node* node = this->head;
    while (node->next != NULL) {
        node = node->next;
    }
    Node* newNode = new Node(data);
    node->next = newNode;
}

void linkedlist::insert(int position, std::string data) {
    Node* node = this->head;
    while (position-- > 0) {
        if (node->next == NULL) {
            throw std::out_of_range("Index out of range.");
        }
        node = node->next;
    }
    Node* newNode = new Node(data);
    newNode->next = node->next;
    node->next = newNode;
}

void linkedlist::remove(int position) {
    Node* node = this->head;
    for (int x = 0; x < position; x++) {
        if (node->next == NULL) {
            throw std::out_of_range("Index out of range.");
        }
        node = node->next;
    }
    Node* nextNode = node->next;
    node->next = nextNode->next;
    delete nextNode;
}

linkedlist::Node* linkedlist::get(int position) {
    Node* node = head;
    while (position-->=0) {
        node = node->next;
    }
    return node;
}

int linkedlist::length() {
    int i = 0;
    if (head==NULL) return 0;
    Node* node = head;
    while (true) {
        i++;
        if (node->next==NULL) return i;
        else (node = node->next);
    }
}
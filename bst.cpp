//
// Created by Alexander Cochrane on 2017-04-06.
//

#include "bst.h"

void bst::Insert(std::string num) {
    Insert(num, root);
}

void bst::Insert(int num) {
    Insert(std::to_string(num), root);
}

int bst::calcHeight(Node* &node){
    int left, right;

    if(node==NULL)
        return 0;
    left = Height(node->left);
    right = Height(node->right);
    if(left > right)
        return left+1;
    else
        return right+1;
}

void bst::Insert(std::string num, Node* &node) {
    if (node == NULL) {
        node = new Node();
        node->data = num;
    }
    else if(num < node->data) {
        Insert( num, node->left );
    }
    else if(num > node->data) {
        Insert( num, node->right );
    }
    else {
        cout << "Node value " << node->data << " already exists.";
        cout << endl;
    }
}

bool bst::search(std::string num, Node* &node)
{
    bool isEqual;
    //if this node is null, node was not found
    if (root == 0) {
        isEqual = false;
    }

   //if the string is lower, look left
    else if (num < bst::root->data) {
        isEqual = search(root->left, num);
    }

    //else look right
    else if (num > bst::root->data) {
        isEqual = search(root->right, num);
    }

    else {
        isEqual = true;
    }
    return isEqual;
}


void bst::Remove(std::string num) {
    bool found = false;
    Node* node = root;
    Node* parent = NULL;

    while(!found && (node != NULL)) {
        if( num < node->data ) {
            parent = node;
            node = node->left;
        }
        else if(num > node->data) {
            parent = node;
            node = node->right;
        }
        else {
            found = true;
        }
    }

    if(!found) {
        return;
    }

    if((node->left != NULL) && (node->right != NULL)) {
        Node* successor = node->right;

        parent = node;
        while(successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        node->data = successor->data;
        node = successor;
    }

    Node* subtree = node->left;

    if(subtree == NULL) {
        subtree = node->right;
    }

    if(parent == NULL) {
        root = subtree;
    }
    else if(parent->left == node) {
        parent->left = subtree;
    }
    else {
        parent->right = subtree;
    }

    delete node;
}

void bst::PrintTree(ostream& output, Node* &node, int indent) {
    if(node != NULL) {
        PrintTree(output, node->right, indent + 5);

        output << setw(indent) << node->data << endl;

        PrintTree(output, node->left, indent + 5);
    }
}

void bst::singleLeftRotation(Node* &node){
    Node* rotateNode;
    rotateNode = node->left;
    node->left = rotateNode->right;
    rotateNode->right = node;
    node = rotateNode;
}


void bst::doubleLeftRotation(Node* &node){
    singleRightRotation(node->left);
    singleLeftRotation(node);
}


void bst::singleRightRotation(Node* &node){
    Node* rotateNode;
    rotateNode = node->right;
    node->right = rotateNode->left;
    rotateNode->left = node;
    node = rotateNode;
}


void bst::doubleRightRotation(Node* &node){
    singleLeftRotation(node->right);
    singleRightRotation(node);
}


ostream& operator<<( ostream &output, bst &searchtree ) {
    searchtree.PrintTree( output, searchtree.root, 0 );

    return output;
}
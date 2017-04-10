//
// Created by Alexander Cochrane on 2017-04-10.
//

#include "avl.h"

int avl::height(avl::Node *p) {
    if (p == NULL) {
        return 0;
    }
    else {
        return p->height;
    }
}

int avl::balanceFactor(avl::Node *p) {
    return height(p->right) - height(p->left);
}

void avl::fixHeight(avl::Node *p) {
    int leftHeight = height(p->left);
    int rightHeight = height(p->right);
    if (leftHeight > rightHeight) {
        p->height = leftHeight + 1;
    }
    else {
        p->height = rightHeight + 1;
    }
}

avl::Node *avl::rotateRight(avl::Node *p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

avl::Node *avl::rotateLeft(avl::Node *q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

avl::Node *avl::balance(avl::Node *p) {
    fixHeight(p);
    if(balanceFactor(p)==2 )
    {
        if(balanceFactor(p->right) < 0){
            p->right = rotateRight(p->right);
        }
        return rotateLeft(p);
    }
    if(balanceFactor(p)==-2 )
    {
        if(balanceFactor(p->left) > 0){
            p->left = rotateLeft(p->left);
        }
        return rotateRight(p);
    }
    return p; // balancing is not required
}

avl::Node *avl::insert(avl::Node *p, std::string data) {
    if (!p) {
        return new Node(data);
    }
    else if (data < p->data) {
        p->left = insert(p->left, data);
    }
    else {
        p->right = insert(p->right, data);
    }
    return balance(p);
}

avl::Node *avl::insert(std::string data) {
    root = insert(root, data);
    return root;
}

bool avl::search(std::string data, Node* node) {
    //if this Node is null, Node was not found
    if (node == NULL) {
        return false;
    }
        //if the string is lower, look left
    else if (data < node->data) {
        return search(data, node->left);
    }
        //else look right
    else if (data > node->data) {
        return search(data, node->right);
    }

    return true;
}

bool avl::search(std::string data) {
    return search(data, root);
}

void avl::printTree(std::ostream &output, Node *&node, int indent) {
    if(node != NULL) {
        printTree(output, node->right, indent + 5);
        output << std::setw(indent) << node->data << std::endl;
        printTree(output, node->left, indent + 5);
    }
}

std::ostream& operator<<(std::ostream &output, avl &tree) {
    tree.printTree(output, tree.root, 0);
    return output;
}

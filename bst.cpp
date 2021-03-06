//
// Created by Alexander Cochrane on 2017-04-06.
//

#include "bst.h"

Node* bst::insert(std::string num) {
    root = insert(num, root);
    return root;
}

Node* bst::insert(int num) {
    return insert(std::to_string(num));
}

int bst::calcHeight(Node* &node) {
    int left, right;

    if(node==NULL)
        return 0;
    left = calcHeight(node->left);
    right = calcHeight(node->right);
    if(left > right)
        return left+1;
    else
        return right+1;
}

Node* bst::insert(std::string num, Node *node) {
    if (node == NULL) {
        node = new Node();
        node->data = num;
    }
    else if(num < node->data) {
        node->left = insert(num, node->left);
    }
    else if(num > node->data) {
        node->right = insert(num, node->right);
    }
    else {
        cout << "Node value " << node->data << " already exists.";
        cout << endl;
    }

    int lefth, righth;
    lefth = calcHeight(node->left);
    righth = calcHeight(node->right);

    if (lefth < righth) {
        if (node->left != NULL && calcHeight(node->left->left) + 1 < calcHeight(node->left->right)) {
            singleLeftRotation(node);
        }
        else {
            doubleLeftRotation(node);
        }
    }
    else if (righth > lefth) {
        if (node->right != NULL && calcHeight(node->right->left) + 1< calcHeight(node->right->right)) {
            doubleLeftRotation(node);
        }
        else {
            singleLeftRotation(node);
        }
    }

    return node;
}

bool bst::search(std::string num, Node* &node) {
    //if this Node is null, Node was not found
    if (root == NULL) {
        return false;
    }

   //if the string is lower, look left
    else if (num < bst::root->data) {
        return search(num, root->left);
    }

    //else look right
    else if (num > bst::root->data) {
        return search(num, root->right);
    }

    return true;
}


void bst::remove(std::string num) {
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

void bst::printTree(ostream &output, Node *&node, int indent) {
    if(node != NULL) {
        printTree(output, node->right, indent + 5);
        output << setw(indent) << node->data << endl;
        printTree(output, node->left, indent + 5);
    }
}

void bst::singleLeftRotation(Node* &node) {
    Node* rotateNode;
	//I think I found the issue
	//pretty sure the next line should just be rotateNode = Node
	//because we pass it the Node->right in the double rotation method
	//actually we should just pass it the Node in the double rotation methods, then this would all work
	//probably.
    rotateNode = node->left;
    node->left = rotateNode->right;
    rotateNode->right = node;
    node = rotateNode;
}


void bst::doubleLeftRotation(Node* &node) {
	//trying to pass it just the Node because in the single method it gets the left Node anyways
    singleRightRotation(node);
    singleLeftRotation(node);
}


void bst::singleRightRotation(Node* &node) {
    Node* rotateNode;
	//I think I found the issue
	//pretty sure the next line should just be rotateNode = Node
	//because we pass it the Node->right in the double rotation method
	//actually we should just pass it the Node in the double rotation methods, then this would all work
	//probably.
    rotateNode = node->right;
    node->right = rotateNode->left;
    rotateNode->left = node;
    node = rotateNode;
}


void bst::doubleRightRotation(Node* &node) {
	//trying to pass it just the Node because in the single method it gets the right Node anyways
    singleLeftRotation(node);
    singleRightRotation(node);
}


ostream& operator<<(ostream &output, bst &searchtree) {
    searchtree.printTree(output, searchtree.root, 0);

    return output;
}
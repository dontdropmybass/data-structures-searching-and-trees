// SearchTree.cpp : Defines the entry point for the console application.
//
//
//  main.cpp
//  binarysearchtree
//
//  Created by Hal O'Connell on 2015-02-12.
//  Copyright (c) 2015 Hal O'Connell. All rights reserved.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>

using namespace std;

class Node;

typedef Node* NodePtr;

class Node
{
public:
    int data;
    NodePtr left;
    NodePtr right;
    
    Node() : data(0), left(NULL), right(NULL) {}
};

class BST
{
private:
    NodePtr root;
    
public:
    BST() : root(NULL) {}
    
    void Insert( int num )
    {
        Insert( num, root );
    }
    
    void Insert( int num, NodePtr &node )
    {
        if( node == NULL )
        {
            node = new Node();
            node->data = num;
        }
        else if( num < node->data )
        {
            Insert( num, node->left );
        }
        else if( num > node->data )
        {
            Insert( num, node->right );
        }
        else
        {
            cout << "Node value " << node->data << " already exists.";
            cout << endl;
        }
    }
    
    void Remove( int num )
    {
        bool found = false;
        NodePtr node = root;
        NodePtr parent = NULL;
        
        while( !found && (node != NULL) )
        {
            if( num < node->data )
            {
                parent = node;
                node = node->left;
            }
            else if( num > node->data )
            {
                parent = node;
                node = node->right;
            }
            else
            {
                found = true;
            }
        }
        
        if( !found )
        {
            return;
        }
        
        if( (node->left != NULL) && (node->right != NULL) )
        {
            NodePtr successor = node->right;
            
            parent = node;
            while( successor->left != NULL )
            {
                parent = successor;
                successor = successor->left;
            }
            
            node->data = successor->data;
            node = successor;
        }
        
        NodePtr subtree = node->left;
        
        if( subtree == NULL )
        {
            subtree = node->right;
        }
        
        if( parent == NULL )
        {
            root = subtree;
        }
        else if( parent->left == node )
        {
            parent->left = subtree;
        }
        else
        {
            parent->right = subtree;
        }
        
        delete node;
    }
    
    void PrintTree( ostream& output, NodePtr &node, int indent )
    {
        if( node != NULL )
        {
            PrintTree( output, node->right, indent + 5 );
            
            output << setw(indent) << node->data << endl;
            
            PrintTree( output, node->left, indent + 5 );
        }
    }
    
    friend ostream& operator<<( ostream &output, BST &bst );
};

ostream& operator<<( ostream &output, BST &bst )
{
    bst.PrintTree( output, bst.root, 0 );
    
    return output;
}

int main()
{
    // test 1
    BST bst;
	
    bst.Insert( 5 );
    bst.Insert( 3 );
    bst.Insert( 7 );
    bst.Insert( 2 );
	bst.Insert( 1 );
    bst.Insert( 4 );
    bst.Insert( 6 );
    bst.Insert( 8 );
	bst.Insert(10 );
    
	/*
     bst.Insert( 2 );
     bst.Insert( 3 );
     bst.Insert( 4 );
     bst.Insert( 5 );
     bst.Insert( 6 );
     bst.Insert( 7 );
     bst.Insert( 8 );
	 */
    
    
    cout << bst << endl;
	cin.ignore();

    // test 2
    cout << "\n\nTest 2\n";
    cout << "-----\n";
    
    bst.Remove( 7 );
    
    cout << bst << endl;
	cin.ignore();

	bst.Insert(7);
	cout << bst << endl;
	cin.ignore();

	bst.Insert(7);

	cout << bst << endl;

	cin.ignore();
    
    return 0;
}


















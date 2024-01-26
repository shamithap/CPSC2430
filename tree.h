// Shamitha Pichika
// tree.h
//header file for tree.cpp


#include <iostream>
using namespace std;
#ifndef TREE_H
#define TREE_H


class Tree {

private:

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root;

void insertVal(Node*& root, int val);

void postorderVal(Node* root);

void inorderVal(Node* root);

int findHeightVal(Node*& root);

bool findKeyVal(Node*& root, int val);

int countLeafVal(Node* root);

int countFullVal(Node* root);

void deleteAll(Node*& root);

void deleteTree(Node* node);

public:

Tree(); //constructor

~Tree(); //destructor

Tree(Tree const& other); //copy constructor

Tree& operator=(const Tree& other); //assignment operator for Stack

void insert(int val); //inserts keys

bool findKey(int val); //returns true if key (val) is present

int findHeight(); //finds height of tree

void postorder(); //done recursively

void inorder(); //done iteratively, use STL stack (see canas for directions)

int countLeaf(); //returns num of leaves in tree

int countFull(); //returns num of full nodes (nodes with two children)

void delNode(Node* root); //Delete single node – must work for nodes with no children, one child or two children

//void deleteAll(Node*& root);






//There will be additional private helper methods needed. The only methods that may print to the screen are the two traversals.
//Your driver should insert a minimum of 25 random* values to the tree. Test all the public methods of your class in the driver, printing the results to the screen. The user interface should clearly explain what is being tested and what results are expected.

 
};
#endif

//Shamitha Pichika
//tree.cpp
//the program below has the function bodies of the class Stack

#include "tree.h"
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

const char SPACE = ' ';


Tree::Tree() {
    root = nullptr;
}


Tree::~Tree() {
    deleteTree(root);
}

void Tree::deleteTree(Node* node) {
    if (root != nullptr){
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
  }
}

Tree::Tree(Tree const& other) {
    root = nullptr;
    if(other.root != nullptr) {
        root = new Node(*other.root);
    }
}

Tree& Tree::operator=(const Tree& other){
    if(this == &other) {
        return *this;
    }
    if(root != nullptr) {
        delete root;
    }
    root = nullptr;
    if(other.root != nullptr) {
        root = new Node(*other.root);
    }
    return *this;
}

void Tree::insertVal(Node*& root, int val) {
    if(root == nullptr) {
        root = new Node;
        root -> data = val;
        root -> left = nullptr;
        root -> right = nullptr;
        } else if(val < root -> data) {
            insertVal(root -> left, val);
        } else if(val > root -> data) {
            insertVal(root -> right, val);
        }
}

void Tree::insert(int val) {
    insertVal(root, val);
}



int Tree::findHeight() {
    return findHeightVal(root);
}

int Tree::findHeightVal(Node*& root) {
    if (root == nullptr) {
        return 0; 
    } else {
        int leftH = findHeightVal(root->left);
        int rightH = findHeightVal(root->right);
        return 1 + max(leftH, rightH); 
    }
}


void Tree::postorder() {
    postorderVal(root);
}

void Tree::postorderVal(Node* root) {
    if (root != nullptr){
    postorderVal(root->left);
    postorderVal(root->right);
    cout << root->data << SPACE;
  }
}

void Tree::inorder() {
    inorderVal(root);
}


void Tree::inorderVal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (!s.empty() || current) {
        if (current) {
            s.push(current);
            current = current->left;
        } else {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
} 

bool Tree::findKey(int val) {
    return findKeyVal(root, val);
}

bool Tree::findKeyVal(Node*& root, int val) {
    if (root == nullptr) {
        return false;
    } else if (val < root -> data) {
        return findKeyVal(root -> left, val);
    } else if (val > root -> data) {
        return findKeyVal(root -> right, val);
    } else {
        return true;
    }
}

int Tree::countLeaf() {
    return countLeafVal(root);
}

int Tree::countLeafVal(Node* root) {
    if (root == nullptr) {
        return 0;
    } else if (root -> left == nullptr && root -> right == nullptr) {
        return 1;
    } else {
        return countLeafVal(root -> left) + countLeafVal(root -> right);
    }
}
int Tree::countFull() {
    return countFullVal(root);
}

int Tree::countFullVal(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root -> left != nullptr && root -> right != nullptr) {
        count = 1;
    }
    count += countFullVal(root -> left) + countFullVal(root -> right);
    return count;

}


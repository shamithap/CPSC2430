//p3.cpp
//Shamitha Pichika
//05/02/2023

#include "tree.h"
#include <iostream>
#include <stack>
using namespace std;

const int SIZE = 26;
const int DUP_VAL = 105;
const int HEIGHT_VAL = 5;
const int FIND_KEY_VAL = 88;
const int LEAF_COUNT = 13;
const int FULL_NODE_COUNT = 12;
const int arr[SIZE] = 
{56, 36, 70, 25, 48, 63, 93, 18,
 31, 42, 52, 59, 67, 82, 102, 4,
 19, 27, 33, 50, 55, 79, 88, 96, 105, 105};


int main() 
{

Tree tree1;
Tree tree3;
cout << "\n\n";
cout << "Welcome! As you know, this uses a binary search tree and preforms " <<
  " a series of testsprogram finds prime numbers \n\n";
cout << "Testing insert...attempting to add values and duplicate " <<
 " value (" << DUP_VAL << "):\n";
for(int i = 0; i < SIZE; i++) {
    tree1.insert(arr[i]);
}
cout << "Attempting Postorder traversal...we should get: ";
cout << "4 19 18 27 33 31 25 42 50 55 52 48 36 59 67 63 79 88 82 " <<
" 96 105 102 93 70 56 ";
cout << "\nResult: ";
tree1.postorder();
cout << "\n\n";

cout << "Attempting Postorder traversal...we should get: ";
cout << "4 18 19 25 27 31 33 36 42 48 50 52 55 56 59 63 67 70 "
<< "79 82 88 93 96 102 105 ";
cout << "\nResult: ";
tree1.inorder();
cout << "\n\n";

cout << "Testing findHeight...we should get " << HEIGHT_VAL << "\n";
cout << "Result: ";
cout << tree1.findHeight();
cout << "\n\n";

cout << "Testing findKey..we will test if " << FIND_KEY_VAL << " is present\n";
cout << "If the result is 1, the value is present (which it is)\n";
cout << "Result: ";
cout << tree1.findKey(FIND_KEY_VAL);
cout << "\n\n";

cout << "Testing countLeaf..we should get " << LEAF_COUNT << " leaves total\n";
cout << "Result: ";
cout << tree1.countLeaf();
cout << "\n\n";

cout << "Testing countFull...we should get " << FULL_NODE_COUNT 
<< " nodes total\n";
cout << "Result: ";
cout << tree1.countFull();
cout << "\n\n";

cout << "The copy constructor will now be tested...\n";
Tree tree2(tree1);
cout << "\n\nCopied: ";
tree2.inorder();
cout << "\n\nOriginal: ";
tree1.inorder();
cout << "\n\n";

cout << "The assignment operator will now be tested...\n";
tree3 = tree1;
cout << "\n\nCopied: ";
tree3.inorder();
cout << "\n\nOriginal: ";
tree1.inorder();



    cout << "\n\n"; 
  cout << "This concludes all the tests";
  cout << "\n\n";
  cout << "Thanks for tuning in. Goodye!";
  cout << "\n\n\n";
    return 0;
}
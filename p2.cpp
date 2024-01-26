//Shamitha Pichika
//p2.cpp
//This program uses a stack class and a dynamic array
//to push, pop, and resize values

#include "stack.h"
#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 10; 
//array size

const int TEST_NUMS[SIZE] = {-10, 2, 77, 19, 17, 91, 3, 13, 47, 31};
//test array

const int NEW_STACK_SIZE = 4;
//new array test size

const double RESIZE_BIG = 1.5;
//resize value


int main()
{
  cout << "\n\n";
  Stack stack1;
  Stack stack2(NEW_STACK_SIZE); 
  
  cout << "Welcome TA Riley! As you know, this program finds prime numbers"
       << " from a dynamic array and resizes a Stack.\n\n";
  cout << "Testing push() and isPrime() - The following values will be"
       << " attempted to be pushed onto the stack: \n";
  
  
  for(int i = 0; i < SIZE/2; i++) {
    cout << TEST_NUMS[i] << " ";
  }
  for(int i = 0; i < SIZE/2; i++) {
    stack1.push(TEST_NUMS[i]);
  }
  
  cout << "\n\n"; 
  cout << "Press enter to continue...";
  cin.get();
  cout << "\n\n"; 
  
  cout << "Testing pop() and isEmpty()...\n";
  cout << "The following values should be popped from the stack: ";
  cout << "2, 19, 17 \n\n";
  
  cout << "Result: ";
  while(!stack1.isEmpty()) {
    cout << stack1.pop();
    cout << " ";
  }
  
  cout << "\n\n"; 
  cout << "Press enter to continue...";
  cin.get();
  cout << "\n\n"; 
  
  cout << "Now testing resize() and isFull()...\n";
  cout << "We will be using a new Stack with size " << NEW_STACK_SIZE;
  
  cout << "\n\n"; 
  cout << "The following values will be attempted"
       << " to be pushed onto the stack: \n";
  
  for(int i = 0; i < SIZE; i++) {
    cout << TEST_NUMS[i] << " ";
  }
  for(int i = 0; i < SIZE; i++) {
    stack2.push(TEST_NUMS[i]);
  }
  
  cout << "\n\n"; 
  cout << "Testing pop() and isEmpty()...\n";
  cout << "The following values should be popped from the stack: ";
  cout << "31 47 3 17 19 2 \n\n";
  
  cout << "Result: ";
  while(!stack2.isEmpty()) {
    cout << stack2.pop();
    cout << " ";
  }
  
  cout << "\n\n"; 
  cout << "Press enter to continue...";
  cin.get();
  cout << "\n\n"; 
  
  cout << "The copy constructor will now be tested...\n";
  cout << "The following values will be attempted to"
       << " be pushed onto the stack: ";
  
  for(int i = 0; i < SIZE; i++) {
    cout << TEST_NUMS[i] << " ";
  }
  for(int i = 0; i < SIZE; i++) {
    stack1.push(TEST_NUMS[i]);
  }
  
  Stack stack3(stack1);
  
  cout << "\n\nCopied: ";
  while(!stack3.isEmpty()) {
    cout << stack3.pop();
    cout << " ";
  }
  cout << "\nOriginal: ";
  while(!stack1.isEmpty()) {
    cout << stack1.pop();
    cout << " ";
  }
  
  cout << "\n\n"; 
  cout << "Press enter to continue...";
  cin.get();
  cout << "\n\n"; 
  
  
  cout << "The overloaded assignment operator will now be tested...\n";
  cout << "The following values will be attempted to be"
       << " pushed onto the stack: ";
  
  for(int i = 0; i < SIZE; i++) {
    cout << TEST_NUMS[i] << " ";
  }
  for(int i = 0; i < SIZE; i++) {
    stack1.push(TEST_NUMS[i]);
  }
  
  stack3 = stack1;
  
  cout << "\n\nCopied: ";
  while(!stack3.isEmpty()) {
    cout << stack3.pop();
    cout << " ";
  }
  cout << "\nOriginal: ";
  while(!stack1.isEmpty()) {
    cout << stack1.pop();
    cout << " ";
  }
  
  cout << "\n\n"; 
  cout << "Press enter to continue...";
  cin.get();
  cout << "\n\n"; 
  
  cout << "Trying to catch EmptyStack()...\n\n";
  
  try {
    cout << stack3.pop();
  }
  catch(Stack::EmptyStack) {
    cout << "ERROR: Cannot pop from an empty stack\n";
  }
  
  cout << "\n\n";
  cout << "This concludes all the tests";
  cout << "\n\n";
  cout << "Thanks for tuning in. Goodye!";
  cout << "\n\n\n";
  
  return 0;
  
}

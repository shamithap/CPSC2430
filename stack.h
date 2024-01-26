// Shamitha Pichika
// stack.h

#ifndef STACK_H
#define STACK_H
#include <iostream>


class Stack {
  
private:
  
  int* stackArray;
  int stackSize;
  int top;
  
  void resize();
  //resizes stack sizeto be 1.5 times greater
  
  bool isPrime(int num);
  //determines if num is prime
  
  bool isFull();
  //determines if stack is full
  
public:
  
  class EmptyStack{}; //exception class thrown
  
  explicit Stack(int size = 10); //(default constructor) 
  
  Stack(const Stack& other); //(copy constructor)
  
  ~Stack(); //(destructor)
  
  Stack& operator=(const Stack& other); //(assignment operator for Stack)
  
  
  void push(int value); 
  //- Adds the input value to the instance's collection of elements
  //value is rejected if not prime
  
  int  pop(); 
  //- Removes and returns whichever element in the stack which was most
  //recently added
  
  bool isEmpty(); //returns true if stack is empty
};
#endif

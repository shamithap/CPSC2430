// Shamitha Pichika
// stack.cpp
// the program below has the function bodies of the class Stack

#include "stack.h"
#include <iostream>
#include <cmath>
using namespace std;

const double RESIZE_BIG = 1.5;


Stack::Stack(int size) {
  stackSize = size;
  stackArray = new int[stackSize];
  top = -1;
}

Stack::Stack(Stack const &other) {
  stackSize = other.stackSize;
  stackArray = new int[stackSize];
  top = other.top;
  for(int i = 0; i < stackSize; i++) {
    stackArray[i] = other.stackArray[i];
  }
}


Stack::~Stack() {
  delete [] stackArray;
}


Stack& Stack::operator=(Stack const &other) {
  delete [] stackArray;
  stackSize = other.stackSize;
  top = other.top;
  stackArray = new int[stackSize];
  for(int i = 0; i < stackSize; i++) {
    stackArray[i] = other.stackArray[i];
  }
  
  return *this;
}


void Stack::push(int data) {
  if(isPrime(data)) {
    if(isFull()) {
      resize();
    } else {
      top++;
      stackArray[top] = data;
    }
    
  }
  
}


int Stack::pop() { 
  int val;
  if(isEmpty()) {
    throw EmptyStack();
  } else {
    val = stackArray[top];
    top--;
    return val;
  }
}

bool Stack::isEmpty() {
  return top == -1;
}

bool Stack::isFull() {
  return top == stackSize - 1;
}

void Stack::resize() {
  int newSize = stackSize * RESIZE_BIG;
  int *newArr = new int[newSize];
  for (int i = 0; i < stackSize; i++) {
    newArr[i] = stackArray[i];
  }
  delete[] stackArray;
  stackArray = newArr;
  stackSize = newSize;
}

bool Stack::isPrime(int num) {
  if(num <= 1) {
    return false;
  }
  for(int i = 2; i <= sqrt(num); i++) {
    if(num % i == 0) {
      return false;
    }
  }
  return true;
}



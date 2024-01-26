//Shamitha Pichika
//heap.h
//this is the header file for heap.cpp

#include <iostream>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

class Heap {
  
private:
  int* heapArray;
  int maxSize;
  int currentSize;
  
  void swap(int one, int two);
  void resize(); //resizes heap
  void heapifyUp(int index); //inserts element up a heap as necessary
  void heapifyDown(int index); //inserts element up a heap as necessary
  
public:
  Heap(int size = 10); //default constructor
  ~Heap(); //destructor
  Heap(const Heap& other); //copy constructor
  Heap& operator=(const Heap& other); //overloaded assignment operator
  
  void insert(int value);
  int remove();
  void flush(int value); //removes all instances of a value while maintaining
  // the heap
  bool isEmpty() const;
  
};

#endif

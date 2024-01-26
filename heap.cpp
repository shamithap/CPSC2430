//Shamitha Pichika
//heap.cpp

#include "heap.h"
#include <iostream>
using namespace std;

Heap::Heap(int size) {
  maxSize = size;
  currentSize = 0;
  heapArray = new int[maxSize];
}

Heap::~Heap() {
  delete[] heapArray;
}

void Heap::insert(int value) {
  if (currentSize == maxSize)
    resize();
  
  heapArray[currentSize] = value;
  heapifyUp(currentSize);
  currentSize++;
}

int Heap::remove() {
  if (isEmpty()) {
    return -1;
  }
  
  int root = heapArray[0];
  heapArray[0] = heapArray[currentSize - 1];
  currentSize--;
  heapifyDown(0);
  return root;
}

void Heap::flush(int value) {
  int count;
  for (count = 0; count < currentSize; count++) {
    if (heapArray[count] == value) {
      heapArray[count] = heapArray[currentSize - 1];
      currentSize--;
      heapifyDown(count);
      count--;
    }
  }
}

bool Heap::isEmpty() const {
  return (currentSize == 0);
}

void Heap::resize() {
  int* newArray = new int[maxSize * 2];
  for (int i = 0; i < currentSize; i++) {
    newArray[i] = heapArray[i];
  }
  delete[] heapArray;
  heapArray = newArray;
  maxSize *= 2;
}

void Heap::heapifyUp(int index) {
  int parent = (index - 1) / 2;
  int current = index;
  
  while (current > 0 && heapArray[current] < heapArray[parent]) {
    swap(heapArray[current], heapArray[parent]);
    current = parent;
    parent = (current - 1) / 2;
  }
}

void Heap::heapifyDown(int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  
  if (left < currentSize && heapArray[left] < heapArray[smallest])
    smallest = left;
  
  if (right < currentSize && heapArray[right] < heapArray[smallest])
    smallest = right;
  
  if (smallest != index) {
    swap(heapArray[index], heapArray[smallest]);
    heapifyDown(smallest);
  }
}

void Heap::swap(int one, int two) {
  int temp = one;
  one = two;
  two = temp;
}

Heap::Heap(const Heap& other) {
  maxSize = other.maxSize;
  currentSize = other.currentSize;
  heapArray = new int[maxSize]; 
  
  for (int i = 0; i < currentSize; i++) {
    heapArray[i] = other.heapArray[i]; 
  }
}

Heap& Heap::operator=(const Heap& other) {
  if (this == &other) {
    return *this; 
  }
  delete[] heapArray;
  maxSize = other.maxSize;
  currentSize = other.currentSize;
  heapArray = new int[maxSize];
  for (int i = 0; i < currentSize; i++) {
    heapArray[i] = other.heapArray[i];
  }
  
  return *this;
}

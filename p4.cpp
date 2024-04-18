//Shamitha Pichika
//p4.cpp
//The following program uses a Heap class and preforsm a series of tests
//including inserting, removing, and flushing values from the heap


#include <iostream>
#include <iomanip>
#include <ctime>
#include "heap.h"

using namespace std;

const int MAX = 15; //max heap size
const int FLUSH_VAL = 15; //value to flush
const int TEST_NUMS[] = {1, 15, 2, 16, 15, 2, 3, 17, 18, 15, 19, 3, 2, 3, 15};
// test array for heap

int main() {
  Heap h1;  
  srand(time(0));
  cout << "\n\n";
  
  cout << "Welcome to my amazing p4 program!\n\n";
  
  cout << "Testing inserting and resize functions...\n";
  cout << "inserting values onto heap (h1):\n\n";
  for(int i = 0; i < MAX; i++) {
    cout << "val inserted is " << TEST_NUMS[i] << "\n";
    h1.insert(TEST_NUMS[i]);
  }
  
  cout << "\n\n";
  
  cout << "Next value removed from the heap: " << h1.remove() << endl;
  
  for(int i = 0; i < MAX; i++) {
    h1.insert(TEST_NUMS[i]);
  }
  
  cout << "\nFlushing value " << FLUSH_VAL << " from the heap....\n";
  h1.flush(FLUSH_VAL);
  
  cout << "Heap after flushing: ";
  while (!h1.isEmpty()) {
    cout << h1.remove() << " ";
  }
  cout << "\nThe flushing worked. No instances of that value remain\n\n";
  
  cout << "The copy constructor will now be tested...\n";
  cout << "The following values will be attempted to"
       << " be inserted onto the heap: ";
  for(int i = 0; i < MAX; i++) {
    h1.insert(TEST_NUMS[i]);
  }
  
  Heap h2(h1);
  
  cout << "\n\nCopied: ";
  while(!h2.isEmpty()) {
    cout << h2.remove();
    cout << " ";
  }
  cout << "\nOriginal: ";
  while(!h1.isEmpty()) {
    cout << h1.remove();
    cout << " ";
  }
  
  
  cout << "\n\nThe overloaded assignment operator will now be tested...\n";
  cout << "The following values will be attempted to be"
       << " pushed onto the heap: ";
  
  for(int i = 0; i < MAX; i++) {
    h1.insert(TEST_NUMS[i]);
  }
  
  Heap h3 = h1;
  
  cout << "\n\nCopied: ";
  while(!h3.isEmpty()) {
    cout << h3.remove();
    cout << " ";
  }
  cout << "\nOriginal: ";
  while(!h1.isEmpty()) {
    cout << h1.remove();
    cout << " ";
  }
  
  
  cout << "\n\n";
  cout << "This concludes all the tests";
  cout << "\n\n";
  cout << "Thanks for tuning in. Goodye!";
  cout << "\n\n\n";
  
  
  return 0;
}

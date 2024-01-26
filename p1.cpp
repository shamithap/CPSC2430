//Shamitha Pichika
//p1.cpp
//04/12/2023
//The following program uses linked lists and functions
// to create and delete values 

#include <iostream>
#include <cstdlib> 
#include <fstream> //for rand and srand
using namespace std;


const int MIN_SIZE = 50;
const int MAX_SIZE = 80;
const int MIN_NUM = 1;
const int MAX_NUM = 1000;
const int DNE_NUM = 10000;

const string ORIGINAL_FILE = "/home/st/spichika/2430/Original.txt";
const string UPDATED_FILE = "/home/st/spichika/2430/Updated.txt";

struct Node {
  int data;
  Node* next;
};


void printList(Node* list, ofstream& outs, const string ORIGINAL_FILE); 
//traverse and print to file the values on the linked list (use ofstream)

void insert(int value, Node* &current); //inserts element onto linked list

void deleteList(Node* &current); //delete specific num from list, if it exists

void deleteOne(int num, Node* &current); //delete specific 


int main()
{
  ofstream outfile;
  srand(time(0));
  int input = 0; //stores random number for list size
  Node* head = nullptr;
  int num;
  
  cout << "\nWelcome to P1. This project uses a linked list and functions "
       << "to traverse and delete values\n\n";
  
  input = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
  
  for(int i = 0; i < input; i++) {
    num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    insert(num, head);
  }
  cout << "List created \n\n";
  
  printList(head, outfile, ORIGINAL_FILE);
  cout << "List printed in original.txt \n\n";
  
  deleteOne(1, head);
  cout << "Deleted smallest (first) element \n\n";
  
  deleteOne((input - 1), head);
  cout << "Deleted biggest (last) element \n\n";
  
  deleteOne((input - 10), head);
  cout << "Deleted middle element \n\n";
  
  deleteOne(DNE_NUM, head);
  cout << "Deleted value that does not exist \n\n";
  
  printList(head, outfile, UPDATED_FILE);
  cout << "List updated in updated.txt \n\n";
  
  deleteList(head);
  cout << "Deleted entire list \n\n";
  
  cout << "\nThanks for tuning in!\n";
  cout << "\n\n";
  return 0;
}





void printList(Node* list, ofstream& outputFile, const string ORIGINAL_FILE)
{
  outputFile.open(ORIGINAL_FILE);
  Node* nodePtr = list;
  if(!outputFile.fail()) {
    
    while(nodePtr != nullptr) {
      outputFile << nodePtr -> data << endl;
      nodePtr = nodePtr -> next;
    }
  } 
  outputFile.close();
} 



void insert(int value, Node* &current)
{
  Node* newNode = new Node;
  Node* list = current;
  newNode -> data = value;
  
  if(current == nullptr) {
    current = newNode;  
  } else if(current -> data >= value) { 
    newNode -> next = current;
    current = newNode;  
  } else {
    Node* previous = nullptr;
    while(list != nullptr && list -> data <= value) { 
      previous = list;
      list = list -> next;
    } 
    previous -> next = newNode;  
    newNode -> next = list; 
  }
  
  
} 



void deleteList(Node* &current)
{
  Node* nodePtr = current;
  Node* nextNode = nullptr;
  while(nodePtr != nullptr) {
    nextNode = nodePtr->next;
    delete nodePtr;
    nodePtr = nextNode;
  }
  
}



void deleteOne(int num, Node* &current) 
{
  Node* nodePtr = current;
  Node* previous = nullptr;
  int count = 1;
  
  while(nodePtr != nullptr && count != num) {
    previous = nodePtr;
    nodePtr = nodePtr -> next;
    count++;
  }
  if(num == 1) {
    nodePtr = current -> next;
    delete current;
    current = nodePtr;
  } else if (nodePtr != nullptr) {
    previous -> next = nodePtr -> next;
    delete nodePtr;
    nodePtr = nullptr;
  }
  
} 

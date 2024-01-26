//Shamitha Pichika
//p5.cpp
//The following program takes in a large text file
//and uses hashing to display to the user info
//about the hash table and the number of times a word
//occurs in the text file

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const string F_NAME = "/home/st/spichika/2430/ulyss12.txt";
const int TABLE_SIZE = 40000; // Size of the hash table
const int WORD_LIMT = 5; //limit to how many letters needs to be
//in a word to be considered a "word"

// Node structure for linked list
struct Node {
  string word;
  int count;
  Node* next;
};

// Hash function
int hashFunc(const string& word);

// Insert a word into the hash table
void insert(Node* table[], const string& word);

// Search for a word in the hash table and return its count
int search(Node* table[], const string& word);

//(I had to look up how to do this)
//basically treats uppercase and lowercase words as same
//and removes anyunnecessary punctuation
string preprocessWord(const string& word);

int main() {
  Node* table[TABLE_SIZE] = {}; // Initialize hash table
  ifstream infile(F_NAME);
  int collisions = 0;
  int uniqueWords = 0;
  int totalWords = 0;
  
  cout << "\n\n";
  cout << "Welcome! In this program, you will be given information about\n"
       << "my hash function and you will be able to find out how many times\n" 
       << "a word appears in Ulysses by James Joyce. Enjoy!\n";
  cout << "\n\n";
  
  if (!infile.is_open()) {
    cout << "Error opening file." << "\n";
    return 1;
  }
  
  string word;
  while (infile >> word) {
    word = preprocessWord(word);
    if (word.length() > 5) {
      insert(table, word);
    }
  }
  
  infile.close();
  
  for (int i = 0; i < TABLE_SIZE; i++) {
    Node* current = table[i];
    while (current != nullptr) {
      uniqueWords++;
      totalWords += current->count;
      if (current->count > 1) {
        collisions += current->count - 1;
      }
      current = current->next;
    }
  }
  
  double loadFactor = static_cast<double>(uniqueWords) / TABLE_SIZE;
  
  cout << "Load Factor: " << loadFactor << "\n";
  cout << "Number of Collisions: " << collisions << "\n";
  cout << "Number of Unique Words: " << uniqueWords << "\n";
  cout << "Total Number of Words: " << totalWords << "\n\n";
  
  // Interactive word search
  string searchWord;
  do {
    cout << "Enter a word (>5 letters) to search (or 'q' to quit): ";
    cin >> searchWord;
    searchWord = preprocessWord(searchWord);
    if (searchWord.length() > WORD_LIMT) {
      int count = search(table, searchWord);
      cout << "Number of occurrences: " << count << "\n";
    } else {
      cout << "Word not long enough. Try again.\n";
    }
  } while (searchWord != "q");
  
  cout << "\n\n";
  cout << "Thanks for tuning in. Goodbye!\n";
  cout << "\n\n";
  return 0;
}


int hashFunc(const string& word) {
  int sum = 0;
  for (char c : word) {
    sum += tolower(c);
  }
  return sum % TABLE_SIZE;
}


void insert(Node* table[], const string& word) {
  int index = hashFunc(word);
  
  Node* newNode = new Node;
  newNode->word = word;
  newNode->count = 1;
  newNode->next = nullptr;
  
  if (table[index] == nullptr) {
    table[index] = newNode;
  } else {
    Node* current = table[index];
    while (current->next != nullptr) {
      if (current->word == word) {
        current->count++;
        delete newNode;
        return;
      }
      current = current->next;
    }
    if (current->word == word) {
      current->count++;
      delete newNode;
      return;
    }
    current->next = newNode;
  }
}


int search(Node* table[], const string& word) {
  int index = hashFunc(word);
  
  Node* current = table[index];
  while (current != nullptr) {
    if (current->word == word) {
      return current->count;
    }
    current = current->next;
  }
  return 0;
}


string preprocessWord(const string& word) {
  string processedWord;
  for (char c : word) {
    if (isalpha(c)) {
      processedWord += tolower(c);
    }
  }
  return processedWord;
}







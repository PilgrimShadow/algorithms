/*
File: main.cpp
Auth: Jordan Dodson
Date: 4/14/16
Info: Demonstrate the functionality of the LinkedList class.
*/

// Libraries
#include "LinkedList.h"
#include <iostream>

// Using declarations
using std::cout;
using std::endl;

// Main
int main(int argc, char* argv[]) {

  LinkedList<int>  l1;  // A linked list of ints
  LinkedList<char> c1;  // A linked list of chars

  l1.push(1);
  c1.push('a');

  l1.push(2);
  c1.push('b');

  l1.push(3);
  c1.push('c');

  cout << "Head of l1: " << l1.peek() << endl;
  cout << "Head of c1: " << c1.peek() << endl << endl;

  cout << "Length of l1: " << l1.length() << endl;
  cout << "Length of c1: " << c1.length() << endl << endl;

  cout << "l1 contains 2: " << l1.contains(2)   << endl;
  cout << "c1 contains b: " << c1.contains('b') << endl << endl;

  cout << "removing head item from l1: " << l1.pop() << endl;
  cout << "removing head item from c1: " << c1.pop() << endl << endl;

  cout << "Length of l1: " << l1.length() << endl;
  cout << "Length of c1: " << c1.length() << endl << endl;

  cout << "removing 1 from l1: " << l1.remove(1)   << endl;
  cout << "removing a from c1: " << c1.remove('a') << endl << endl;

  cout << "Length of l1: " << l1.length() << endl;
  cout << "Length of c1: " << c1.length() << endl;

  return 0;
}

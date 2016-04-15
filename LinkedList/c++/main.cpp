/*
File: main.cpp
Auth: Jordan Dodson
Date: 4/14/16
Info: Demonstrate functionality of the LinkedList class.
*/

// Libraries
#include "LinkedList.h"
#include <iostream>

// Using declarations
using std::cout;
using std::endl;

// Main
int main(int argc, char* argv[]) {

  LinkedList<int>  l1;
  LinkedList<char> c1;

  l1.push(1);
  c1.push('a');

  l1.push(2);
  c1.push('b');

  l1.push(3);
  c1.push('c');

  cout << "Head of l1: " << l1.peek() << endl;
  cout << "Head of c1: " << c1.peek() << endl;

  cout << "Length of l1: " << l1.length() << endl;
  cout << "Length of c1: " << c1.length() << endl;

  cout << "l1 contains 2: " << l1.contains(2)   << endl;
  cout << "c1 contains b: " << c1.contains('b') << endl;

  return 0;
}

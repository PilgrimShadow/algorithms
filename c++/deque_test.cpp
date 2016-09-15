/*
File: main.cpp
Auth: Jordan Dodson
Date: 4/4/16
Info:
*/

#include "Deque.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

  Deque<int> d;

  d.pushLeft(1);
  d.pushRight(2);

  cout << d.peekLeft() << " " << d.peekRight() << endl;

  return 0;
}

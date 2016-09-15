/*
File: main.cpp
Auth: Jordan Dodson
Date: 4/4/16
Info: Test the Queue class
*/

#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

  Queue<int> q1;

  for (int i = 0; i < 40; i++) {
    q1.enqueue(i);
  }

  for (int i = 0; i < 20; i++) {
    cout << q1.dequeue() << " ";
  }

  for (int i = 0; i < 40; i++) {
    q1.enqueue(i);
  }

  for (int i = 0; i < 20; i++) {
    cout << q1.dequeue() << " ";
  }

  cout << endl;

  return 0;
}


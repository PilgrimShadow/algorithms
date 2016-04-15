#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, char* argv[]) {

  Stack<int> s1;
  Stack<float> s2;

  for (int i=0; i<10; i++) {
    s1.push(i);
    s2.push((float) i);
  }

  for (int i=0; i<8; i++) {
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
  }

  // Test the dynamic memory allocation
  for (int i=0; i<200; i++) {
    s1.push(i);
    s2.push((float) i);
  }

  for (int i=0; i<20; i++) {
    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
  }

  return 0;
}

int * realloc(int * old_arr, unsigned long new_size) {

  // Allocate memory for the new array
  int * new_arr = new int[new_size];

  // Copy values into the new array
  for (unsigned long i=0; i < new_size; i++) {
    new_arr[i] = old_arr[i];
  }

  // Delete the old array
  delete[] old_arr;

  return new_arr;
}

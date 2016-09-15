/*
File: AbstractStack.h
Auth: Jordan Dodson
Date: 4/23/16
Info:
*/

#ifndef _ALGORITHMS_ABSTRACT_STACK_H
#define _ALGORITHMS_ABSTRACT_STACK_H

template <typename T>
class AbstractStack {

  public:

    virtual void push(T x) = 0;

    virtual T pop() = 0;

};

#endif

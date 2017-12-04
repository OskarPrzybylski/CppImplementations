#ifndef _Stack_H
#define _Stack_H
#include <iostream>
using namespace std;

class Stack{

private:
int size;
int* data;
int top;

public:

Stack(int i=1);
void push(int value);
int pop();
void clear();
bool isEmpty();
~Stack();





};

void menu();
#endif

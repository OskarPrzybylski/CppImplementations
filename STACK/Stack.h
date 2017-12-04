#ifndef STACK_H
#define STACK_H

#include <stdbool.h>


struct Stack{

int size;
int top;
int* data;

};


struct Stack* init();
void destroy(struct Stack* k);
void push(struct Stack* k, int element);
int pop(struct Stack* k);
void clear(struct Stack* k);
bool isEmpty(struct Stack* k);
void menu();

#endif

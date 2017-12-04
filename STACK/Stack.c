#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include <assert.h>


struct Stack* init(){

struct Stack* k;
k=(struct Stack*)calloc(1,sizeof(struct Stack));
if(!k){
printf("blad alokacji");
exit(1);

}
k->data=(int*)calloc(1,sizeof(int));
if(!k->data){
printf("blad alokacji");
exit(1);
}
k->size=1;
k->top=0;
return k;
}

void destroy(struct Stack* k){
free(k->data);
free(k);

}

void push(struct Stack* k, int element){
if(k->top == k->size){
k->size=k->size * 2;
k->data = (int*)realloc(k->data,k->size*sizeof(int));

}
printf("%i\n", k->size);
printf("%i\n", k->top);
printf("HAHA \n");
k->data[k->top]=element;
k->top++;
}

int pop(struct Stack* k){
if(k->top == 0){
puts("STACK IS EMPTY \n");
destroy(k);
abort();
}
k->top--;
return k->data[k->top];

}

void clear(struct Stack* k){
k->top=0;


}
bool isEmpty(struct Stack* k){

if(k->top == 0){
return true;
}
else{
return false;
}
}

void menu(){

struct Stack *stos;
stos=init();

 	while(1){
 		puts("***Choose option***");
 		puts("1. Push");
 		puts("2. Pop");
 		puts("3. Clear");
 		puts("4. isEmpty");
 		puts("0. Exit");
 		puts("What to do: ");

 		int choose;
 		fflush(stdin);
 		if(scanf("%d", &choose) != 1){
 			puts("Error!");
 			exit(1);
 		}

 		int bufor = 0, value = 0;
 		switch(choose){
 			case 1:
 				puts("Type value to push: ");
 				if(scanf("%d", &value) != 1){
 					puts("Error!");
 					exit(1);
 				}
 				push(stos, value);
 				system("clear");
 				break;
 			case 2:
 				bufor = pop(stos);
 				system("clear");
 				printf("Value of popped element: %d\n", bufor);
 				break;
 			case 3:
 				clear(stos);
 				system("clear");
 				puts("Stack is clear!");
 				break;
 			case 4:
 				system("clear");
 				if(isEmpty(stos)){
 					puts("Stack is empty :(\n");
 				}
 				else{
 					puts("Stack is not empty :)\n");
 				}
 				break;
 			case 0:
 				destroy(stos);
 				exit(0);
 				break;
 			default:
 				system("clear");
 				puts("Wrong option!");
 				break;
 		}
 	}
}









#include <iostream>
#include "Stack.h"
using namespace std;


Stack::Stack(int i){
size = i;
top=0;
data =(int*)calloc(size,sizeof(int));
if(!data){
cout<<"MEMORY ALLOCATION ERROR!"<<endl;
abort();
}


}

void Stack::push(int value){

if(top == size){
size=2*size;
data=(int*)realloc(data,size*sizeof(int));

}

data[top]=value;
top++;

}

int Stack::pop(){

if(top==0){
cout<<"STACK IS EMPTY"<<endl;
free(data);
abort();

}
top--;
return data[top];

}

void Stack::clear(){

top=0;

}

bool Stack::isEmpty(){

if(top!=0){
return false;

}
else{
return true;
}

}

Stack::~Stack(){

free(data);

}


void menu(){
	Stack stos = Stack(); // setting up and stack with default value
	while(1){
 		cout<<"***Choose option***\n"
 			  "1. Push\n"
 			  "2. Pop\n"
 			  "3. Clear\n"
 			  "4. isEmpty\n"
 			  "0. Exit\n"
 			  "What to do: ";

 		int choose;
 		cin>>choose;

 		int bufor = 0, value = 0;
 		switch(choose){
 			case 1:
 				cout<<"Type value to push: "<<endl;
 				cin>>value;
 				stos.push(value);
 				system("clear");
 				break;
 			case 2:
 				bufor = stos.pop();
 				system("clear");
 				cout<<"Value of popped element: "<<bufor<<endl;
 				break;
 			case 3:
 				stos.clear();
 				system("clear");
 				cout<<"Stack is clear!"<<endl;
 				break;
 			case 4:
 				system("clear");
 				if(stos.isEmpty()){
 					cout<<"Stack is empty :(\n"<<endl;
 				}
 				else{
 					cout<<"Stack is not empty :)\n"<<endl;
 				}
 				break;
 			case 0:
 				exit(0);
 				break;
 			default:
 				system("clear");
 				cout<<"Wrong option!"<<endl;
 				break;
 		}
 	}
}

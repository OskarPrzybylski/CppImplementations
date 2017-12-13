#include <iostream>
#include "AssociativeArray.hpp"
#include <string>
#include <algorithm>



using std::endl;
using std::cout;


AssociativeArray::AssociativeArray(){
this->top=NULL;
}

AssociativeArray::~AssociativeArray(){
cout<<"HAHAHAHAHA"<<endl;
this->clear();
}


void AssociativeArray::clear(){
cout<<"HAHAHAHAHA"<<endl;
while(this->top){

struct Node* bufor=this->top->next;
delete this->top;
this->top=bufor;
}

}


Node* AssociativeArray::check(std::string &str){
struct Node* bufor = this->top;
changeKey(str);
while(bufor){
if(bufor->key.c_str() == str){
return bufor;
}
bufor = bufor->next;
}
return NULL;
}


void AssociativeArray::push(std::string newk, int newv){

struct Node* ncell = check(newk);


if(!ncell){
ncell= new Node(newk,newv);
ncell->next=this->top;
this->top=ncell;
}
else{
ncell->value=newv;
}
}


void AssociativeArray::print(){
struct Node* bufor;
bufor=this->top;


while(bufor){
cout<<bufor->key<<"\t"<<bufor->value<<endl;
bufor=bufor->next;
}

}


int& AssociativeArray::operator[] (std::string str){

struct Node* bufor=this->check(str);



if(bufor==NULL){
//delete bufor;
//this->clear();
throw "ElementNotFound";

}
return bufor->value;

}


void AssociativeArray2::changeKey(std::string &key){

std::transform(key.begin(),key.end(),key.begin(), ::tolower);
}




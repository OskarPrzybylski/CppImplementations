#include <iostream>
#include "complex.h"
#include <limits>
//#include <windows.h>


using std::cout;
using std::cin;
using std::endl;


int main(){
double m;
complex k(1,-2);
complex p(1,-3);
cout<<p;
int a=5;
//k-=p;
//cout<<k;
complex e= 10*k;
cout<<e;
if(p!=k){
cout<<"HAHAHA";
}
p+=k+=p;
cout<<p;
m=p.returnreal();
cout<<m;
m=p.amplitude();
cout<<m;
//m+=p;
if(m!=p){
cout<<"hehs";
}

return 0;
}

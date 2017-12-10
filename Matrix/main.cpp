#include <iostream>
#include "matrix.h"


using namespace std;


int main(){
gMatrix m1(2,2);
gMatrix m2(2,2);
gMatrix m4("plik1.txt");
cout<< m4 <<endl;
m4.transpose();

cout<< m4 <<endl;

return 0;
}


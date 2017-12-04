#include <iostream>
#include "matrix.h"


using namespace std;


int main(){
gMatrix m1(2,2);
gMatrix m2(2,2);
gMatrix m4("plik1.txt");
m2(1,1) = 5;
cout<< m2(1,1) <<endl;
return 0;
}


#include <iostream>
#include "matrix.h"


using namespace std;


int main(){
gMatrix m1(2,2);
gMatrix m2(2,2);
gMatrix m3("plik3.txt");
gMatrix m4("plik1.txt");
gMatrix m5("plik2.txt");

gMatrix m6 =m4 + m5;
cout<< "m6=m4+m5 \t " << m6 <<endl;

m6=m5-m4;
cout<< "m6=m4-m5 \t " << m6 <<endl;

m6-=m5;
cout<< "m6-=m5 \t " << m6 <<endl;

m6+=m5;
cout<< "m6+=m5 \t " << m6 <<endl;

gMatrix m7= m3*m4;
cout<< "m7=m3*m4 \t " << m7 <<endl;

m3*=m4;
cout<< "m3*=m4 \t " << m3 <<endl;
cout<< m4(0,0) <<endl;
if(m4(0,0)==1){
cout<< "widzisz ten komunikat poniewaz element macierz m4(0,0) jest rowny 1" <<endl;
}

cout<<"licznik referencji m4: " << m4.getRc() <<endl; 
gMatrix m10=m4;
cout<<"licznik referencji m4 po zmianie: " << m4.getRc() <<endl; 

cout<< "Macierz m4 przed transpozycja" << m4 <<endl;
m4.transpose();

cout<< "Macierz m4 po transpozycji" << m4 <<endl;

return 0;
}


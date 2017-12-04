#include <iostream>
#include "complex.h"
#include <math.h>

using std::cout;
using std::cin;
using std::endl;


complex::complex(double r, double i){
real=r;
img=i;

}

complex::complex(int r){
real=r;
img=0;


}

complex&  complex::operator= (const complex& a){
this->real=a.real;
this->img=a.img;
return *this;



}
complex complex::operator+ (const complex& a){

return complex(this->real + a.real, this->img + a.img);
}

std::ostream& operator<<(std::ostream &out, const complex &a){


if(a.img < 0){

return out<<a.real<<a.img<<a.k;
}
if(a.img == 0){
return out<<a.real;

}
else{
return out<<a.real<<"+"<<a.img<<a.k;

}
}

complex& complex::operator+= (const complex &a){
*this = *this + a;
return *this;
}

complex complex::operator- (const complex &a){

return complex(this->real - a.real, this->img - a.img);
}


complex& complex::operator-= (const complex &a){

*this = *this - a;
return *this;
}

complex complex::operator* (const complex &a){
return complex(this->real * a.real - this->img * a.img, this->real * a.img + this->img * a.real);
}

complex& complex::operator*= (const complex &a){

*this = *this * a;
return *this;

}


complex complex::operator/ (const complex &a){

return complex((this->real * a.real + this->img * a.img) / (a.real * a.real + a.img * a.img), (this->img * a.real - this->real * a.img) / (a.real * a.real + a.img * a.img) );
}

complex& complex::operator/= (const complex &a){
*this = *this * a;
return *this;
}

bool complex::operator== (const complex &a){

if(this->real==a.real && this->img==a.img) {return true;}
return false;


}
bool complex::operator!= (const complex &a){

if(this->real!=a.real || this->img!=a.img) {return true;}
return false;


}
complex operator+ (const double v, const complex &a){
return complex(v+a.real,a.img);

}
//complex operator+ (const complex &a, const double v){
//return complex(v+a.real,a.img);

//}

complex operator- (const double v, const complex &a){
return complex(v-a.real,-a.img);

}

complex operator* (const double v, const complex &a){
return complex(v*a.real,v*a.img);

}
complex operator/ (const double v, const complex &a){
return complex((v * a.real) / (a.real * a.real + a.img * a.img), (-v * a.img) / (a.real * a.real + a.img * a.img) );

}

double complex::returnreal(){

return this->real;
}

double complex::returnimg(){
return this->img;
}

//complex& operator+= (const double b){
//*this=*this+b;
//return *this;
//}

double complex::amplitude(){

return sqrt(this->real * this->real + this->img * this->img);
}

double complex::phase(){

return atan(this->img / this->real) * 180 / M_PI;
}

bool operator== (const double b, const complex &a){
if(a.img!=0){ return false; }
if(b == a.real) { return true; }
return false;

}
bool operator!= (const double b, const complex &a){
if(a.img!=0){ return true; }
if(b == a.real) { return false; }
return true;

}

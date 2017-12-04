#include <iostream>

class complex{
private:
double real;
double img;
const char k='i';

public:
complex(double r, double i);
complex(int r);

complex& operator= (const complex &a);
complex operator+ (const complex &a);
complex& operator+= (const complex &a);
complex operator- (const complex &a);
complex& operator-= (const complex &a);
complex operator* (const complex &a);
complex& operator*= (const complex &a);
complex operator/ (const complex &a);
complex& operator/= (const complex &a);
bool operator== (const complex &a);
bool operator!= (const complex &a);

friend std::ostream& operator<<(std::ostream &out, const complex &a);
friend complex operator+ (const double b, const complex &a);
//friend complex operator+ (const complex &a, const double b);
friend complex operator- (const double b, const complex &a);
friend complex operator* (const double b, const complex &a);
friend complex operator/ (const double b,const complex &a);
//friend double& operator+= (const double b);
friend bool operator== (const double b, const complex &a);
friend bool operator!= ( const double b, const complex &a);
double returnreal();
double returnimg();
double amplitude();
double phase();
};

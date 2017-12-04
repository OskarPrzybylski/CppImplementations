#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>


using namespace std;

class gMatrix{
class Matrix;
Matrix *matrix;

public:
//exceptions
class outofrange{};
class InequalSize{};
class ZeroSize{};
class FilestreamOpeningError{};
//referenced elementofmatrix
class Cref;

//constructors
gMatrix(unsigned int row, unsigned int column);
gMatrix(const gMatrix &m);
gMatrix(const char* filename);
gMatrix();
//destructor
~gMatrix();

//operators gMatrix
gMatrix& operator=(const gMatrix &m);

gMatrix operator+(const gMatrix &m)const;
gMatrix& operator+=(const gMatrix &m);

gMatrix operator-(const gMatrix &m)const;
gMatrix& operator-=(const gMatrix &m);

gMatrix operator*(const gMatrix &m)const;
gMatrix& operator*=(const gMatrix &m);

bool operator==(const gMatrix &m);

friend ostream& operator<<(ostream& s, const gMatrix &m);


//helpful methods
void check(unsigned int row, unsigned int column) const;
double read(unsigned int row, unsigned int column)const;
void write(unsigned int row, unsigned int column, double element);


//operator ()
double operator()(unsigned int row, unsigned int column) const;
Cref operator()(unsigned int row, unsigned int column);

//get number of references
int getRc();
//convert [][] to []
unsigned int index(const unsigned int row, const unsigned int column)const;



};

class gMatrix::Matrix{

friend class gMatrix;
double *data;
int rows;
int columns;
//numberofreferences
int rc;

public:
//constructors;
Matrix(unsigned int row, unsigned int column);
Matrix(const Matrix &m);
Matrix(const char* filename);
Matrix();

//destructor
~Matrix();

Matrix* detach();
void assign(const int rows, const int columns, double *ndata);

//operatorsformatrix
Matrix& operator=(const Matrix &m);
bool operator==(const Matrix &m);


friend ostream& operator<<(ostream& s, const gMatrix &m);




};


class gMatrix::Cref{

friend class gMatrix;
gMatrix &m;
int row;
int col;

//constructor
Cref(gMatrix &mm, unsigned int rr, unsigned int cc);

public:
operator double() const;
gMatrix::Cref& operator=(double d);
gMatrix::Cref& operator=(const Cref& ref);
};









#endif 

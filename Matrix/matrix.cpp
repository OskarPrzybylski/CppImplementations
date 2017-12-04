#include <iostream>
#include <fstream>
#include <new>
#include "matrix.h"




using namespace std;


gMatrix::Matrix::Matrix(unsigned int row, unsigned int column){

	if(row>0 && column>0){
	
		this->rows = row;
		this->columns = column;
		try{
		this->data = new double [rows*columns];

		}
		catch(bad_alloc &ba){
			cout << "Exception caught:" << ba.what()<<endl;
		}
		for(int i=0;i<rows*columns;i++){
			this->data[i]=0;
		}
		rc=1;
	}
	else throw ZeroSize();
}

gMatrix::Matrix::Matrix(){
	this->rows=1;
	this->columns=1;
	try{
		this->data= new double[1];
	}
	catch(bad_alloc &ba){
		cout<<"Exception caught:" << ba.what()<<endl;
	}
	rc=1;
	this->data[0]=0;
}


gMatrix::Matrix::Matrix(const char* filename){

	ifstream s(filename);
	if(!s){ throw FilestreamOpeningError(); }
	s >> rows;
	s >> columns;
	try{
	data = new double[rows*columns];
	} 
	catch(bad_alloc &ba){
			cout << "Exception caught: " << ba.what()<< endl;
		}
	for(int i=0; i < this->rows*columns; i++){
		s >> this->data[i];	
	}
	rc=1;
	s.close();

}

gMatrix::Matrix::Matrix(const Matrix &m){

	this->rows=m.rows;
	this->columns=m.columns;
	try{
		this->data= new double[rows*columns];

	}
	catch(bad_alloc *ba){
		cout<<"Exception caught: " << ba->what()<< endl;
	}
	for(int i=0;i<rows*columns;i++){
		this->data[i]=m.data[i];
	}
	rc=1;
}

gMatrix::Matrix::~Matrix(){
	delete[] this->data;
}

gMatrix::Matrix* gMatrix::Matrix::detach(){
	if(rc==1) return this;
	Matrix* m = new Matrix(*this);
	rc--;
	return m;

}

void gMatrix::Matrix::assign(const int nrows, const int ncolumns, double *ndata){
	if(rows!=nrows || columns!=ncolumns){
		double *newData = NULL;
		try{
			newData=new double[nrows*ncolumns];
		}
		catch(bad_alloc &ba){
		cout << "Exception caught: " << ba.what()<<endl;
		}
		rows = nrows;
		columns=ncolumns;
		for(int i=0;i<rows*columns;i++){
		newData[i]=ndata[i];
			}
		delete[] data;
		data = newData;
	}
	else{
		for(int i=0;i<rows*columns;i++){
			data[i]=ndata[i];
		}
	}

}
gMatrix::Cref::Cref(gMatrix& mm, unsigned int rr, unsigned int cc): m(mm), row(rr), col(cc){}

gMatrix::Cref::operator double() const{
return m.read(row,col);
}

gMatrix::Cref& gMatrix::Cref::operator=(double d){
	m.write(row,col,d);
	return *this;
}
gMatrix::Cref& gMatrix::Cref::operator=(const gMatrix::Cref& ref){
	return operator=(ref);
}


//gmatrix operators and methods


gMatrix::gMatrix(unsigned int row, unsigned int column){
	matrix = new Matrix(row,column);
}

gMatrix::gMatrix(const gMatrix &m){
	m.matrix->rc++;
	matrix=m.matrix;
}

gMatrix::gMatrix(const char* filename){
	matrix=new Matrix(filename);

}

gMatrix::gMatrix(){
	matrix= new Matrix();
}

gMatrix::~gMatrix(){
	if(--matrix->rc==0) delete matrix;
}


gMatrix& gMatrix::operator=(const gMatrix& m){
	m.matrix->rc++;
	if(--matrix->rc==0) delete matrix;
	matrix=m.matrix;
	return *this;

}



bool gMatrix::operator==(const gMatrix &m){
	if(this->matrix==m.matrix) return true;
	else return false;

}

ostream & operator <<(ostream & s, const gMatrix &m){
s << endl;
	for(int i=0; i < m.matrix->rows*m.matrix->columns; i++){
		s << m.matrix-> data[i] << "\t" ;
		if((i % m.matrix->columns) == (m.matrix->columns-1)) s << endl;
	}
	return s; 


}

gMatrix gMatrix::operator+(const gMatrix &m)const{
if(this->matrix->rows!=m.matrix->rows && this->matrix->columns!=m.matrix->columns){
		throw InequalSize();
		}
	gMatrix mat(this->matrix->rows, this->matrix->columns);
		for(int i=0; i < mat.matrix->rows*mat.matrix->columns; i++){
			mat.matrix->data[i] = this->matrix->data[i] + m.matrix->data[i];
		}
	return mat;


}

gMatrix& gMatrix::operator+=(const gMatrix &m){

Matrix *mat = new Matrix(this->matrix->rows, this->matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this + m;
	return *this;

}

gMatrix gMatrix::operator-(const gMatrix &m)const{

if(this->matrix->rows!=m.matrix->rows && this->matrix->columns!=m.matrix->columns){
		throw InequalSize();
		}
	gMatrix mat(this->matrix->rows, this->matrix->columns);
		for(int i=0; i < mat.matrix->rows*mat.matrix->columns; i++){
			mat.matrix->data[i] = this->matrix->data[i] - m.matrix->data[i];
		}
	return mat;

}

gMatrix& gMatrix::operator-=(const gMatrix &m){

Matrix *mat = new Matrix(this->matrix->rows, this->matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this - m;
	return *this;

}

gMatrix gMatrix::operator*(const gMatrix &m)const{
if(this->matrix->columns!=m.matrix->rows){
		throw InequalSize();
	}
	
	gMatrix mat(this->matrix->rows, m.matrix->columns);
		for(int r=0; r < mat.matrix->rows; r++){
			for(int c=0; c < mat.matrix->columns; c++){
				int sum=0;
				for(int k=0; k < this->matrix->columns; k++){
					sum += this->matrix->data[this->index(r,k)] * m.matrix->data[m.index(k,c)];
				}
				mat.matrix->data[mat.index(r,c)]=sum;		
			}
		}
	return mat;
}

gMatrix& gMatrix::operator*=(const gMatrix &m){

Matrix *mat = new Matrix(this->matrix->rows, m.matrix->columns);
	mat->assign(this->matrix->rows, this->matrix->columns, this->matrix->data);
	if(--matrix->rc == 0) delete this->matrix;	
	this->matrix = mat;
	*this = *this * m;
	return *this;



}


void gMatrix::check(unsigned int row, unsigned int column)const{
if((matrix->rows*matrix->columns)<=(int)index(row, column)) throw outofrange();

}

double gMatrix::read(unsigned int row, unsigned int column)const{
return matrix->data[index(row, column)];
}

void gMatrix::write(unsigned int row, unsigned int column, double d){
matrix = matrix->detach();
	matrix->data[index(row, column)] = d;
}


double gMatrix::operator()(unsigned int row, unsigned int column)const{

	try{
	check(row, column);
	}
	catch(outofrange &r){
		cout << "Exception caught: index out of range"<< endl;
	}
	return matrix->data[index(row, column)];
}


gMatrix::Cref gMatrix::operator()(unsigned int row, unsigned int column){
	try{
	check(row, column);
	}
	catch(outofrange &r){
		cout << "Exception caught: index out of range"<< endl;
	}
	return Cref(*this, row, column);

}

int gMatrix::getRc(){
return gMatrix::matrix->rc;

}


bool gMatrix::Matrix::operator==(const Matrix &m){

if(this->rows != m.rows || this->columns != m.columns) return false;
	bool equal = true;
	for(int i=0; i < this->rows*this->columns; i++){
		if(this->data[i] != m.data[i]){
			equal=false;
			break;
		}	
	}
	return equal;
}

unsigned int gMatrix::index(const unsigned int row, const unsigned int column)const{

return matrix->columns*row+column;	
}


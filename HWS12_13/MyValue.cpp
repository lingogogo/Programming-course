#include "MyValue.h"
#include "MyMatrix.h"
#include <iostream>

using std::cout;
using std::endl;
//constructor
MyValue::MyValue(MyMatrix* mat,unsigned int rows, unsigned int col)
{
	row = rows;
	column = col;
	matrix = mat;
}
//copy constructor
MyValue::MyValue(const MyValue& mat)
{
	row = mat.row;
	column = mat.column;
	matrix = mat.matrix;
}

MyValue::~MyValue()
{
}
//use const to prevent user change data
float MyValue::the_value() const
{
	return matrix->get_value(row, column);
}
//use const to prevent user modify data
void MyValue::output() const
{
	cout << "row : " << row + 1 << endl 
		 << "column : " << column + 1<< endl
		 << "Matrix address : " << matrix << endl;
}
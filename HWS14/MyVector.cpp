#include "MyVector.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::sqrt;
//default constructor
MyVector::MyVector()
{
	vector = new float[3];
}
//constructor:3 input argument
MyVector::MyVector(float a, float b, float c)
{
	vector = new float[3];
	vector[0] = a;
	vector[1] = b;
	vector[2] = c;
}
//copy construtor
MyVector::MyVector(const MyVector& vec)
{
	vector = new float[3];
	vector[0] = vec.vector[0];
	vector[1] = vec.vector[1];
	vector[2] = vec.vector[2];
}
//destrutor
MyVector::~MyVector()
{
	delete[] vector;
	
}
//operator=
MyVector& MyVector::operator=(const MyVector& vec)
{
	vector[0] = vec.vector[0];
	vector[1] = vec.vector[1];
	vector[2] = vec.vector[2];
	return *this;
}
//operator+
MyVector MyVector::operator+(const MyVector& vec)
{
	MyVector(result);
	result.vector[0] = vector[0] + vec.vector[0];
	result.vector[1] = vector[1] + vec.vector[1];
	result.vector[2] = vector[2] + vec.vector[2];
	return result;
}
//operator+=
MyVector& MyVector::operator+=(const MyVector& vec)
{
	vector[0] = vector[0] + vec.vector[0];
	vector[1] = vector[1] + vec.vector[1];
	vector[2] = vector[2] + vec.vector[2];
	return *this;
}
//operator-(binary operator)
MyVector MyVector::operator-(const MyVector& vec)
{
	MyVector result;
	result.vector[0] = vector[0] - vec.vector[0];
	result.vector[1] = vector[1] - vec.vector[1];
	result.vector[2] = vector[2] - vec.vector[2];
	return result;
}
//operator*
float MyVector::operator*(const MyVector& vec) const
{
	float tot = 0;
	tot = vector[0] * vec.vector[0] + vector[1] * vec.vector[1] + vector[2] * vec.vector[2];
	return tot;
}
//operator/
MyVector MyVector::operator/(float a)
{
	MyVector(result);
	result.vector[0] = vector[0] / a;
	result.vector[1] = vector[1] / a;
	result.vector[2] = vector[2] / a;
	
	return result;
}
//operator>
bool MyVector::operator>(const MyVector& vec) const
{
	
	return this->length() > vec.length() ? true : false;
}
//length():get vector length
float MyVector::length() const
{
	float tota;
	tota = (*this)*(*this);
	tota = sqrt(tota);
	return tota;
}
//operator-(unary operator)
MyVector MyVector::operator-()
{
	MyVector(result);
	result.vector[0] = -vector[0];
	result.vector[1] = -vector[1];
	result.vector[2] = -vector[2];
	return result;
}
//operator<<(using friend)
std::ostream& operator<<(std::ostream& s,const MyVector& vec)
{
	s << vec[0] << " " << vec[1] << " " << vec[2] << endl;
	return s;
}
//operator[]
float MyVector::operator[](int a) const
{
	return vector[a];
}
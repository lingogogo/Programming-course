#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

class MyVector
{
private:
	float* vector;
public:
	MyVector();														//default constructor
	MyVector(float, float, float);									//constructor:3 input argument
	MyVector(const MyVector&);										//copy construtor
	~MyVector();													//destrutor
	MyVector& operator=(const MyVector&);							//operator=
	float operator[](int) const;									//operator[]
	MyVector operator+(const MyVector&);							//operator+
	MyVector& operator+=(const MyVector&);							//operator+=
	MyVector operator-(const MyVector&);							//operator-(binary operator)
	float operator*(const MyVector&) const;							//operator*
	MyVector operator/(float);										//operator/
	bool operator>(const MyVector&) const;							//operator>
	friend std::ostream& operator<<(std::ostream&,const MyVector&);	//operator<<(using friend)
	MyVector operator-();											//destrutor
	float length() const;											//length():get vector length
};

#endif MYVECTOR_H

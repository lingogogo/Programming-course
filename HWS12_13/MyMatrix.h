#ifndef MyMatrix_H
#define MyMatrix_H
class MyValue;
class MyMatrix
{
private:
	float **matrix;
	unsigned int rows;
	unsigned int columns;
	static int matrixCount;
public:
	MyMatrix();//default constructor
	MyMatrix(unsigned int, unsigned int);//two input constructor
	MyMatrix(const MyMatrix&);//copy construction
	~MyMatrix();//destructor
	void output() const;//output function
	float get_value(unsigned int, unsigned int) const;//get data from private member
	MyMatrix kronecker_product(const MyMatrix&);//kronecker_product
	static int getmatirxCount();//take static int matrixCount
	MyValue get_minimum();//take the minimun number
};
#endif MyMatrix_H

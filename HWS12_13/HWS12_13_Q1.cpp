/*
********************************************************************************************************************************
##���v�Ҧ� �T���ŧ ���Ӥ��|�Q�ۼo���j�ǥͪ��{���a##
�ɮצW��:HW112_13_Q1.cpp
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:�H����ܦ�P�C��2~6���x�}�A���@�w����x�}�A�ñN�䤺�����ȳ]�w�b-11.8�P5.1�����A�åB��kronecker product�A����ܥX�o
�T�ӯx�}���ˤl�A�m�ߨϥ�class���覡�A�åB�b�A���a��[�Wconst�Ӵ�ָ�ƳQ�զۧ�ʪ����|�A�۹�󵲺cstruct�A��`�Q�ϥΡA�B�ϥ��F���׸����C
********************************************************************************************************************************
*/

#include "MyMatrix.h"
#include "MyValue.h"
#include <iostream>
#include <iomanip>
int MyMatrix::matrixCount = 0;
using std::cout;
using std::endl;
//random number 2 to 6 for matrix size
inline int random_matrix()
{
	return 2 + 4 * rand() / RAND_MAX;
}

int main()
{
	
	srand(static_cast<unsigned int>(time(NULL)));
	//call constructor
	MyMatrix matA(random_matrix(),random_matrix());
	MyMatrix matB(random_matrix(), random_matrix());
	
	MyValue minA,minB,min_kron;
	//using MyMatrix output to show the data
	cout << "mat A ";
	matA.output();
	cout << "mat B ";
	matB.output();
	//using kronecker product to get the result and copy constructor to MyMatrix result
	//output result(kronecker_product data)
	MyMatrix result = matB.kronecker_product(matA);
	cout << "mat kron ";
	result.output();
	//using MyMatrix get_minimun to take the smallest data
	minA = matA.get_minimum();
	minB = matB.get_minimum();
	min_kron = result.get_minimum();

	cout << endl;
	//MyValue output data
	minA.output();
	cout << "minimun data : " << minA.the_value() << endl;
	cout << endl;
	minB.output();
	cout << "minimun data : " << minB.the_value() << endl;
	cout << endl;
	min_kron.output();
	cout << "minimun data : " << min_kron.the_value() << endl;
	//show how many MyMatrix constructor used
	cout << "static count : " << MyMatrix::getmatirxCount() << endl;
	return 0;
}
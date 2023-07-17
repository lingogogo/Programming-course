/*
********************************************************************************************************************************
##版權所有 禁止抄襲 應該不會想抄廢物大學生的程式吧##
檔案名稱:HW112_13_Q1.cpp
系級:111
姓名:林學謙
學號:E14073043
program target:隨機顯示行與列為2~6的矩陣，不一定為方矩陣，並將其內部的值設定在-11.8與5.1之間，並且做kronecker product，並顯示出這
三個矩陣的樣子，練習使用class的方式，並且在適當的地方加上const來減少資料被擅自更動的機會，相對於結構struct，更常被使用，且使用靈活度較高。
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
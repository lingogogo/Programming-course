/*
********************************************************************************************************************************
##版權所有 禁止抄襲 應該不會想抄廢物大學生的程式吧##
檔案名稱:HWS14.cpp
系級:111
姓名:林學謙
學號:E14073043
program target:練習使用operator，並且使用所以有建立的功能，並且加上註記以便於複習
********************************************************************************************************************************
*/
#include "MyVector.h"
using std::cout;
using std::endl;
int main()
{
	//setup all MyVector
	MyVector a(2.4f, 3.6f, 5.0f);
	MyVector b(2.0f, 6.0f, 5.0f);
	MyVector c;
	MyVector d(a);
	MyVector tot;
	//test operator=
	c = a;
	cout << "operator= c=a = " << c;
	//test operator+
	tot = a + b;
	//test operator<<
	cout << "operator a+b = "<< tot;
	//test operator+=
	c += b;
	//test operator<<
	cout << "operator c+=b = " <<c;
	//test operator-
	tot = a - b;
	//test operator<<
	cout << "operator- a-b="<<tot;
	//test operator> and length()
	if (a > b)
		cout << "a's length "<< a.length() << " is bigger than b's length "<< b.length() << endl;
	else
		cout << "b's length " << b.length() << " is bigger than a's length " << a.length() << endl;
	//test operator* inner product
	cout << "inner product a and b = " << a * b <<endl;
	//test operator/ and operator<<
	cout << "operator/ = " << a / 2 ;
	//test unary minus operator and operator<<
	cout << "-a = " << -a;
	//test subscript operator
	cout << "a[0] = " << a[0] << " a[1] = " << a[1] << " a[2] = " << a[2] << endl;
	//test copy constructor and operator<<
	cout << "copy constructor d = " << d;

	return 0;
}
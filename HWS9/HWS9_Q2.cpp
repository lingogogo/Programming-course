#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

double plus(double, double);
int plus(int, int);
string plus(string,string);
char* plus(const char*&, const char*&);

int main()
{
	const char* s1 = "aaa";
	const char* s2 = "bbb";

	int n = plus(3, 4);
	double d = plus(3.2, 4.2);
	string s = plus("he", "llo");
	char* s3 = plus(s1, s2);

	cout << "\nint : " << n << endl;
	cout << "double : " << d << endl;
	cout << "string : " << s << endl;
	cout << "char* : " << s3 << endl;

	delete[] s3;
	system("pause");
	return 0;
}
int plus(int a, int b)
{
	cout << "int" << endl;
	return a + b;
}
double plus(double a, double b)
{
	cout << "double" << endl;
	return a + b;
}
string plus(string a,string b)
{
	cout << "string" << endl;
	string c = a + b;
	return c;
}
char* plus(const char*& a, const char*& b)//如果不使用參照 這邊會使得string吃到const char*
{
	cout << "char*" << endl;
	unsigned int count = strlen(b) + strlen(a);
	char* tot = new char[count + 1];
	for (unsigned int i = 0; i < strlen(a); i++)
	{
		*(tot + i) = *(a + i);
	}
	for (unsigned int i = 0; i < strlen(b); i++)
	{
		*(tot + i + strlen(a)) = *(b + i);
	}
	tot[count] = '\0';
	return tot;
}
//請問常數會有位址嗎?
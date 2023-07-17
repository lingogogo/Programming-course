#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


template <class T> T plus(T, T);
template <>const char* plus(const char*, const char*);
template <> string plus(string, string);

int main()
{
	const char* s1 = "aaa";
	const char* s2 = "bbb";

	int n = plus(3, 4);
	double d = plus(3.2, 4.2);
	string s = plus<string>("he", "llo");
	const char* s3 = plus<const char*>(s1, s2);

	cout << "\nint : " << n << endl;
	cout << "double : " << d << endl;
	cout << "string : " << s << endl;
	cout << "char* : " << s3 << endl;

	delete[] s3;
	system("pause");
	return 0;
}
template <class T> T plus(T a, T b)
{
	cout << "template double and int" << endl;
	return a + b;
}

template <> string plus(string a, string b)
{
	cout << "template string" << endl;
	return a + b;
}

template <> const char* plus(const char*a,const char* b)
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
	const char* tot_f = tot;
	return tot_f;
}


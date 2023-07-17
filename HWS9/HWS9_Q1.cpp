#include <iostream>

using namespace std;

template <class T > T maxn(T [] , const int);
template <> const char* maxn(const char* [], const int); 

int main() 
{
	double db[10] = { 1,2,3,4,5,6,7,10,9,8 };
	int i[7] = { 1,2,3,7,5,6,5 };
	const char* input[4] = { "Lebron James" , "Kevin Durant" , "Steven Currys", "James Harden" };
	cout << maxn(input, 4) << endl;
	cout << "Dobule maximun : " << maxn(db, 10) << " " << "\nInt maximun : " << maxn(i, 7) << endl;
	system("pause");
	return 0;
}
template <class T> T maxn(T array[], const int count)
{
	T max = array[0];
	for (int i = 0; i < count; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}
template <> const char* maxn(const char* arr[] ,const int count)
{
	int* count_c = new int[count];
	int j = 0, max_n = 0;
	for (int i = 0; i < count; i++)
	{
		while (true) {
			if (static_cast<int>(toupper(arr[i][j])) < 91 && static_cast<int>(toupper(arr[i][j])) > 64) {
				count_c[i] = count_c[i] + 1;
			}
			if (arr[i][j] == NULL)
			{
				j = 0;
				break;
			}
			j++;
		}
	}
	int max = count_c[0];
	
	for (int i = 0; i < count; i++)
	{
		if (count_c[i] > max)
		{
			max = count_c[i];
			max_n = i;
		}
	}
	delete[] count_c;
	return arr[max_n];
}
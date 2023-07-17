/*
檔案名稱:question1.cpp
系級:111
姓名:林學謙
學號:E14073043
program target:輸入2個數字，可以列出並計算出所有的質數，並且透過兩個數字之間的質數互相相加並顯示
並且加入防呆機制，禁止使用者輸入負數與字元。
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int G_data1 = 0, tem_data = 0, G_data2 = 0;

	int check = 0;
	int sum = 0;

	cout << "Please key in two integer :" << endl;

	cin >> G_data1 >> G_data2;

	if (G_data1 < 0 || G_data2 < 0)
	{
		cout << "wrong key-in ,terminate" << endl;
		return 0;
	}
	else if (cin.fail() == 1)
	{
		cout << "wrong key-in ,terminate" << endl;
		return 0;
	}

	//G_data2 must be larger than G_data1.
	if (G_data1 > G_data2) {
		tem_data = G_data2;
		G_data2 = G_data1;
		G_data1 = tem_data;
	}

	//使用sqrt去優化計算過程
	for (int i = G_data1; i <= G_data2; i++)
	{
		tem_data = static_cast<int>(sqrt(i));

		//這一段無法處理小於2的值，又此種情況只有發生在最小輸入值與最大輸入值之間的範圍有包含到2跟3
		//所以在最外圈另外做處理
		for (int k = 2; k <= tem_data; k++)
		{
			check = i % k;
			//表示除的進，必定不是質數
			if (check == 0)
			{
				break;
			}
		}

		if (check != 0)
		{
			//cout << i << endl;
			sum += i;
		}
	}

	//deal with the 2 and 3 各類情況 G_data1 must be smaller than G_data2
	if (G_data1 == 3 && G_data2 >= 3)
	{
		sum += 3;
	}
	else if (G_data1 <= 2 && G_data2 > 2)
	{
		sum += 5;
	}
	else if (G_data1 <= 2 && G_data2 == 2)
	{
		sum += 2;
	}
	
	cout << "The sum of all prime number between two integer : " << sum << endl;
	system("pause");
	return 0;
}
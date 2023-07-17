/*
##版權所有 禁止抄襲##

檔案名稱:HWS6-Q1-1
系級:111
姓名:林學謙
學號:E14073043
program target:使用者輸入其名字與姓和出生年，顯示出其名字與姓，在計算其現在年紀，此方法為使用char來處理各項問題

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	//count_c:計算coma數量,count_s:計算space數量 ,cal: 年紀計算 ,chtoi: char to integer
	int count_c = 0, count_s = 0, cal = 0, chtoi = 0;
	//輸入整句的字元位置，不隨著for迴圈改變
	size_t c_ch = 0;
	//輸入name_birth,f_name為將name_birth切成三等分
	char name_birth[80], f_name[3][80] = { 0 };


	cout << "Please enter your name and birth year in one string :(First name) (Last name), (birth)" << endl;
	cin.getline(name_birth, 80);

	//ex: gordon lin, 1999

	for (int k = 0; k < 3; k++)
	{
		//因為要固定格式，並且不希望多浪費一排的空間，所以在k==2的位置將c_ch往後加一格，跨過空白字元
		if (k == 2)
		{
			if ((static_cast<int>(name_birth[c_ch])) != 32)
			{
				cout << "wrong format ! error:0" << endl;
				system("pause");
				return 0;
			}
			c_ch++;
		}

		for (size_t i = 0; c_ch < strlen(name_birth); i++, c_ch++)
		{

			chtoi = static_cast<int>(name_birth[c_ch]);
			//空白字元跳出 並且作紀錄 為了讓其不要無限迴圈 再加入c_ch++
			if (chtoi == 32)
			{
				c_ch++;
				count_s++;
				break;
			}
			//逗號跳出 並且作紀錄 為了讓其不要無限迴圈 再加入c_ch++
			else if (chtoi == 44)
			{
				c_ch++;
				count_c++;
				break;
			}
			//將資料取出並分別放入三個列矩陣中
			f_name[k][i] = name_birth[c_ch];
		}
		//處理當空白與逗號隨機放置的問題(除了正常的以外) 並加入如果多空白字元或是逗號也排除
		if (count_s != 1 && k == 0)
		{
			cout << "wrong format ! error:1" << endl;
			system("pause");
			return 0;
		}
		else if (k == 1 && count_c != 1)
		{
			cout << "wrong format ! error:2" << endl;
			system("pause");
			return 0;
		}
		else if (count_c >= 2 || count_s >= 2)
		{
			cout << "wrong format ! error:3" << endl;
			system("pause");
			return 0;
		}
	}

	//檢測三個列矩陣中，名字內是否有數字，或是出生年有字母
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < strlen(f_name[k]); i++)
		{

			if (k < 2 && isalpha(f_name[k][i]) == 0)
			{
				cout << "wrong format ! error:4" << endl;
				system("pause");
				return 0;
			}
			else if (k == 2 && isalpha(f_name[k][i]) != 0)
			{
				cout << "wrong format ! error:4" << endl;
				system("pause");
				return 0;
			}
		}
	}

	cal = 2022 - atoi(f_name[2]);
	if (cal < 0)
	{
		cout << "wrong format ! 5" << endl;
		system("pause");
		return 0;
	}

	//輸出
	cout << '\n' << '\n';
	cout << "Here's your information" << endl;
	cout << "Last  name:" << f_name[1] << endl;
	cout << "First name:" << f_name[0] << endl;
	cout << "Age: " << cal << endl;
	system("pause");
	return 0;
}
/*
檔案名稱:question2_1.cpp
系級:111
姓名:林學謙
學號:E14073043
program target:執行猜數字遊戲，會自行產生1~100的數字，一開始可以輸入玩家名額，最多5位，並且在這邊加入防呆機制，不可輸入不是1~5的數字
每一次如果輸入的數字不是正確的，都會更改選擇範圍，讓下一位選手有更高的機率進行猜測，此程式都是用while迴圈進行設計
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	//name 玩家輸入名字存放 num_pc 玩家輸入數量
	char name[5][80], num_pc = 0 ;
	//num_p 輸入的玩家數量 guess_p 玩家所猜測的數字 guess_c 電腦猜測的數字 max,min 猜測最大最小範圍
	int num_p = 0, num = 1, guess_p = -1, guess_c = 0, i = 1, min = 1, max = 100;



	//ASCII碼來解決輸入錯誤問題
	while (num_p < 49 || num_p >= 54)
	{
		cout << "How many player want to play(up to 5) :" << endl;
		cin >> num_pc;
		num_p = static_cast<int>(num_pc);
		//去除掉後半部不需要的部分
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
	}

	//將ASCII code轉回原本整數型態
	num_p = num_p - 48;

	cout << "Player name's length must be smaller than 80 " << endl;

	//輸入玩家名稱
	while (i != num_p + 1)
	{

		cout << "Number " << i << " player name : ";
		cin >> name[i];
		i++;
	}

	//電腦猜測數字
	srand(static_cast<unsigned int>(time(NULL)));
	guess_c = 2 + rand() * 97 / 32767;
	cout << "The guess range is 1 ~ 100 " << endl;

	while (guess_p != guess_c)
	{
		//告訴玩家猜測後的範圍
		if (guess_p >= min && guess_p < guess_c)
		{
			cout << "Guess " << guess_p << "~" << max << " number" << endl;
			min = guess_p;
		}
		else if (guess_p <= max && guess_p > guess_c)
		{
			cout << "Guess " << min << "~" << guess_p << " number" << endl;
			max = guess_p;
		}

		//玩家輸入猜測
		cout << name[num] << " guess number : ";
		cin >> guess_p;

		//進行num的計算 才有辦法顯示玩家輸入的名字為何
		if (guess_p == guess_c)
		{
			cout << "Congratuation, " << name[num] << " guess the right number." << endl;
		}

		if (num < num_p)
		{
			num++;
		}
		else
		{
			num = 1;
		}

	}
	system("pause");
	return 0;
}
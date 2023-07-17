/*
##版權所有 禁止抄襲##

檔案名稱:HWS6-Q2
系級:111
姓名:林學謙
學號:E14073043
program target:讓使用者輸入studentID，並且每一次都詢問是否要繼續加入下一個，並且最後隨機輸出四個隨機成績 ，並且做排版並輸出

*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


int main()
{
	//參數設置
	int count = 0, avg[20] = { 0 };
	string stu_id[20];
	int score[4][20];
	char YN;
	//Enter stdudent ID 並且判斷是否繼續輸入
	do
	{
		cout << "(Up to 20)Enter student ID :";
		cin >> stu_id[count];
		cout << stu_id[count] << endl;
		cout << "Whether enter next name or not (Y/N) :(key in Y y or N n)(only one character)" << endl;
		cin >> YN;
		//N 跳出 Y 繼續 其他則關閉
 		if (static_cast<int>(toupper(YN)) == 78)
		{
			break;
		}
		else if (static_cast<int>(toupper(YN)) == 89)
		{
			count++;
		}
		else 
		{
			cout << "Wrong Key-in ! terminate !" << endl;
			system("pause");
			return 0;
		}
		
		
	} while (count < 20);
	//種子碼設定
	srand(static_cast<unsigned int>(time(NULL)));

	for (int k = 0; k < (count + 1); k++)
	{
		for (int i = 0; i < 4; i++)
		{
			
			score[i][k] = 0 + rand() * 100 / 32767;
			avg[k] += score[i][k];
		}
		
	}
	//標示
	cout << "Student ID" << setw(15) << "English" << setw(15) << "Chinese" << setw(12) << "Math" << setw(17) << "Chemistry" << setw(15) <<"Average" << endl;
	
	//輸出並排版
	for (int i = 0; i < count + 1; i++)
	{
		avg[i] = avg[i] / 4;
		cout << stu_id[i];
		
		cout << setw(25 - stu_id[i].length()) << score[0][i]
			 << setw(15) << score[1][i]
			 << setw(12) << score[2][i]
			 << setw(17) << score[3][i]
			 << setw(15) << avg[i] << endl;
	}
	system("pause");
	return 0;
}
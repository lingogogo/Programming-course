/*
##���v�Ҧ� �T���ŧ##

�ɮצW��:HWS6-Q2
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:���ϥΪ̿�JstudentID�A�åB�C�@�����߰ݬO�_�n�~��[�J�U�@�ӡA�åB�̫��H����X�|���H�����Z �A�åB���ƪ��ÿ�X

*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


int main()
{
	//�ѼƳ]�m
	int count = 0, avg[20] = { 0 };
	string stu_id[20];
	int score[4][20];
	char YN;
	//Enter stdudent ID �åB�P�_�O�_�~���J
	do
	{
		cout << "(Up to 20)Enter student ID :";
		cin >> stu_id[count];
		cout << stu_id[count] << endl;
		cout << "Whether enter next name or not (Y/N) :(key in Y y or N n)(only one character)" << endl;
		cin >> YN;
		//N ���X Y �~�� ��L�h����
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
	//�ؤl�X�]�w
	srand(static_cast<unsigned int>(time(NULL)));

	for (int k = 0; k < (count + 1); k++)
	{
		for (int i = 0; i < 4; i++)
		{
			
			score[i][k] = 0 + rand() * 100 / 32767;
			avg[k] += score[i][k];
		}
		
	}
	//�Х�
	cout << "Student ID" << setw(15) << "English" << setw(15) << "Chinese" << setw(12) << "Math" << setw(17) << "Chemistry" << setw(15) <<"Average" << endl;
	
	//��X�ñƪ�
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
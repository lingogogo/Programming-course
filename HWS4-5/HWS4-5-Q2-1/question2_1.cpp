/*
�ɮצW��:question2_1.cpp
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:����q�Ʀr�C���A�|�ۦ沣��1~100���Ʀr�A�@�}�l�i�H��J���a�W�B�A�̦h5��A�åB�b�o��[�J���b����A���i��J���O1~5���Ʀr
�C�@���p�G��J���Ʀr���O���T���A���|����ܽd��A���U�@���⦳�󰪪����v�i��q���A���{�����O��do-while�j��i��]�p
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	//name ���a��J�W�r�s�� num_pc ���a��J�ƶq
	char name[5][80], num_pc = 0;
	//num_p ��J�����a�ƶq guess_p ���a�Ҳq�����Ʀr guess_c �q���q�����Ʀr max,min �q���̤j�̤p�d��
	int num_p = 0, num = 1, guess_p = -1, guess_c = 0, i = 1, max = 100, min = 1;



	//ASCII�X�ӸѨM��J���~���D
	do
	{
		cout << "How many player want to play(up to 5) :" << endl;
		cin >> num_pc;
		num_p = static_cast<int>(num_pc);
		//�h������b�����ݭn������
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (num_p < 49 || num_p >= 54);

	//�NASCII code��^�쥻��ƫ��A
	num_p = num_p - 48;

	cout << "Player name's length must be smaller than 80 " << endl;

	//��J���a�W��
	do
	{
		
		cout << "Number " << i << " player name : ";
		
		cin >> name[i];
		i++;
	} while (i != num_p + 1);

	//�q���q���Ʀr
	srand(static_cast<unsigned int>(time(NULL)));
	guess_c = 2 + rand() * 97 / 32767;
	cout << "The guess range is 1 ~ 100 " << endl;
	

	do
	{
		//�i�D���a�q���᪺�d��
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

		//���a��J�q��
		cout << name[num] << " guess number : ";
		cin >> guess_p;

		//�i��num���p�� �~����k��ܪ��a��J���W�r����
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

	} while (guess_p != guess_c);
	system("pause");
	return 0;
}
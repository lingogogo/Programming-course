/*
�ɮצW��:question1.cpp
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:��J2�ӼƦr�A�i�H�C�X�íp��X�Ҧ�����ơA�åB�z�L��ӼƦr��������Ƥ��۬ۥ[�����
�åB�[�J���b����A�T��ϥΪ̿�J�t�ƻP�r���C
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

	//�ϥ�sqrt�h�u�ƭp��L�{
	for (int i = G_data1; i <= G_data2; i++)
	{
		tem_data = static_cast<int>(sqrt(i));

		//�o�@�q�L�k�B�z�p��2���ȡA�S���ر��p�u���o�ͦb�̤p��J�ȻP�̤j��J�Ȥ������d�򦳥]�t��2��3
		//�ҥH�b�̥~��t�~���B�z
		for (int k = 2; k <= tem_data; k++)
		{
			check = i % k;
			//��ܰ����i�A���w���O���
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

	//deal with the 2 and 3 �U�����p G_data1 must be smaller than G_data2
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
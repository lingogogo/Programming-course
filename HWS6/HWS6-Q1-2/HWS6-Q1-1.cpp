/*
##���v�Ҧ� �T���ŧ##

�ɮצW��:HWS6-Q1-1
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:�ϥΪ̿�J��W�r�P�m�M�X�ͦ~�A��ܥX��W�r�P�m�A�b�p���{�b�~���A����k���ϥ�char�ӳB�z�U�����D

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	//count_c:�p��coma�ƶq,count_s:�p��space�ƶq ,cal: �~���p�� ,chtoi: char to integer
	int count_c = 0, count_s = 0, cal = 0, chtoi = 0;
	//��J��y���r����m�A���H��for�j�����
	size_t c_ch = 0;
	//��Jname_birth,f_name���Nname_birth�����T����
	char name_birth[80], f_name[3][80] = { 0 };


	cout << "Please enter your name and birth year in one string :(First name) (Last name), (birth)" << endl;
	cin.getline(name_birth, 80);

	//ex: gordon lin, 1999

	for (int k = 0; k < 3; k++)
	{
		//�]���n�T�w�榡�A�åB���Ʊ�h���O�@�ƪ��Ŷ��A�ҥH�bk==2����m�Nc_ch����[�@��A��L�ťզr��
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
			//�ťզr�����X �åB�@���� ���F���䤣�n�L���j�� �A�[�Jc_ch++
			if (chtoi == 32)
			{
				c_ch++;
				count_s++;
				break;
			}
			//�r�����X �åB�@���� ���F���䤣�n�L���j�� �A�[�Jc_ch++
			else if (chtoi == 44)
			{
				c_ch++;
				count_c++;
				break;
			}
			//�N��ƨ��X�ä��O��J�T�ӦC�x�}��
			f_name[k][i] = name_birth[c_ch];
		}
		//�B�z��ťջP�r���H����m�����D(���F���`���H�~) �å[�J�p�G�h�ťզr���άO�r���]�ư�
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

	//�˴��T�ӦC�x�}���A�W�r���O�_���Ʀr�A�άO�X�ͦ~���r��
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

	//��X
	cout << '\n' << '\n';
	cout << "Here's your information" << endl;
	cout << "Last  name:" << f_name[1] << endl;
	cout << "First name:" << f_name[0] << endl;
	cout << "Age: " << cal << endl;
	system("pause");
	return 0;
}
/*
********************************************************************************************************************************
##���v�Ҧ� �T���ŧ##

�ɮצW��:HW7_Q2
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:�H����ܦ�P�C��2~6���x�}�A���@�w����x�}�A�ñN�䤺�����ȳ]�w�b-11.8�P5.1�����A�åB��kronecker product�A����ܥX�o
�T�ӯx�}���ˤl�A�M��N�C�@�Ӫ��̤p����ܥX�ӡA���F�H���L�X�{��ӥH�W���̤p�ȡA�٨ϥΰj��h�˴��O�_���P�˪��̤p�Ȩÿ�X�C
********************************************************************************************************************************
*/
#include <iostream>
#include <ctime> 
#include <iomanip>
using namespace std;

int main()
{
	int m_m = 0, m_n = 0, m_p = 0, m_q = 0;
	srand(static_cast<unsigned int>(time(NULL)));
	
	m_m = 2 + 4 * rand() / RAND_MAX; m_n = 2 + 4 * rand() / RAND_MAX; m_p = 2 + 4 * rand() / RAND_MAX; m_q = 2 + 4 * rand() / RAND_MAX;
	//cout << m_m << m_n << m_p << m_q;
	double **A, **B, **Kron_m; 
	int judge_m = 0, locat_m[2] = {0};
	double min = 5.1;
	A = new double *[m_m];
	B = new double *[m_p];
	//cout << "A row: " << m_m << " A column: " << m_n << endl;

	//�ŧi A �M B ��Ӽ�
	for (int i = 0; i < m_m; i++)
	{
		A[i] = new double[m_n];//*(A + i) = new double[m_n];
	}
	for (int i = 0; i < m_p; i++)
	{
		B[i] = new double[m_q];
	}

	//�ŧi A �M B �C�Ӽ�
	cout << "A matrix :" << endl;
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			A[i][j] = static_cast<double>(-11.8 + 16.9 * rand() / RAND_MAX);
			cout << fixed << setprecision(1) << setw(7) << A[i][j];
			if (j == (m_n - 1))
			{
				cout << endl;
			}
		}
	}
	
	cout << "B matrix :" << endl;
	for (int i = 0; i < m_p; i++)
	{
		
		for (int j = 0; j < m_q; j++)
		{
			B[i][j] = static_cast<double>( -11.8 + 16.9 * rand() / RAND_MAX);
			cout << fixed << setprecision(1) << setw(7) << B[i][j];
			if (j == (m_q - 1))
			{
				cout << endl;
			}
		}
	}

	//Kronecker product of two matrix A and B
	Kron_m = new double *[(m_m)*(m_p)];//�p��᪺�x�}�j�p

	for (int i = 0; i < (m_m*m_p); i++)
	{
		Kron_m[i] = new double[(m_n)*(m_q)];
	}

	cout << "Kronecker product of two matrix :" << endl;

	for (int m = 0; m < m_m; m++)
	{
		for (int p = 0; p < m_p; p++)
		{
			for (int n = 0; n < m_n; n++)
			{
				for (int q = 0; q < m_q; q++)
				{
					Kron_m[m * m_p + p][n * m_q + q] = A[m][n] * B[p][q];
					cout << fixed << setprecision(1) << setw(7) << Kron_m[m * m_p + p][n * m_q + q];
				}
			}
			cout << endl;
		}
	}

	//��XA matrix �̤p��
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (min > A[i][j])
			{
				min = A[i][j];
				judge_m = 1;
				locat_m[0] = i + 1; //�쥻�ϥ�++i �����o�˪��ʧ@ �|��i�i��+1 �ɭP��v�Tfor�j�骺�B�@ �ҥH�ϥ�i+1�N���|�ܰʨ�i���� �]��++i => i = i + 1; locat_m[0] = i;
				locat_m[1] = j + 1;
			}
		}
	}
	cout << "A matrix minimum subscript: \n";
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (min == A[i][j])
			{
				locat_m[0] = i + 1;
				locat_m[1] = j + 1;
				cout << "[" << locat_m[0] << "," << locat_m[1] << "]\n";
			}

		}
	}
	cout << "minimum number: " << min << endl;
	
	//��XB matrix �̤p��
	//reset
	min = 5.1;
	for (int i = 0; i < m_p; i++)
	{
		for (int j = 0; j < m_q; j++)
		{
			if (min > B[i][j])
			{
				min = B[i][j];
				judge_m = 2;
				locat_m[0] = i + 1;
				locat_m[1] = j + 1;
			}
		}
	}
	cout << "B matrix minimum subscript: \n";
	for (int i = 0; i < m_p; i++)
	{
		for (int j = 0; j < m_q; j++)
		{
			if (min == B[i][j]) 
			{
				locat_m[0] = i + 1;
				locat_m[1] = j + 1;
				cout << "[" << locat_m[0] << "," << locat_m[1] << "]\n";
			}
			
		}
	}
	cout << "minimum number: " << min << endl;
	
	//��Xkronecker product ���̤p��
	//reset: the maximun number -11.8*(-11.8)
	min = 139.24;
	for (int i = 0; i < (m_m)*(m_p); i++)
	{
		for (int j = 0; j < (m_n)*(m_q); j++)
		{
			if (min > Kron_m[i][j])
			{
				min = Kron_m[i][j];
				judge_m = 3;
				locat_m[0] = i + 1;
				locat_m[1] = j + 1;
			}
		}
	}
	cout << "Kronecker product's matrix minimum subscript: \n";
	for (int i = 0; i < (m_m)*(m_p); i++)
	{
		for (int j = 0; j < (m_n)*(m_q); j++)
		{
			if (min == Kron_m[i][j])
			{
				locat_m[0] = i + 1;
				locat_m[1] = j + 1;
				cout << "[" << locat_m[0] << "," << locat_m[1] << "]\n";
			}

		}
	}
	cout << "minimum number: " << min << endl;
	
	//delete dynamic allocation
	for (int i = 0; i < m_m; i++) {
		delete [] A[i];
	}
	for (int i = 0; i < m_p; i++) {
		delete [] B[i];
	}
	for (int i = 0; i < m_m; i++) {
		delete [] Kron_m[i];
	}
	delete [] A;
	delete [] B;
	delete [] Kron_m;
	system("pause");
	return 0;
}
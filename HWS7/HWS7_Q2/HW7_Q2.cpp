/*
********************************************************************************************************************************
##版權所有 禁止抄襲##

檔案名稱:HW7_Q2
系級:111
姓名:林學謙
學號:E14073043
program target:隨機顯示行與列為2~6的矩陣，不一定為方矩陣，並將其內部的值設定在-11.8與5.1之間，並且做kronecker product，並顯示出這
三個矩陣的樣子，然後將每一個的最小值顯示出來，為了以防他出現兩個以上的最小值，還使用迴圈去檢測是否有同樣的最小值並輸出。
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

	//宣告 A 和 B 行個數
	for (int i = 0; i < m_m; i++)
	{
		A[i] = new double[m_n];//*(A + i) = new double[m_n];
	}
	for (int i = 0; i < m_p; i++)
	{
		B[i] = new double[m_q];
	}

	//宣告 A 和 B 列個數
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
	Kron_m = new double *[(m_m)*(m_p)];//計算後的矩陣大小

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

	//輸出A matrix 最小值
	for (int i = 0; i < m_m; i++)
	{
		for (int j = 0; j < m_n; j++)
		{
			if (min > A[i][j])
			{
				min = A[i][j];
				judge_m = 1;
				locat_m[0] = i + 1; //原本使用++i 但其實這樣的動作 會對i進行+1 導致其影響for迴圈的運作 所以使用i+1就不會變動到i的值 因為++i => i = i + 1; locat_m[0] = i;
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
	
	//輸出B matrix 最小值
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
	
	//輸出kronecker product 的最小值
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
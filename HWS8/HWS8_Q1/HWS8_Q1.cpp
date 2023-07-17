/*
********************************************************************************************************************************
##版權所有 禁止抄襲##
檔案名稱:HW8_Q1
系級:111
姓名:林學謙
學號:E14073043
program target:隨機顯示行與列為2~6的矩陣，不一定為方矩陣，並將其內部的值設定在-11.8與5.1之間，並且做kronecker product，並顯示出這
三個矩陣的樣子，然後將每一個的最小值顯示出來，為了以防他出現兩個以上的最小值，還使用迴圈去檢測是否有同樣的最小值並輸出，這邊都是使
用function進行，這樣如果使用者想要自定義的範圍，較好使用。
********************************************************************************************************************************
*/
#include <iostream>
#include <ctime> 
#include <iomanip>

using namespace std;
//function 宣告
inline int random_int(const int, const int);
inline float random_float(const float lower, const float upper);
double** create(const int , const int );
void create_elements(double**, const int, const int);
void kronecker_product(double **&, int &, int &, const double *const*const,
	const int, const int, const double *const*const, const int, const int);
void minimun(double**, const int, const int);
void output_matrix(double**, const int, const int);
void release(double **&, const int);

int main()
{
	double **A, **B, **kron_m;
	int row_a = 0, col_a = 0, row_b = 0, col_b = 0, row_kron = 0, col_kron = 0;
	int* min_r = 0, *min_c = 0;
	double *min = 0;
	srand(static_cast<unsigned int>(time(NULL)));
	row_a = random_int(2, 6); row_b = random_int(2, 6); col_a = random_int(2, 6); col_b = random_int(2, 6);
	A = create(row_a, col_a);
	B = create(row_b, col_b);
	
	create_elements(A, row_a, col_a);
	create_elements(B, row_b, col_b);

	kronecker_product(kron_m, row_kron, col_kron, A, row_a, col_a, B, row_b, col_b);
	cout << "A's matrix : " << endl;
	output_matrix(A, row_a, col_a);
	cout << "B's matrix : " << endl;
	output_matrix(B, row_b, col_b);
	cout << "kronecker product's matrix : " << endl;
	output_matrix(kron_m, row_kron, col_kron);
	cout << "A's ";
	minimun(A, row_a, col_a);
	cout << "B's ";
	minimun(B, row_b, col_b);
	cout << "kronecker product's ";
	minimun(kron_m, row_kron, col_kron);
	void release(double A, const int row_a);
	void release(double B, const int row_b);
	void release(double kron_m, const int kron_row);
	**A = 1;
	return 0;
}

inline int random_int(const int lower, const int upper)
{
	return (lower + (upper - lower)*rand() / RAND_MAX);
}

inline float random_float(const float lower, const float upper)
{
	return (lower + (upper - lower)*rand()/RAND_MAX);
}
//創造二維矩陣
double** create(const int rows, const int columns)
{
	double** A;
	A = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new double[columns];
	}
	//cout << "A start :" << A << "A[0][0] start :" << &A[0][0] << " " << &A[0][1] << endl;
	
	return A;
}
//Q:如果今天在上面傳入的為雙重指標，是否下面可以寫成兩個中括號[][] : void create_elements(double mat[][]) 
//塞入範圍值
void create_elements(double** mat,const int rows, const int columns) 
{
	//如果直接使用5.1輸入，其基本資料型態為double，必須輸入5.1f才可以宣告其為float的狀態。
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] =random_float(-11.8f,5.1f);//會出現引數從double轉換為const float? Q:回傳不是float為何為const float?
		}
	}
	return;
}
//利用參照回傳值
//克羅內積
void kronecker_product(double **&result, int &r_rows, int &r_columns, const double *const*const matrix1,
	const int rows1, const int columns1, const double *const*const matrix2, const int rows2, const int columns2)
{
	r_rows = rows1 * rows2;
	r_columns = columns1 * columns2;
	result = create(r_rows, r_columns);
	for (int m = 0; m < rows1; m++)
	{
		for (int p = 0; p < rows2; p++)
		{
			for (int n = 0; n < columns1; n++)
			{
				for (int q = 0; q < columns2; q++)
				{
					result[m * rows2 + p][n * columns2 + q] = matrix1[m][n] * matrix2[p][q];
				}
			}
		}
	}
}
//計算出最小值並輸出其最小值與位置
void minimun(double** mat ,const int rows, const int columns)
{
	double min = 1000;
	int row = 0, col = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (min > mat[i][j])
			{
				min = mat[i][j];
				row = i + 1;
				col = j + 1;
			}
		}
	}
	cout << "minimun number : " << min << endl;
	cout << "Matrix subscript of minimun :\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (min == mat[i][j])
			{
				row = i + 1;
				col = j + 1;
				cout << "[" << row << "," << col << "]\n";
			}

		}
	}
	cout << endl;
}
//釋放空間
void release(double **& mat, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[rows];
	}
	delete[] mat;
}
//顯示矩陣
void output_matrix(double** mat, const int rows, const int col)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << fixed << setprecision(1) << setw(7) << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
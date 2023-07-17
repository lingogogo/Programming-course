/*
********************************************************************************************************************************
##���v�Ҧ� �T���ŧ##
�ɮצW��:HW8_Q1
�t��:111
�m�W:�L����
�Ǹ�:E14073043
program target:�H����ܦ�P�C��2~6���x�}�A���@�w����x�}�A�ñN�䤺�����ȳ]�w�b-11.8�P5.1�����A�åB��kronecker product�A����ܥX�o
�T�ӯx�}���ˤl�A�M��N�C�@�Ӫ��̤p����ܥX�ӡA���F�H���L�X�{��ӥH�W���̤p�ȡA�٨ϥΰj��h�˴��O�_���P�˪��̤p�Ȩÿ�X�A�o�䳣�O��
��function�i��A�o�˦p�G�ϥΪ̷Q�n�۩w�q���d��A���n�ϥΡC
********************************************************************************************************************************
*/
#include <iostream>
#include <ctime> 
#include <iomanip>

using namespace std;
//function �ŧi
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
//�гy�G���x�}
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
//Q:�p�G���Ѧb�W���ǤJ�����������СA�O�_�U���i�H�g����Ӥ��A��[][] : void create_elements(double mat[][]) 
//��J�d���
void create_elements(double** mat,const int rows, const int columns) 
{
	//�p�G�����ϥ�5.1��J�A��򥻸�ƫ��A��double�A������J5.1f�~�i�H�ŧi�䬰float�����A�C
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] =random_float(-11.8f,5.1f);//�|�X�{�޼Ʊqdouble�ഫ��const float? Q:�^�Ǥ��Ofloat����const float?
		}
	}
	return;
}
//�Q�ΰѷӦ^�ǭ�
//�Jù���n
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
//�p��X�̤p�Ȩÿ�X��̤p�ȻP��m
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
//����Ŷ�
void release(double **& mat, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[rows];
	}
	delete[] mat;
}
//��ܯx�}
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
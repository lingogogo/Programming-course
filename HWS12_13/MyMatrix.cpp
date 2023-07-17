#include "MyMatrix.h"
#include "MyValue.h"
#include <iostream>
#include <iomanip>

using std::setw;
using std::cout;
using std::endl;

template<class T> T random_num(T up, T low)
{
	return low + (up - low)*rand() / RAND_MAX;
}
//default constructor
MyMatrix::MyMatrix()
{
	matrixCount++;
}
//constructor
MyMatrix::MyMatrix(unsigned int row,unsigned int col)
{
	rows = row;
	columns = col;
	matrix = new float *[row];
	for (unsigned int i = 0; i < row; i++)
	{
		matrix[i] = new float[columns];
	}
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			matrix[i][j] = random_num(5.1f, -11.8f);
		}
	}
	matrixCount++;
}
//copy constructor
MyMatrix::MyMatrix(const MyMatrix &mat)
{
	rows = mat.rows;
	columns = mat.columns;
	matrix = new float *[mat.rows];
	for (unsigned int i = 0; i < mat.rows; i++)
	{
		matrix[i] = new float[mat.columns];
	}
	//如果不給空間放入，直接取用copy使用 會使用到同一塊double pointer所指向的位置
	for (unsigned int i = 0; i < mat.rows; i++)
	{
		for (unsigned int j = 0; j < mat.columns; j++)
		{
			matrix[i][j] = mat.matrix[i][j];
		}
	}
	matrixCount++;
}
//release MyMatrix
MyMatrix::~MyMatrix()
{
	//cout << "destroy" << endl;
	for (unsigned int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}
//output MyMatrix data
void MyMatrix::output() const
{
	/*float **matrix;
	unsigned int rows;
	unsigned int columns;
	static int matrixCount;*/
	cout << "Matrix :" << endl;
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			cout << setw(8) << std::setprecision(1) << std::fixed << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Matrix rows : " << rows << endl;
	cout << "Matrix columns : " << columns << endl << endl;
}
//get special location in Matrix
float MyMatrix::get_value(unsigned int row ,unsigned int col) const
{
	//cout << "Matrix " << "( " << row + 1<< " , " << col + 1 << " )" << " :" << matrix[row-1][col-1];
	return matrix[row][col];
}
//kronecker_product and return the result
MyMatrix MyMatrix::kronecker_product(const MyMatrix &mat1)
{
	unsigned int rows_r = mat1.rows*this->rows;
	unsigned int columns_r = this->columns*mat1.columns;
	MyMatrix result(rows_r, columns_r);
	
	for (unsigned int m = 0; m < mat1.rows; m++)
	{
		for (unsigned int p = 0; p < this->rows; p++)
		{
			for (unsigned int n = 0; n < mat1.columns; n++)
			{
				for (unsigned int q = 0; q < this->columns; q++)
				{
					result.matrix[m*this->rows + p][n*this->columns + q] = mat1.matrix[m][n]*(this->matrix[p][q]);
				}
			}
		}
	}
	return result;
}
//get the static int member in private
int MyMatrix::getmatirxCount()
{
	return matrixCount;
}

//result,matA,matB, 3 MyMatrix
MyValue MyMatrix::get_minimum()
{
	unsigned int r = 0, c = 0;
	float minum = matrix[0][0];
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			if (matrix[i][j] < minum)
			{
				minum = matrix[i][j];
				r = i;
				c = j;
			}
		}
	}
	
	MyValue min(this, r, c);
	return min;
}

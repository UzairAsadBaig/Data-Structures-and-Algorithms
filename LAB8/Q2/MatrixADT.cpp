#include <iostream>

using namespace std;

class Matrix
{
private:
	int *m;
	int rows;
	int columns;

public:
	//Added by Sir
	Matrix();
	Matrix(const int);
	Matrix(const int, const int);
	Matrix(const Matrix &);
	Matrix &operator=(const Matrix &);
	~Matrix();
	Matrix &operator+(const Matrix &);
	Matrix &operator-(const Matrix &);
	void Get();
	void Put();
	//Added by me
	Matrix &transpose();
	Matrix &operator*(const Matrix &rhs);
	bool isIdentity();
	bool isSymmetric();
	bool operator==(const Matrix &rhs);
	void additiveInverse();
	bool isColumnMatrix();
	bool isRowMatrix();
};

Matrix::Matrix()
{
	rows = 0;
	columns = 0;
	m = NULL;
}

Matrix::Matrix(const int order)
{
	m = new int[order * order];
	rows = order;
	columns = order;
}

Matrix::Matrix(const int rows, const int columns)
{
	m = new int[rows * columns];
	this->rows = rows;
	this->columns = columns;
}

Matrix::Matrix(const Matrix &oo)
{
	rows = oo.rows;
	columns = oo.columns;
	m = new int[rows * columns];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m[i + j * rows] = oo.m[i + j * rows];
		}
	}
}

Matrix &Matrix::operator=(const Matrix &rhs)
{
	if (this != &rhs)
	{
		delete[] m;

		rows = rhs.rows;
		columns = rhs.columns;
		m = new int[rows * columns];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				m[i + j * rows] = rhs.m[i + j * rows];
			}
		}
	}
	return *this;
}

Matrix::~Matrix()
{
	delete[] m;
}

Matrix &Matrix::operator+(const Matrix &rhs)
{
	if (rows == rhs.rows && columns == rhs.columns)
	{
		Matrix *ro = new Matrix(rhs.rows, rhs.columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ro->m[i + j * rows] = m[i + j * rows] + rhs.m[i + j * rows];
			}
		}
		return *ro;
	}
	else
	{
		throw -1;
	}
}

Matrix &Matrix::operator-(const Matrix &rhs)
{
	if (rows == rhs.rows && columns == rhs.columns)
	{
		Matrix *ro = new Matrix(rhs.rows, rhs.columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				ro->m[i + j * rows] = m[i + j * rows] - rhs.m[i + j * rows];
			}
		}
		return *ro;
	}
	else
	{
		throw -1;
	}
}
Matrix &Matrix::operator*(const Matrix &rhs)
{
	if (columns == rhs.rows)
	{
		Matrix *ret = new Matrix(rows, rhs.columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rhs.columns; j++)
			{
				ret->m[i + j * rows] = 0;
				for (int r = i, c = j * rhs.rows; c < (j + 1) * rhs.rows; r = r + rows, c++)
				{
					ret->m[i + j * rows] = ret->m[i + j * rows] + (m[r] * rhs.m[c]);
				}
			}
		}
		return *ret;
	}
	else
		throw -1;
}

bool Matrix::operator==(const Matrix &rhs)
{
	if (rows != rhs.rows || columns != rhs.columns)
		return false;
	for (int i = 0; i < rows * columns; i++)
	{
		if (m[i] != rhs.m[i])
			return false;
	}
	return true;
}

void Matrix::Get()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> m[i + j * rows];
		}
	}
}

Matrix &Matrix::transpose()
{
	Matrix *ret = new Matrix(columns, rows);
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ret->m[k] = m[i + j * rows];
			k++;
		}
	}
	return *ret;
}

void Matrix::additiveInverse()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			m[i + j * rows] = m[i + j * rows] * (-1);
		}
	}
}

bool Matrix::isColumnMatrix()
{
	if (columns == 1)
		return true;
	else
		return false;
}
bool Matrix::isRowMatrix()
{

	if (rows == 1)
		return true;
	else
		return false;
}

bool Matrix::isSymmetric()
{
	if (transpose() == transpose().transpose())
		return true;
	else
		return false;
}

bool Matrix::isIdentity()
{
	if (rows != columns)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{

			if (i == j && m[i + j * rows] != 1)
				return false;
			else if (i != j && m[i + j * rows] != 0)
				return false;
		}
	}
	return true;
}

void Matrix::Put()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << m[i + j * rows] << " ";
		}
		cout << endl;
	}
}

int main()
{
	// Matrix p(3, 5), q(5, 3);
	// cout << "Enter the elements of two (3 X 2) matrices " << endl;
	// cout << endl;
	// p.Get();
	// q.Get();
	// cout << endl;

	// cout << "First matrix is :" << endl;
	// p.Put();
	// cout << endl;

	// cout << "Second matix is :" << endl;
	// q.Put();
	// cout << endl;

	// Matrix k = p * q;
	// cout << "Product of above two matrices is : " << endl;
	// k.Put();
	// cout << endl;

	// cout << "Transpose of above matrix is : " << endl;
	// Matrix kTrans = k.transpose();
	// kTrans.Put();
	// cout << endl;

	// Matrix Identity(2, 2);
	// Identity.Get();
	// Identity.Put();
	// cout << endl
	// 	 << Identity.isIdentity();
	// cout << endl
	// 	 << Identity.isSymmetric();

	// Matrix A(2, 2);
	// A.Get();
	// A.additiveInverse();
	// A.Put();

	// Matrix R(1, 2);
	// R.Get();
	// cout << R.isRowMatrix();

	return 0;
}

#include <iostream>
using namespace std;

template<class T>
class Matrix
{
	T** data;
	int rows;
	int cols;
public:
	Matrix(int r, int c)
	{
		rows = r;
		cols = c;

		data = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new T[cols]{ 0 };
		}
			
	}

	void FillNumbers()
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = rand() % 20 + 1;
			}
		}
	}
	int GetRows()
	{
		return rows;
	}
	int GetCols()
	{
		return cols;
	}
	T** GetData()
	{
		return data;
	}
	~Matrix()
	{
		for (size_t i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}

	void FindElement()
	{
		int min = 0;
		int max = 21;

		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (data[i][j] > min)
				{
					min = data[i][j];
				}
				if (data[i][j] < max)
				{
					max = data[i][j];
				}
			}
		}
		cout << "Min number is: " << max << endl;
		cout << "Max number is: " << min << endl;
		cout << endl;
	}

	Matrix& operator++()
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] += 1;
			}
		}
		return *this;
	}
	Matrix& operator--()
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] -= 1;
			}
		}
		return *this;
	}
	Matrix& operator/=(int number)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] /= number;
			}
		}
		return *this;
	}
	Matrix& operator*=(int number)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] *= number;
			}
		}
		return *this;
	}
	Matrix& operator+=(int number)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] += number;
			}
		}
		return *this;
	}
	Matrix& operator-=(int number)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				data[i][j] -= number;
			}
		}
		return *this;
	}
};
template <class T>
ostream& operator<<(ostream& os, Matrix<T> & m)
{
	for (int i = 0; i < m.GetRows(); i++)
	{
		for (int j = 0; j < m.GetCols(); j++)
		{
			os << m.GetData()[i][j] << ", ";
		}
		os << endl;
	}
	return os;
}
int main()
{
	srand(time(NULL));
	int rows = 3, cols = 5;
	int** ptr = new int*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		ptr[i] = new int[cols];
	}

	//int rows2 = 0;
	//int cols2 = 0;
	//cin >> rows2;
	//cin >> cols2;

	//for (int i = 0; i < rows2; i++)
	//{
	//	for (int j = 0; j < cols2; j++)
	//	{
	//		cin >> ptr[i][j];
	//	}
	//}

	//Matrix<int> obj2(rows2, cols2);
	//cout << obj2 << endl;

	Matrix<int> obj1(rows, cols);
	obj1.FillNumbers();
	cout << obj1 << endl;
	obj1.FindElement();

	cout << "++" << endl;
	++obj1;
	cout << obj1 << endl;

	cout << "--" << endl;
	--obj1;
	cout << obj1 << endl;

	cout << "/2" << endl;
	obj1 /= 2;
	cout << obj1 << endl;

	cout << "*3" << endl;
	obj1 *= 3;
	cout << obj1 << endl;

	cout << "+5" << endl;
	obj1 += 5;
	cout << obj1 << endl;

	cout << "-10" << endl;
	obj1 -= 10;
	cout << obj1 << endl;
}
//Задание 1.Проверить, есть ли в матрице хотя бы один столбец, содержащий отрицательный элемент, и найти его но - мер.Уменьшить элементы найденного столбца вдвое.
#include <iostream>
using namespace std;

const int M = 3;
const int N = 3;

void input(double **a)
{
	cout << "input data : \n";
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
			cin >> a[i][j];
	}
	cout << "\n";
}

void output(double **a)
{
	cout << "output data: \n";
	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
			cout << a[i][j] << "\t";
		cout << "\n";
	}
}

void del(double **a)
{
	for (int i = 0; i<M; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}

int findRow(double **a)
{
	int numbRow;
	int j=0;
	for (int j = 0; j<N; j++)
	{
		
		for (int i = 0; i<M; i++)
		{
			if (a[i][j] < 0) { numbRow = j; return numbRow; }
		}
	}
	return j;
}

void change(double **a, int *numbRow)
{
	for (int j = 0; j<M; j++)
	{
		if (j == *numbRow)
		{
			for (int i = 0; i<N; i++)
			{
				a[i][j] = a[i][j] / 2;
			}
			return;
		}
	}
}

int main()
{
	double **a = new double *[M];
	for (int i = 0; i<M; i++)
	{
		a[i] = new double[N];
	}
	input(a);
	output(a);
	int numbRow = findRow(a);
	cout << "Row with value < 0: " << numbRow+1 << "\n";
	change(a, &numbRow);
	cout << "\nAfter change: \n";
	output(a);
	system("pause");
	return 0;
	
}
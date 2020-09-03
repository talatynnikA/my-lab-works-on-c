# include <iostream>
using namespace std;
void massiv();
void matrix();

int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int c;
	do
	{
		cout << endl;
		cout << "¬ведите" << endl;
		cout << "1-одномерный массив" << endl;
		cout << "2-работа с матрицей" << endl;
		cout << "3-выход" << endl;
		cin >> c;
		switch (c)
		{
		case 1: massiv(); break;
		case 2: matrix(); break;
		case 3: break;
		}
	} while (c != 3);
}


void massiv()
{
	int size = 0, i, n, polozh=0,nulevoy=-1;
	float *M, sum = 0, avar, mn, summa=0;
	cout << "¬ведите размер массива ";
	cin >> size;

	M = new float[size];
	for (i = 0; i < size; i++)
	{
		cout << "¬ведите " << i + 1 << " элемент ";
		cin >> *(M + i);
		sum += *(M + i);
	}
	/*avar = sum / size;
	mn = abs(*M - avar);
	n = 0;*/
	for (i = 0; i < size; i++)
	if ((*(M + i)) > 0)
	{
		polozh++;
	}
	cout << "количество положительных элементов =" << polozh;
	cout << endl;
	for (i = 0; i < size; i++)
	if (*(M + i) == 0)
	{
		nulevoy = i;
	}
	if (nulevoy != -1)
	{
		cout << "индекс последнего нулевого элемента=" << nulevoy+1 << endl;
		for (i = nulevoy + 1; i < size; i++)
			summa += *(M + i);
		cout << "сумма элементов после нул€ =" << summa << endl;
	}
	else
		cout << "¬ массиве нет нулевых элементов" << endl;
	delete[] M;
}

void matrix()
{
	int *A, row, colum, i, j, max_colum, max_row, max,nul;
	cout << "¬ведите число строк матрицы ";
	cin >> row;
	cout << "¬ведите чиcло столбцов ";
	cin >> colum;
	A = new int[row * colum];
	for (i = 0; i < row; i++)
	for (j = 0; j < colum; j++)
	{
		cout << "¬ведите " << i + 1 << " элемент " << j + 1 << "-й строки ";
		cin >> *(A + i * colum + j);
	}
	max = A[0];
	max_row = 0;
	max_colum = 0;


	for (i = 0; i < row; i++)
	for (j = 0; j < colum; j++)
	if (*(A + i * colum + j) == 0)
	{
		nul = colum - 1;
	}
	cout << " номер столбца A=" << nul;
	cout << endl;
	delete[] A;
}


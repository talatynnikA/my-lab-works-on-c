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
		cout << "�������" << endl;
		cout << "1-���������� ������" << endl;
		cout << "2-������ � ��������" << endl;
		cout << "3-�����" << endl;
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
	cout << "������� ������ ������� ";
	cin >> size;

	M = new float[size];
	for (i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << " ������� ";
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
	cout << "���������� ������������� ��������� =" << polozh;
	cout << endl;
	for (i = 0; i < size; i++)
	if (*(M + i) == 0)
	{
		nulevoy = i;
	}
	if (nulevoy != -1)
	{
		cout << "������ ���������� �������� ��������=" << nulevoy+1 << endl;
		for (i = nulevoy + 1; i < size; i++)
			summa += *(M + i);
		cout << "����� ��������� ����� ���� =" << summa << endl;
	}
	else
		cout << "� ������� ��� ������� ���������" << endl;
	delete[] M;
}

void matrix()
{
	int *A, row, colum, i, j, max_colum, max_row, max,nul;
	cout << "������� ����� ����� ������� ";
	cin >> row;
	cout << "������� ��c�� �������� ";
	cin >> colum;
	A = new int[row * colum];
	for (i = 0; i < row; i++)
	for (j = 0; j < colum; j++)
	{
		cout << "������� " << i + 1 << " ������� " << j + 1 << "-� ������ ";
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
	cout << " ����� ������� A=" << nul;
	cout << endl;
	delete[] A;
}


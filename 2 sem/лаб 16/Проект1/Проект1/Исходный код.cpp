#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	for (j = n - 1; j >= i; j--)
	if (a[j - 1] > a[j])
	{
		t = a[j - 1];
		a[j - 1] = a[j];
		a[j] = t;
	}
}

void selectSort(int �[], int size2)
{
	int k, i, j;
	for (i = 0; i < size2 - 1; i++)
	{
		for (j = i + 1, k = i; j < size2; j++)
		if (�[j] < �[k])
			k = j;
		int c = �[k];
		�[k] = �[i];
		�[i] = c;
	}
}
void insertSort(int *C2, int size22)
{
	int t, i, j;
	for (i = 1; i < size22; i++)
	{
		t = C2[i];
		for (j = i - 1; j >= 0 && C2[j] > t; j--)
			C2[j + 1] = C2[j];
		C2[j + 1] = t;
	}
}


void main()
{
	setlocale(LC_ALL, "Rus");
	int size, i, size2, size22;
	int A[100], B[100], C[100], C2[100];
	//------------------------------------------------
	cout << "������ � \n";
	cout << "���������� ��������� = ";
	cin >> size;
	for (i = 0; i < size; i++)
	{
		A[i]=rand() % 100;
		/*cout << i + 1 << " ������� = ";
		cin >> A[i];*/
	}
	//------------------------------------------------
	cout << "������ B \n";
	cout << "���������� ��������� = ";
	cin >> size;
	for (i = 0; i < size; i++)
	{
		B[i] = rand() & 99;
		/*cout << i + 1 << " ������� = ";
		cin >> B[i];*/
	}
	//------------------------------------------------
	cout << " ������� �������������: \n";
	cout << " ������  �: ";
	for (i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
	//------------------------------------------------
	//------------------------------------------------

	cout << " ������  B: ";
	for (i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;
	//------------------------------------------------
	//------------------------------------------------
	cout << "������ C \n";
	
	size2 = 0;
	for (i = 0; i < size; i++)
	{
		if (A[i] % 2 != 0)
		{
			C[ size2] = A[i];
			size2++;
		}
	}
		for (i = 0; i < size; i++)
		{
			if (B[i] % 2 == 0)
			{
				C[ size2] = B[i];
				size2++;
			}
			
		}
	
	//------------------------------------------------
	//parr[counter] % 2 != 0
	//bubbleSort(A, size);
	//bubbleSort(B, size);
	//------------------------------------------------

	
		cout << " ��������� �������� �������� �� � � ������ �� B: \n";
	cout << " ������ C: ";
	for (i = 0; i < size2; i++)
		cout << C[i] << " ";
	cout << endl;
	//------------------------------------------------
	selectSort(C, size2);
	cout << "������������ ���������� �������: \n";

	cout << "�������������� ������ c: ";
	for (i = 0; i < size2; i++)
		cout << C[i] << " ";
	cout << endl;
	//------------------------------------------------
	cout << "������� ������ C � ������� ���������\n";

	size22 = 0;
	for (i = 0; i < size; i++)
	{
		if (A[i] % 2 != 0)
		{
			C2[size22] = A[i];
			size22++;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (B[i] % 2 == 0)
		{
			C2[size22] = B[i];
			size22++;
		}

	}
	cout << " ������ C: ";
	for (i = 0; i < size22; i++)
		cout << C2[i] << " ";
	cout << endl;
	//------------------------------------------------
	cout << "������������ ���������� �����: \n";
	insertSort(C2, size22);
	cout << "�������������� ������ c: ";
	for (i = 0; i < size22; i++)
		cout << C2[i] << " ";
	cout << endl;
	system("pause");
}

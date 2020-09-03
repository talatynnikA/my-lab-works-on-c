#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, j=0, sz, A[N], B[N];
	int rmn = 0, rmx = 99, kmax = 0;
	cout << "Введите размер массива ";
	cin >> sz;
	cout << "Массив А:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand()));
		  A[i] = rand() % rmx;
		cout << A[i] << endl;
	}
	for (i = 0; i < sz; i++)
	if (A[i] > A[kmax])
		kmax = i;
	cout << "Максимальный элемент " << A[kmax] << endl;
	for (i = 0; i < sz; i++)
	{
		if (A[i] % 2 == 1)
			B[i] = A[kmax];
		else B[i] = A[i];
	}
	/*if (i % 2 == 1)
	{
		B[j] = A[i];
		A[i] = i;
		j++;
	}*/
	cout << "Массив В:" << endl;
	for (i = 0; i < sz; i++)
		cout << B[i] << endl;
	
	system("pause");
}

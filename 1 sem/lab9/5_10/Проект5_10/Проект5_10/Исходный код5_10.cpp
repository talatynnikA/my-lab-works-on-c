#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, j = 0, sz, A[N], B[N];
	int rmn = 0, rmx = 99, k;
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
		k = (A[sz - 1] + A[sz - 2] + A[sz - 3]) / 3;
		cout << "среднее арифметическое равно:" << endl;
		cout << k << endl;
	for (i = 0; i < sz; i++)
	{
		if (A[i] == k)
			cout << "Элемент равный среднему арифметическому найден, его номер: " << i+1 <<endl;
		else cout << "Элемент не равен среднему арифметическому" << endl;
	}


	system("pause");
}

#include <iostream>
#include <ctime>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 100;
	int i, j = 0, sz, A[N], B[N];
	int rmn = 0, rmx = 99, k;
	cout << "������� ������ ������� ";
	cin >> sz;
	cout << "������ �:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++)
	{
		A[i] = (int)(((double)rand()));
		A[i] = rand() % rmx;
		cout << A[i] << endl;
	}
		k = (A[sz - 1] + A[sz - 2] + A[sz - 3]) / 3;
		cout << "������� �������������� �����:" << endl;
		cout << k << endl;
	for (i = 0; i < sz; i++)
	{
		if (A[i] == k)
			cout << "������� ������ �������� ��������������� ������, ��� �����: " << i+1 <<endl;
		else cout << "������� �� ����� �������� ���������������" << endl;
	}


	system("pause");
}

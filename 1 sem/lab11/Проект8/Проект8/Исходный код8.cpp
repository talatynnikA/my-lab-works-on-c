#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n= 6;
	int   z=-1,i, x[n], y[n], a[n*n];
	for (int i = 0; i < n; i++)
	{
		cout << "������ �[" << i << "]: ";
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "������ y:[" << i << "]: ";
		cin >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n;k++)
		if (*(x+i) == *(y+k))
		{
			a[++z] = x[i];
			cout << z << endl;
		}
	}
	for (int i = 0; i <= z; i++)
	{
		cout << "������ a[" << i << "]:" << a[i] << endl;
	}
	system("pause");
}
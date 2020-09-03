#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, h, d = 12.5 * pow(10, -4), sum = 0;  int i;
	const int n = 5;
	for (i = 1; i <= n; i++)
	{
		cout << "Введите a" << i << endl;
		cin >> a;
		sum = sum + pow(a,2);
	}
	h = d + sum;
	cout << "Ответ h = " << h << endl;
	system("pause");
}
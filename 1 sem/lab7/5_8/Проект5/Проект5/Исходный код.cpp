//#include <stdio.h>
//#include <iostream>
//using namespace std;
//void main()
//
//{
//	setlocale(LC_CTYPE, "Russian");
//	
//	float n1 = 6, n2 = 5, sum = 0, sum2 = 0, c = 0.7, a, b, d; int i;
//	const int COUNT = 6;
//	const int COUNT2 = 5;
//	for (int i = 1; i <= COUNT; i++)
//	{
//		cout << "Введите а=" << i << endl;
//		cin >> a;
//		sum = sum + a;
//	}
//	for (int i = 1; i <= COUNT2; i++)
//		{
//		cout << "Введите b=" << i << endl;
//		cin >> b;
//		sum2 = sum + b;
//		d = a * n1 * 1 - c * (pow(b - 1, 2)*n2 * 1);
//		cout << d;
//		}
//		system("pause");
//}
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, b, sum = 0, c = 0.7, sum2 = 0; int i;
	const int n1 = 6;
	for (i = 1; i <= n1; i++)
	{
		cout << "Введите a" << i << endl;
		cin >> a;
		sum = sum + a;
	}
	const int n2 = 5;
	for (i = 1; i <= n2; i++)
	{
		cout << "Введите b" << i << endl;
		cin >> b;
		sum2 = sum2 + pow(b - 1, 2);
	}
	cout << "Ответ " << sum - c * sum2 << endl;
	system("pause");
}
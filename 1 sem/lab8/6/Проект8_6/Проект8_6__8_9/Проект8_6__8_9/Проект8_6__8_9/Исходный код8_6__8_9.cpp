#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float a = 3, b = 6, n = 200, h = 0, x = 0, s = 0, s1 = 0, s2 = 0, j = 1;
	h = (b - a) / n;
	x = a;
	do
	{
		s += h*((pow(x, 3) + 3) + ((pow(x, 3) + 3 + h))) / 2;

		x = x + h;

	}
	while (x <= (b - h));
	cout << s << endl;
	/*{
	метод трапеций
	/*}*/
	system("pause");
}
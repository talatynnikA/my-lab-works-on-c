#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, b, n, h, x, s;
	cout << "¬ведите a, b, n" << endl;
	cin >> a >> b >> n;
	h = (b - a) / n;
	x = a;
	s = 0;
	s = s + h*((1 + pow(x, 3)) + ((1 + pow(x, 3) + h) / 2));
	x = x + h;
	if (x <= (b - h))

		cout << s << endl;
	else
		s = s + h*((1 + pow(x, 3)) + ((1 + pow(x, 3) + h) / 2));
	x = x + h;
	/*{
	cout << s << endl;
	s = s + h*((pow(x, 3) - 1) + ((pow(x, 3) - 1 + h) / 2));

	x = x + h;

	cout << s << endl;*/
	/*}*/
	system("pause");
	return 0;
}
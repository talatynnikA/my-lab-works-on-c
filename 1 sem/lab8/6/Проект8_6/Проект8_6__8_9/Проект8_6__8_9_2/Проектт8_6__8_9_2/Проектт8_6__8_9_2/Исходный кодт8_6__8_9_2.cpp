#include <iostream>
using namespace std;
void main()
{
	float a = 3, b = 6, n = 200, x = 0, h = 0, s1 = 0, s2 = 0, s = 0, i = 1;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do
	{
		s2 = s2 + (pow(x, 3) + 3);
		x = x + h;
		s1 = s1 + (pow(x, 3) + 3);
		x = x + h;
		i++;
	} while (i < n);
	s = (h / 3)*((pow(a, 3) + 3) + 4 * (pow(a, 3) + 3) + 4 * s1 + 2 * s2 + (pow(b, 3) + 3));
	cout << s << endl;
	system("pause");// метод парабол
}

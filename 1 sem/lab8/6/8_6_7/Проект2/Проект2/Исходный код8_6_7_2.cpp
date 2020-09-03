#include <iostream>
using namespace std;
void main()
{
	float a = 5, b = 11, n = 200, x = 0, h = 0, s1 = 0, s2 = 0, s = 0, i = 1;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do
	{
		s2 = s2 + exp(x) + 2;
		x = x + h;
		s1 = s1 + exp(x) + 2;
		x = x + h;
		i++;
	} while (i < n);
	s = (h / 3)*((exp(a) + 2) + 4 * (exp(a + h) + 2) + 4 * s1 + 2 * s2 + (exp(b) + 2));
	cout << s << endl;
	system("pause"); // метод паарбол

}

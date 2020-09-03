#include <iostream>
using namespace std;
void main()
{
	float a = 0, b = 3, n = 400, x = 0, h = 0, s1 = 0, s2 = 0, s = 0, i = 1;
	h = (b - a) / (2 * n);
	x = a + 2 * h;
	do
	{
		s2 = s2 + (pow(x, 3) - 1);
		x = x + h;
		s1 = s1 + (pow(x, 3) - 1);
		x = x + h;
		i++;
	} 
	while (i < n);
	s = (h / 3)*((pow(a, 3) - 1) + 4 * (pow(a, 3) - 1) + 4 * s1 + 2 * s2 + (pow(b, 3) - 1));
	cout << s << endl;
	system("pause");// метод парабол
}

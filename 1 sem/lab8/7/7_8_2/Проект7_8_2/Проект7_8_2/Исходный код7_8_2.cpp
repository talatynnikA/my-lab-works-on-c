#include<iostream>
using namespace std;
float f(float x)
{
	return pow(x, 3) + x - 2;
}
float g(float a, float b)
{
	return (a + b) / 2;
}
void main()
{
	float a = -1, b = 3, x, e = 1e-4;
	do
	{
		x = g(a, b);
		f(x)*f(a) <= 0 ? b = x : a = x;
	} while (abs(a - b) > 2 * e);
	cout << x << endl;
	system("pause");
}
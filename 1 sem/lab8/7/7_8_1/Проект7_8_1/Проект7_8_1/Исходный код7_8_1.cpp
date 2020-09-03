#include<iostream>
using namespace std;
float f(float x)
{
	return pow(x, 3) + x - 2;

}
float df(float x)
{
	return 3 * pow(x, 2);
}
float dff(float x)
{
	return 1;
}
void main()
{
	float a = -1, b = 5, e = 1e-4, x1, x;
	f(a)*dff(a) > 0 ? x1 = a : x1 = b;
	do
	{
		x = x1;
		x1 = x - f(x) / df(x);
	} while (abs(x1 - x) > e);
	cout << x1 << endl;
	system("pause");
}
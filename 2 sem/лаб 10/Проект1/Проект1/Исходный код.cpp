#include <iostream>

using namespace std;

float f(float x) {
	return x * x - 1;
}

float Dicho(float a, float b, float eps) {
	float c = (a + b) / 2;
	if (f(c) == 0 || (b - a) < 2 * eps) return c;
	if (f(a) * f(c) <= 0) return Dicho(a, c, eps);
	if (f(a) * f(c) > 0) return Dicho(c, b, eps);

	return Dicho(a, b, eps);
}

int main()
{
	float a, b, eps;
	cout << "enter a:\n";
	cin >> a;
	cout << "enter b:\n";
	cin >> b;
	cout << "enter eps:\n";
	cin >> eps;
	cout << Dicho(a, b, eps);

	system("pause");
	return 0;
}
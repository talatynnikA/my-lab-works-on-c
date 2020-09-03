#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float a, b, n, h, s = 0, s1, s2, i, x;
	printf("¬ведите значени€ a, b и n");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &n);
	h = (b - a) / h;
	x == a;
	s = s + h*(pow(cos(x), 3) + pow(cos(x + h), 3)) / 2;
	x = x + h;
	if (x > (b - h))
		printf("s = ", &s);
	else
	{
		s = s + h*(pow(cos(x), 3) + pow(cos(x + h), 3)) / 2;
		x = x + h;
	}


}
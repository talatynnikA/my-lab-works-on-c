#include <stdio.h>
#include <cmath>
#include <iostream>

void main()
{
	setlocale(LC_CTYPE, "Russian");
	float w, s, y, t = -7.4, n = 9, j = 0.1;
	const float e = 2.71828;

	do
	{
		printf("¬ведите y ");
		scanf_s("%f", &y);
		w = 0.6 * j + pow(e, t * j) * pow(4 * y / n, 2);
		s = sqrt(w - 0.1 * t) / (2 + pow(n, 2));
		printf("j = %5.2f\t", j);
		printf("y = %5.2f\n", y);
		printf("w = %5.2f\n", w);
		printf("t = %5.2f\n", t);
		printf("s = %5.2f\n", s);
		j = j + 0.1;
	} while (j < 0.4);
	system("pause");
}

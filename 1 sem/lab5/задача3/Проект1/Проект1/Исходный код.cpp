#include <stdio.h>
#include <cmath>

void main()
{
	float w, s, t = -7.4, n = 9, y = 5, j = 0;
	const float e = 2.71828;
	do
	{
		w = 0.6 * j + pow(e, t * j);
		s = sqrt(w - 0.1 * t) / (2 + pow(n, 2));
		printf("j = %5.2f\t", j);
		printf("y = %5.2f\n", y);
		printf("w = %5.2f\n", w);
		printf("t = %5.2f\n", t);
		printf("s = %5.2f\n", s);
	j = j + 0.1;
		
	} while (j < 2.1);

}













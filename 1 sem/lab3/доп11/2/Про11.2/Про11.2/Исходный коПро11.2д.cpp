#include<iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int d, S;
	printf("¬ведите d=");
	scanf_s("%d", &d);
	if (d != 0)
		S = 0.5*pow(d, 2),
		printf("ѕлощадь квадрата S= %d, ", S);
	else printf("диагональ не может быть равна нулю");
	system("pause");
}

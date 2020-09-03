#include <iostream>
#include <stdio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int N, K, ost, evr;
	printf("Введите N=");
	scanf_s("%d", &N);
	printf("Введите K=");
	scanf_s("%d", &K);
	evr = K / N;
	ost = K % N;
	printf("Каждому достанется яблок %d, ", evr );
	printf(" Остаток в корзине %d, ", ost);
	system("pause");

}
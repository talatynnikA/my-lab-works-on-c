#include <iostream>
#include <stdio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int N, K, ost, evr;
	printf("������� N=");
	scanf_s("%d", &N);
	printf("������� K=");
	scanf_s("%d", &K);
	evr = K / N;
	ost = K % N;
	printf("������� ���������� ����� %d, ", evr );
	printf(" ������� � ������� %d, ", ost);
	system("pause");

}
#include<iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int d, S;
	printf("������� d=");
	scanf_s("%d", &d);
	if (d != 0)
		S = 0.5*pow(d, 2),
		printf("������� �������� S= %d, ", S);
	else printf("��������� �� ����� ���� ����� ����");
	system("pause");
}

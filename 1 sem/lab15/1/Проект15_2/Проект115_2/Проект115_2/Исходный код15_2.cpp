//Задание №2.Написать программу, которая записывает строку в обратном порядке.

#include <iostream>
#include <stdio.h>
void letters(char *str);
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char s[256];
	cout << "Введите строку:" << endl;
	gets_s(s);
	letters(s);
	system("pause");
}
void letters(char *str)
{
	int i = 0;
	i = strlen(str) - 1;
	while (i >= 0)
	{
		cout << str[i];
		i--;
	}
}
#include <string.h>
#include <iostream>
#include <locale>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char str[] = { '�', '�', '�', '�', ' ', '�', ' ', '�', '�', '�', '�', '�', ' ', '�', '�', '�', '�', '�', ' ', '�', '�', '�', '�', '�', '�' };
	int i, j;
	for (int i = 1; str[i] != 0; i++)
	{
		if (str[i] == ' ')
		{
			cout << str[i - 1] << endl;
		}


		

	}
	system("pause");
}
	


#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int n = 6;
	int   z = -1, i;
	char x[] = { 'H', 'E', 'L', 'L', 'O','\0'};
	char y[] = { 'H', 'E', 'L', 'I', 'O', '\0' };
	char a[n]; char *pr=x;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		if (*(x+i) == y[k])
		{
			a[++z] = x[i];
			cout << z << endl;
		}
	}
	for (int i = 0; i <= z; i++)
	{
		cout << "совпадает элемент[" << i << "]:" << a[i] << endl;
	}
	system("pause");
}
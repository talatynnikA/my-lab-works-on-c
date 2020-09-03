#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float  b, g, pro = 1, c = -0.045; int i;
	const int m = 4;
	for (i = 1; i <= m; i++)
	{
		cout << "Введите b" << i << endl;
		cin >> b;
		pro = pro * pow(b+1,2);
	}
	g = c * pro;
		cout << "Ответ " << g << endl;
	system("pause");
}
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A=151, B=115, m,n, i, mask = 0;
	
	/*cout << "Первое число="; cin >> A;
	cout << "Второе число="; cin >> B;*/
	cout << "введите n="; cin >> n;
	cout << "Введите m="; cin >> m;
	for (i = n - 1; i < n - 1 + 3; i++)
	{
		mask = mask + pow(2, i);
	}
	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;
	_itoa_s(mask, tmp, 2);
	cout << "Маска для А: " << tmp << endl;
	_itoa_s((A & mask) >> (n-1), tmp, 2);
	cout << "Выделенные биты А: " << tmp << endl;
	_itoa_s(~((mask>>(n-1))<<(m-1)), tmp, 2);
	cout << "Маска для В: " << tmp << endl;
	_itoa_s(B & ~((mask >> (n - 1)) << (m - 1)), tmp, 2);
	cout << " Очищены биты в B: " << tmp << endl;
	_itoa_s(((B & ~((mask >> (n - 1)) << (m - 1))) | (((A & mask) >> (n-1))<<(m-1))), tmp, 2);
	cout << " Результат B=" << tmp << endl;
	

	system("pause");
}

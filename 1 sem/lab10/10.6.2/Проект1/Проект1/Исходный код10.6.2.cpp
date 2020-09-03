#include <iostream>
#include <string>
using namespace std;

void main()

{

	setlocale(LC_CTYPE, "Russian");

	char tmp[33];

	int a=150, n=4, p=2, maska;

	//cout << "A в 10 = "; cin >> a;

	//cout << "кол-во n = "; cin >> n;

	//cout << "позиция p = "; cin >> p;

	_itoa_s(a, tmp, 2); cout << "A в 2 = " << tmp << endl;

	maska = 15;
	maska = ~(maska);
	_itoa_s(maska, tmp, 2);
	cout << maska << tmp << endl;
	_itoa_s( maska << 1, tmp, 2);
	_itoa_s((a & maska)<<1, tmp, 2);

	cout << tmp << endl;

	system("pause");

}
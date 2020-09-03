#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char tmp[33];
	int A, B, maskA;
	cout << "введите число А" << endl;
	cin >> A;
	cout << "введите число B" << endl;
	cin >> B;
	_itoa_s(A, tmp, 2); cout << "A=" << tmp << endl;
	_itoa_s(B, tmp, 2); cout << "B=" << tmp << endl;
	maskA = (A >> 2) & 31;
	B &= ~(31 << 1);
	_itoa_s(B|(maskA<<1), tmp, 2); cout << "B=" << tmp << endl;
	system("pause");
}

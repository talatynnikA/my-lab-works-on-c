#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int A = 150; char tmp[33];
	_itoa_s(A, tmp, 2);
	cout << " ����� �: " << tmp << endl;
	_itoa_s(36, tmp, 2);
	cout << " ����� ��� �: " << tmp << endl;
	_itoa_s(A & ~36, tmp, 2);
	cout << " ���������: " << tmp << endl << endl;


	system("pause");
}


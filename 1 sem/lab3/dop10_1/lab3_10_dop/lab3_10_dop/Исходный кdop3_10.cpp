#include <iostream>
#include <iomanip> 
void main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	char c, probel; probel = ' ';
	cout << "vvedite simvol "; cin >> c;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	/*cout << setw(34) << setfill(probel) << probel;
	cout << setw(6) << setfill(c) << c << endl;*/
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(8) << setfill(c) << c << endl;
	cout << setw(32) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(31) << setfill(probel) << probel;
	cout << setw(12) << setfill(c) << c << endl;
	cout << setw(32) << setfill(probel) << probel;
	cout << setw(10) << setfill(c) << c << endl;
	cout << setw(33) << setfill(probel) << probel;
	cout << setw(8) << setfill(c) << c << endl;
	cout << setw(35) << setfill(probel) << probel;
	cout << setw(4) << setfill(c) << c << endl;
	system("pause");
}
//#include <iostream>
//void main()
//{
//
//	setlocale(LC_CTYPE, "Russian");
//	int t;
//	cout << "Введите t=";
//	cin >> t;
//	cout << "t=" << t << endl;
//	cout << "Тип Размер в байтах" << endl;
//	cout << "int: " << sizeof(int) << endl;
//	cout << "char: " << sizeof(char) << endl;
//	cout << "float: " << sizeof(float) << endl;
//	cout << "double: " << sizeof(double) << endl;
//	// sizeof определяет размер объекта в бай-тах
//}
//#include <iomanip> 
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	using namespace std;
//	char c, probel; probel = ' ';
//	cout << "Введите символ "; cin >> c;
//	cout << setw(35) << setfill(probel) << probel;
//	cout << setw(10) << setfill(c) << c << endl;
//	cout << setw(34) << setfill(probel) << probel;
//	cout << setw(12) << setfill(c) << c << endl;
//	cout << setw(33) << setfill(probel) << probel;
//	cout << setw(14) << setfill(c) << c << endl;
//}
//#include <iostream>
//void main()
//{
//	double t, u, k = 4, a = 4.1, x = 5e-5;
//	t = 2 * tan(k) / a * log(abs(3 + x)) + exp(x);
//	u = sqrt(t + 1) * (sin(x) * cos(t));
//	std::cout << "t=" << t;
//	std::cout << "u=" << u;
//	system("pause");
//}
//#include <iostream>
//void main()
//{
//	float x = 3, y;
//	y = x * x + sin(x);
//	std::cout << y;
//	system("pause");
//}
//#include <iostream>
//void main()
//{
//	double t, u, k = 4, a = 4.1, x = 5e-5;
//	t = 2 * tan(k) / a * log(abs(3 + x)) + exp(x);
//	u = sqrt(t + 1) * (sin(x) * cos(t));
//	std::cout << "t=" << t;
//	std::cout << "u=" << u;
//	system("pause");
//}

//#include <iostream>
//
//using namespace std;
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int t;
//	cout << "vvedite t=";
//	cin >> t;
//	cout << "t=" << t << endl;
//	cout << "tip razmer v byteah" << endl;
//	cout << "int: " << sizeof(int) << endl;
//	cout << "char: " << sizeof(char) << endl;
//	cout << "float: " << sizeof(float) << endl;
//	cout << "double: " << sizeof(double) << endl; 
//	system("pause");
//	// sizeof определяет размер объекта в бай-тах
//}
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b, c, p, S;
	cout << "vvedite a=";
	cin >> a;
	cout << "vvedite b=";
	cin >> b;
	cout << "vvedite c=";
	cin >> c;
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	std::cout << "p=" << p << '\n';
	std::cout << "S=" << S;
	system("pause");
}
#include <iostream>


using namespace std;
void main()
{
	double w, d, a = 1.5, x = -1.8, z = 15 * pow(10, -9), e = 2.71828;
	w = tan(1) * (1 + x) + z - pow(e,a);
	d = 9 * sqrt(2 - 3 * x) + abs(a + 1);
	std::cout << "w=" << w << "\n";
	std::cout << "d=" << d << "\n";
	system("pause");

}

#include <iostream>
void main()
{
	double a = 1.5, b=-8.1, j=4,t=4*pow(10,-8), s, w, v;
	s = sqrt(t*a / (t + 1)) + 4 * exp(2 * b);
	w = s*a/(1+0.1*a);
	v = s+j*sqrt(pow(a,2)+pow(b,2));
	std::cout << "s=" << s << "\n";
	std::cout << "w=" << w << "\n";
	std::cout << "v=" << v;
	system("pause");
}
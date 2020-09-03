#include <iostream>
void main()

{

	double s, t, x = 0.1, j = 12, y = 5e-6;
	s = 0.4 * x - 1 / j * tan(y);
	t = s - sin(s);
	std::cout << "s=" << s << std::endl;
	std::cout << "t=" << t << std::endl;

}

#include <iostream>
using namespace std;
void main()
{
	float w, s, t = -7.4, n = 9, y = 5, j = 0;
	const float e = 2.71828;
	while (j < 2.1)
	{
		
		w = 0.6 * j + pow(e, t * j) * pow(4 * y / n, 2);
		s = sqrt(w - 0.1 * t) / (2 + pow(n, 2));
		cout << "j=" << j << "\t";
		cout << "w=" << w << "\t";
		cout << " s=" << s << endl;
		j = j + 0.1;
	}
	system("pause");
}

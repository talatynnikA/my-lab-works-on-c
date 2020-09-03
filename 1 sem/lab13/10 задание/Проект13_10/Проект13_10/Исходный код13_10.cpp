#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int c_n = 3;
	const int c_m = 2;
	int B[c_n][c_m] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	int n, m, s=1;
	for (n = 0; n < c_n; n++)
	for (m = 0; m < c_m; m++)
		std::cout << "\n B[" << n << "," <<
		m << "] =" << B[n][m];
	cout << endl;
	for (n = 0; n < c_n; n++)
	for (m = 1; m < c_m; m =m+2)
	if (B[n][m] % 2 == 0)
	{
		/*s = s*B[n][m];*/
		s = s**(*(B + n) + m);
	}
		cout << s << endl;
	system("pause");
}
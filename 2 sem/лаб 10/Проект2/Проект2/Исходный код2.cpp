#include <iostream>
#include <cstdlib>

using namespace std;


unsigned int f(unsigned int m, unsigned int n)
{
	if (m == 0 || n == 0)
	{
		return n + 1;
	}
	else
	{
		return f(m - 1, f(m, n - 1));

	}
}

int main()
{
	unsigned int m, n;
	cout << "enter m:\n";
	cin >> m;
	cout << "enter n:\n";
	cin >> n;
	cout << "f = :\n";
	cout << f(m, n) << endl;
	system("PAUSE");
}
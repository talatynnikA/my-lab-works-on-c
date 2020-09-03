#include <iostream>
#include <iomanip>
#define setw setw(6)<<setfill('0')
using namespace std;

int main()
{
	for (int i = 0; i < 999999; i++)
	if (i % 7 == 0 && (i + 1) % 7 == 0)
		cout << setw << i << " && " << setw << i + 1 << endl;
	else if (i % 10000 == 9999) {
		if (i % 7)
			cout << setw << i << " !!! " << i % 7 << endl;
		else
			cout << "# " << (i + 1) % 7 << endl;
	}
	system("pause");
}

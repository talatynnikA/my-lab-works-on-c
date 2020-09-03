#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	const int c_i = 3;
	const int c_j = 2;
	int a[c_i][c_j] = { { 1, 2 }, { 4, 4 }, { 5, 6 } };
	int i, j, bol=0,men=0,ravn=0;
	for (i = 0; i < c_i; i++)
	for (j = 0; j < c_j; j++)
		std::cout << "\n a[" << i << "," <<
		j << "] =" << a[i][j];
	cout << endl;
	int b[c_i][c_j] = { { 2, 9 }, { 3, 5 }, { 6, 6 } };
	for (i = 0; i < c_i; i++)
	for (j = 0; j < c_j; j++)
		std::cout << "\n b[" << i << "," <<
		j << "] =" << b[i][j];
	cout << endl;
	for (i = 0; i < c_i;i++)
	for (j = 0; j < c_j; j++)
	{
		//if (a[i][j] < b[i][j])
		if (*(*(a + i) + j) < *(*(b + i) + j))
			men++;

		if (a[i][j] == b[i][j])
			ravn++;

		if (a[i][j] > b[i][j])
			bol++;
	}
	cout << men << endl;
	cout << bol << endl;
	cout << bol << endl;
	system("pause");
}

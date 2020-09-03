//#include <iostream>
//using namespace std;
//void main()
//{
//	float w, s, e = 1.06, y = 5, t = -7.4, n = 9, j = {0.5, 8.4, 0.3};
//	while (j < 2)
//	{
//		w = 0.6 * j + pow(e, t * j);
//		s = sqrt(w - 0.1 * t) / (2 + pow(n, 2));
//		cout << "w=" << w << "\t";
//		cout << " s=" << y << endl;
//		j = j + 0.1;
//	}
//	system("pause");
//}
#include <iostream>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float w, s, y, t, n, j;
	const float e = 2.71828;
	for (int n = 1; n <= 9; n++)
	{
		printf("¬ведите j ");
		scanf_s("%f", &j);
		printf("¬ведите y ");
		scanf_s("%f", &y);
		printf("¬ведите t ");
		scanf_s("%f", &t);
		w = 0.6 * j + pow(e, t * j) * pow(4 * y / n, 2);
		s = sqrt(w - 0.1 * t) / (2 + pow(n, 2));
		printf("j = %5.2f\t", j);
		printf("y = %5.2f\n", y);
		printf("w = %5.2f\n", w);
		printf("t = %5.2f\n", t);
		printf("s = %5.2f\n", s);
	}
	system("pause");
}
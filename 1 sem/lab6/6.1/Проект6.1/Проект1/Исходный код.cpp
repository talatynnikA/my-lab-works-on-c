#include <iostream>								// начало
using namespace std;
void main()
{
	
	setlocale(LC_CTYPE, "Russian");
	float b = 3, i=8, c = 6*pow(10,-4), a=6,t,x, // получение исходных данных
	const e = 2.71828;
	while (i<28)								// если i меньше 28 выполняются следующие действия
	{											// (если i больше 28 переходим в конец)
		
			t = a*i/(pow(a,2)-b)*pow(e,-a);     // вычисляем t равное a*i/((a^2)-b)*(e^-a)
			if (t>5 * c) x = 4.8*pow(10, -3) + i*a; // если t>5c x=4.8*(10^-3)+i*a
			else x = a+pow(i,2)*t;				// если нет значит t меньше либо равно 5c и х будет равен a+(i^2)*t
			printf("b = %5.2f\t", b);          //выводим полученные t и x     
			printf("i = %5.2f\n", i);		  
			printf("c = %5.2f\n", c);
			printf("a = %5.2f\n", a);
			printf("t = %5.2f\n", t);
			printf("x = %5.2f\n", x);
			i = i + 4;						  // к i добавляем 4 и возвращаемся в начало
	}
	system("pause");
}											 // конец
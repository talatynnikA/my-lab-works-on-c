#include <iostream>
using namespace std;
void main()
{
	float a = 5, b = 11, n = 200, x = 0, h = 0, s1 = 0, s2 = 0, s = 0, i = 1;  //1. Ввод a, b, n.
	h = (b - a) / n;															//2. Вычисление h = (b - a) / n, x = a , s = 0.
	x = a;
	do
	{
		s += h*(exp(x) + 2 + exp(x + h) + 2 + b) / 2;							//3. Расчет s = s + h * ( f(x) + f(x + h)) / 2, x = x + h.
		x = x + h;
	} 
	while (x <= b - h);															//4. Если x > (b – h), то переход к пункту 5, иначе – переход к пункту 3.
	cout << s << endl;															//5. Вывод s
	system("pause"); //метод трапеций
}

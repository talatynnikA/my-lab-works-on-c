//�������� ��������� ��� ���������� ������������� ��������� �� �������, ����������� ����, ������� �������� � ������� �������: x^3 � 1. n = 200
#include <stdio.h>
#include <iostream>

using namespace std;
float integ(float(*) (float), float, float, float);
float f(float);
int main()
{

	setlocale(LC_CTYPE, "Russian");
	float s;
	s = integ(f, (float)0.0, (float)3.0, (float)0.0);								 //1. ���� a, b, n
	std::cout << "��������=" << s;													//5. ����� s
	system("pause");
}
	float integ(float(*f) (float), float a, float b, float h)
	{
		float  n = 400,  x = 0, s = 0, s1 = 0, s2 = 0, j = 1; 
		h = (b - a) / n;														  //2. ���������� h = (b - a) / n, x = a , s = 0.
		x = a;

		do
		{
			s += h*f(x);					//3. ������ s = s + h * ( f(x) + f(x + h)) / 2, x = x + h.

			x = x + h;

		} 
		while (x <= (b - h));				//4. ���� x > (b � h), �� ������� � ������ 5, ����� � ������� � ������ 3.
		return s/2;
		
	}
	float f(float x)
	{
		return (pow(x, 3) - 1);
	}
														

 
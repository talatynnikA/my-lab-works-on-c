#include <iostream>								// ������
using namespace std;
void main()
{
	
	setlocale(LC_CTYPE, "Russian");
	float b = 3, i=8, c = 6*pow(10,-4), a=6,t,x, // ��������� �������� ������
	const e = 2.71828;
	while (i<28)								// ���� i ������ 28 ����������� ��������� ��������
	{											// (���� i ������ 28 ��������� � �����)
		
			t = a*i/(pow(a,2)-b)*pow(e,-a);     // ��������� t ������ a*i/((a^2)-b)*(e^-a)
			if (t>5 * c) x = 4.8*pow(10, -3) + i*a; // ���� t>5c x=4.8*(10^-3)+i*a
			else x = a+pow(i,2)*t;				// ���� ��� ������ t ������ ���� ����� 5c � � ����� ����� a+(i^2)*t
			printf("b = %5.2f\t", b);          //������� ���������� t � x     
			printf("i = %5.2f\n", i);		  
			printf("c = %5.2f\n", c);
			printf("a = %5.2f\n", a);
			printf("t = %5.2f\n", t);
			printf("x = %5.2f\n", x);
			i = i + 4;						  // � i ��������� 4 � ������������ � ������
	}
	system("pause");
}											 // �����
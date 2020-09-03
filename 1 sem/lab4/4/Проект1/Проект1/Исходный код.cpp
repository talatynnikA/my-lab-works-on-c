//#include <iostream>
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	float x, y, z, mn, mx;
//	printf("vvedite x "); scanf_s("%f", &x);
//	printf("vvedite y "); scanf_s("%f", &y);
//	printf("vvedite z "); scanf_s("%f", &z);
//	if ((x + y + z) < (x * y * z))
//		mx = (x * y * z);
//	else
//		mx = (x + y + z);
//	mn = x;
//	if (mn > y) mn = y;
//	if (mn > z) mn = z;
//	printf("max(x + y + z, xyz) * min(x, y, z) = %f \n", mn*mx);
//	system("pause");
//}

#include <iostream>
#include <stdio.h>
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a, b, k, buf;
	printf("vvedite a="); scanf_s("%d", &a);
	printf("vvedite b="); scanf_s("%d", &b);
	printf("vvedite k="); scanf_s("%d", &k);
	if
		(a < k)
	buf = k, k = a, a = buf;
	
	
	if  
		(a < b)
			buf = b, b = a, a = buf;
	
	if
		(b < k)
		buf = b, b = k, k = buf;
		printf("%d > %d > %d", a, b, k);
	  
	system("pause");
}       
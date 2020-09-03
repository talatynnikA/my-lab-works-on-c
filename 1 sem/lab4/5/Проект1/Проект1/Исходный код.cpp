#include <iostream>
#include <stdio.h>
void main()
{
	int a, b, c, d, e;
	printf("vvedite 4-ex znachnoe chislo = "); scanf_s("%d", &a);
	 b = a / 1000;
	 c = (a - b * 1000) / 100;
     d = (a - b * 1000 - c * 100)/10;
	 e = a % 10;
	 if ((a != b), (a != c), (a != d), (a != e), (b != c), (b != d), (b != e), (c != d), (c != e), (d != e))
		 
	     printf("verno");
	 else
		 printf("neverno");
	 system("pause");
	

}
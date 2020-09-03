
#include <iostream>
#include <stdio.h>

int main()
{
	int a[99], b[99], s[99], n = 0;

	std::cout << "Vvedite razmer massiva: ";
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cout << "Vvedite massiv A = ";
		std::cin >> *(a + i);
	}

	for (int i = 0; i < n; i++) {
		std::cout << "Vvedite massiv B = ";
		std::cin >> *(b + i);
	}

	for (int i = 0; i < n; i++) {
		*(s + i) = *(a + i) + *(b + i);
	}


	std::cout << "Massiv S = ";

	for (int i = 0; i < n; i++) {
		std::cout << *(s + i) << ' ';
	}

	std::cout << '\n';
	system("pause");
}
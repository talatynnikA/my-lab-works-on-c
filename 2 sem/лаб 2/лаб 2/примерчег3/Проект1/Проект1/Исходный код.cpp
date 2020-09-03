//#include <iostream>   
//#include <stdio.h>       
//int main(void)
//{
//	setlocale(LC_CTYPE, "Russian");
//	FILE *fp;
//	errno_t err;
//	char const *st = "привет";
//	err = fopen_s(&fp, "a.bin", "w");
//	if (err != 0)
//	{
//		perror("ошибка открытия a.txt");
//		return EXIT_FAILURE;
//	}
//	fwrite(st, strlen(st), 1, fp);
//	printf("Записан элемент\n");
//	fclose(fp);
//	system("pause");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	int m = 0, number = 0, pr = 0;
//	long fsize;
//	char pd;
//	FILE *fd;
//	errno_t err;
//	err = fopen_s(&fd, "b.txt", "r");
//	if (err != 0)
//	{
//		perror("ошибка открытия a.txt");
//		system("pause");
//		return;
//	}
//	fseek(fd, 0L, SEEK_END);
//	fsize = ftell(fd);
//	fseek(fd, 0L, SEEK_SET);
//	printf("Введите номер предложения ");
//	scanf_s("%d", &number);
//	for (int k = 1; k <= fsize; k++)
//	{
//		fread((void*)&pd, sizeof(char), 1, fd);
//		if (pd == '.')   pr++;
//		if ((number - 1) == pr)  m++;
//		if (number == pr)
//		{
//			long pos1 = k - m - 1;
//			if (number != 1) pos1++;
//			fseek(fd, pos1, SEEK_SET);
//			printf("%d-е предложение: ", number);
//			for (int i = 0; i <= m; i++)
//			{
//				fread((void*)&pd, sizeof(char), 1, fd);
//				printf("%c", pd);
//			}
//			break;
//		}
//	}
//	if (number > pr)
//		printf("Такого номера нет");
//
//	fclose(fd);
//	
//}
//#include <stdio.h>
//#include <iostream>
//int main()
//{
//	setlocale(LC_ALL, "");
//	int a; errno_t err;
//	FILE *f;
//	err = fopen_s(&f, "a.txt", "w");
//	if (err != 0)
//	{
//		perror("Невозможно создать файл\n");
//		return EXIT_FAILURE;
//	}
//	for (a = 0; a < 70; a += 3)
//	{
//		fprintf_s(f, "%d, ", a);
//	}
//	printf_s("Данные записаны в файл a.txt\n");
//	fclose(f);
//		
//	return 0;
//	system("pause");
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <memory.h>
//#include <time.h>
//
//#define N 25
//
//int main(int argc, char* argv[])
//{
//	int* A = new int[2 * N];
//	memset((void*)A, 0x00, sizeof(int)* 2 * N);
//
//	srand((unsigned)time(NULL));
//
//	for (int i1 = 0; i1 < N; i1++)
//	{
//		A[i1] = rand() % N + 1;
//		printf("%d ", A[i1]);
//	}
//
//	printf("\n");
//
//	int r = N;
//	for (int i = 1; i <= r; i++)
//	{
//		int k = r;
//		while (--k >= i && (i % 2))
//			A[k + 1] = A[k];
//
//		if (i % 2)
//		{
//			A[i] = -1; r++;
//		}
//	}
//
//	int t = -1, j = r;
//	while (j >= 0 && t <= r)
//		A[t += 2] = A[j -= 2];
//
//	for (int i2 = 0; i2 < 2 * N; i2++)
//		printf("%d ", A[i2]);
//
//	printf("\n");
//
//	return 0;
//}
//Создание и чтение двоичных файлов
#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	int m[10] = { 0 };
	srand((unsigned)time(NULL)); // инициализация датчика случайных чисел
	FILE *stream;
	/* открываем двоичный файл для записи */
	//if((stream = fopen("c:/binfiles/number1.bin", "wb" )) == NULL)
	if ((stream = fopen("number1.bin", "wb")) == NULL)
		return 1; // ошибка при открытии
	/* заполняем массив m числами */
	for (int i = 0; i < 10; i++)
		m[i] = rand() % 10; // случайные числа от 0 до 9
	// заполняем файл number1.bin элементами-числами
	for (int i = 0; i < 10; i++)
		fwrite(&m[i], 1, sizeof(int), stream);
	fclose(stream); // закрываем файл
	/* открываем другой файл для записи */
	//if((stream = fopen("c:/binfiles/number2.bin", "wb" )) == NULL)
	if ((stream = fopen("number2.bin", "wb")) == NULL)
		return 1; // ошибка при открытии
	// заполняем файл number2.bin элементом-массивом
	fwrite(m, 1, sizeof(m), stream); // массив - один элемент
	fclose(stream); // закрываем файл
	// вывод второго двоичного файла на экран
	// открываем файл для чтения
	//if((stream = fopen("c:/binfiles/number2.bin", "rb" )) == NULL)
	if ((stream = fopen("number2.bin", "rb")) == NULL)
		return 1; // ошибка при открытии
	int a = 0; // сюда вводим
	// читаем второй файл поэлементно
	// правильный цикл
	printf("number2.bin\n");
	fread(&a, 1, sizeof(int), stream); // предварительное чтение
	while (!feof(stream)) // пока не конец файла
	{
		printf("%d\n", a);
		fread(&a, 1, sizeof(int), stream);
	}
	fclose(stream);
	// открываем первый файл в режиме чтения
	printf("number1.bin\n");
	//if((stream = fopen("c:/binfiles/number1.bin", "rb" )) == NULL)
	if ((stream = fopen("number1.bin", "rb")) == NULL)
		return 1;
	int t[10] = { 0 }; // массив для чтения
	// читаем первый файл как массив
	fread(t, 1, sizeof(t), stream);
	for (int i = 0; i < 10; i++) // выводим поэлементно
		printf("%d\n", t[i]);
	fclose(stream);
	char ch = getchar();
	return 0;
}

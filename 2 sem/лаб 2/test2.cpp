
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>



#include <string>
using namespace std;


int main(void) {
	int a = 10, A[10], B[10], err, upper = 99, lower = 0;
	FILE *f;
	char * line = NULL;
	size_t len = 0;
	size_t read;
	char *read1;
	

	//input file generation
	err = fopen_s(&f, "input.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < a; i++)
		fprintf(f, "%d\n", ((rand() % (upper - lower + 1)) + lower));
	printf("Данные записаны в файл input.txt\n");
	fclose(f);

	//read input file
	err = fopen_s(&f, "input.txt", "r");
	if (err != 0)
	{
		perror("Невозможно открыть файл\n");
		return EXIT_FAILURE;
	}
	int i = 0;

	while (1) { 
		//printf("%s", line);
	/*	A[i] = atoi(line);
		i++;*/
		fscanf_s(f, "%d", &A[i]);
		if (feof(f) != 0)
			break;
		else i++;
	}
	puts("A: ");
	for (int i = 0; i < a; i++)
		printf("%i ", A[i]);
	fclose(f);
	puts("\n");

	//create new modified array
	int step = 0, N = a;
	for (int i = 0; i < a; i++)
	{
		if (i % 2 == 0)
		{
			B[i] = A[step];
			step++;
		}
		else
		{
			B[i] = A[N - 1];
			N--;
		}
	}
	puts("B: ");
	for (int i = 0; i < a; i++)
		printf("%i ", B[i]);
	puts("\n");

	//save file with the new array
	err = fopen_s(&f, "output.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < a; i++)
		fprintf(f, "%d\n", B[i]);
	printf("Данные записаны в файл output.txt\n");
	fclose(f);

	printf("Pause\n");
	getchar();
	printf("exit\n");
	return EXIT_SUCCESS;
}

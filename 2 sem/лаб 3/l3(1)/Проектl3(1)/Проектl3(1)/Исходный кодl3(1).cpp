////#include "stdafx.h"
//#include <iostream>                    
//# define str_len 30                               
//# define size 30  
//using namespace std;
//void enter_new();
//void del();
//void change();
//void out();
//struct Student
//{
//	char name[str_len];
//	int year_of_birth;
//	char department[5];
//};
//struct Student list_of_student[size];
//struct Student bad;
//int current_size = 0; int choice;
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "Введите:" << endl;
//	cout << "1-для удаления записи" << endl;
//	cout << "2-для ввода новой записи" << endl;
//	cout << "3-для изменения записи" << endl;
//	cout << "4-для вывода записи(ей)" << endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1:  del();	break;
//		case 2:  enter_new();  break;
//		case 3:  change();  break;
//		case 4:  out();	break;
//		}
//	} while (choice != 5);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	if (current_size < size)
//	{
//		cout << "Строка номер ";
//		cout << current_size + 1;
//		cout << endl << "Фамилия " << endl;
//		cin >> list_of_student[current_size].name;
//		cout << "Год рождения " << endl;
//		cin >> list_of_student[current_size].year_of_birth;
//		cout << "Факультет " << endl;
//		cin >> list_of_student[current_size].department;
//		current_size++;
//	}
//	else
//		cout << "Введено максимальное кол-во строк";
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void del()
//{
//	int d;
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
//	if (d != 99)
//	{
//		for (int de1 = (d - 1); de1 < current_size; de1++)
//			list_of_student[de1] = list_of_student[de1 + 1];
//		current_size = current_size - 1;
//	}
//	if (d == 99)
//	for (int i = 0; i < size; i++)
//		list_of_student[i] = bad;
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void change()
//{
//	int n, per;
//	cout << "\nВведите номер строки" << endl; 	cin >> n;
//	do
//	{
//		cout << "Введите: " << endl;
//		cout << "1-для изменения фамилии" << endl;
//		cout << "2-для изменения года рождения" << endl;
//		cout << "3-для изменения факультета" << endl;
//		cout << "4-конец\n";
//		cin >> per;
//		switch (per)
//		{
//		case 1: cout << "Новая фамилия";
//			cin >> list_of_student[n - 1].name;   break;
//		case 2: cout << "Новый год рождения";
//			cin >> list_of_student[n - 1].year_of_birth; break;
//		case 3: cout << "Новый факультет ";
//			cin >> list_of_student[n - 1].department; break;
//		}
//	} while (per != 4);
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
//void out()
//{
//	int sw, n;
//	cout << "1-вывод 1 строки" << endl;
//	cout << "2-вывод всех строк" << endl;
//	cin >> sw;
//	if (sw == 1)
//	{
//		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
//		cout << "Фамилия ";
//		cout << list_of_student[n - 1].name << endl;
//		cout << "Год рождения ";
//		cout << list_of_student[n - 1].year_of_birth << endl;
//		cout << "Факультет ";
//		cout << list_of_student[n - 1].department << endl;
//	}
//	if (sw == 2)
//	{
//		for (int i = 0; i < current_size; i++)
//		{
//			cout << "Фамилия ";
//			cout << list_of_student[i].name << endl;
//			cout << "Год рождения ";
//			cout << list_of_student[i].year_of_birth << endl;
//			cout << "Факультет ";
//			cout << list_of_student[i].department << endl;
//		}
//	}
//	cout << "Что дальше?" << endl;
//	cin >> choice;
//}
#include <iostream>
using namespace std;
void input(int size);
void output();
//void del();
void find(char lastName[]);
typedef struct Pupils
{
	char fio[16];
	char name[16];
	char otch[16];
	char klass[3];
	char predm[20];
	char sub1[20], sub2[20], sub3[20], sub4[20], sub5[20];
	char marks1[20], marks2[20], marks3[20], marks4[20], marks5[20];
	char sr_bal[20];
} STUD;
STUD stud[20];
struct Pupils bad;
int number; FILE *f; errno_t err;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int choice; 
	//char fio[16]; char name[16];
	//char otch[16];
	//char klass[3];
	//char predm[20];
	//char sub1[20], sub2[20], sub3[20], sub4[20], sub5[20];
	//char marks1[20], marks2[20], marks3[20], marks4[20], marks5[20];
	char sr_bal[20];
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по среднему баллу\n";
		cout << "4.Удалениe записи" << endl;
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество учеников: ";
			cin >> number;
			input(number);  break;
		case 2: output(); break;
		case 3: {  cout << "Введите средний балл: ";
			cin >>  sr_bal;
			
			find(sr_bal); break;
		}
		//case 4:  del();	break;
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: "; 	cin >> buf.fio;
			cout << "Имя: "; 	cin >> buf.name;
			cout << "Отчество: "; 	cin >> buf.otch;
			cout << "Класс: "; 	cin >> buf.klass;
			cout << "Предмет1: ";
			cin >> buf.sub1;
			cout << "Предмет2: ";
			cin >> buf.sub2;
			cout << "Предмет3: ";
			cin >> buf.sub3;
			cout << "Предмет4: ";
			cin >> buf.sub4;
			cout << "Предмет5: ";
			cin >> buf.sub5;
			cout << "Оценка 1 предмета: "; 	cin >> buf.marks1;
			cout << "Оценка 2 предмета: ";
			cin >> buf.marks2;
			cout << "Оценка 3 предмета: ";
			cin >> buf.marks3;
			cout << "Оценка 4 предмета: ";
			cin >> buf.marks4;
			cout << "Оценка 5 предмета: ";
			cin >> buf.marks5;
			cout << "Средний балл: "; 	cin >> buf.sr_bal;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		cout << "\nФамилия        Имя            Отчество      Класс     Предмет     Оценка  Средний балл\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub1 << "\t    " << buf.marks1 << "\t    " << buf.sr_bal << endl;
			cout << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub2 << "\t    " << buf.marks2 << "\t    " << buf.sr_bal << endl;
			cout << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub3 << "\t    " << buf.marks3 << "\t    " << buf.sr_bal << endl;
			cout << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub4 << "\t    " << buf.marks4 << "\t    " << buf.sr_bal << endl;
			cout << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub5 << "\t    " << buf.marks5 << "\t    " << buf.sr_bal << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void find(char sredniBal[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "base.bin", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(sredniBal, buf.sr_bal) == 0)   //сравнение строк
			{
				cout << "\nСредний балл  Фамилия        Имя          Отчество        Класс      Предмет\n";
				cout << buf.sr_bal << "\t    " << buf.fio << "\t    " << buf.name << "\t    " << buf.otch << "\t    " << buf.klass << "\t    " << buf.sub1 <<  endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}
//void del(int size)
//{
//	int d;
//	STUD buf;
//	fopen_s(&f, "base.bin", "ab");
//	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;  cin >> d;
//	if (d != 99)
//	{
//		for (int del = (d - 1); del < size; del++)
//			buf[del] = buf[del + 1];
//		size = size - 1;
//	}
//	if (d == 99)
//	for (int i = 0; i < size; i++)
//		buf[i] = bad;
//}

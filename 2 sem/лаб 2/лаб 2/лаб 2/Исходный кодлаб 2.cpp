#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char buff1[50], buff2[100], buff3[150], buff4[200], buff5[250], buff6[300], buff7[350];
	ofstream fout("FILE1.txt");
	fout << "Работа с файлами в С++" << endl; // запись строки в файл
	fout << "Это вторая строка" << endl;
	fout << "Немного текста здесь" << endl;
	fout << "Скопировать из файла 1 в файл 2 все строки, кроме той строки, в которой больше всего гласных букв" << endl;
	fout << "Напечатать номер этой строки" << endl;
	fout << "произвольный текст" << endl;
	fout.close(); // закрываем файл
	cout << "строки записаны в FILE1.txt" << endl;
	string str;
	ifstream fin("File1.txt");    // создание объекта fin класса ifstream для чтения  
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin.getline(buff1, 50); // считывание строки из файла
		cout << buff1 << endl;   // печать строки
		fin.getline(buff2, 100); // считывание строки из файла
		cout << buff2 << endl;   // печать строки
		fin.getline(buff3, 150); // считывание строки из файла
		cout << buff3 << endl;   // печать строки
		fin.getline(buff4, 200); // считывание строки из файла
		cout << buff4 << endl;   // печать строки
		fin.getline(buff5, 250); // считывание строки из файла
		cout << buff5 << endl;   // печать строки
		fin.getline(buff6, 300); // считывание строки из файла
		cout << buff6 << endl;   // печать строки
		fin.getline(buff7, 350); // считывание строки из файла
		cout << buff7 << endl;   // печать строки
	}
	int length, i, j, kol6 = 0, kol1 = 0, kol2 = 0, kol3 = 0, kol4 = 0, kol5 = 0, kol7 = 0;
	char vowel[] = "уеыаоэяию";
	puts(buff1); //принимает buff1
	length = strlen(buff1);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff1[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol1 = kol1 + 1;
	}
	cout << kol1 - 1 << endl;
	kol2 = 0;
	puts(buff2); //принимает buff2
	length = strlen(buff2);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff2[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol2 = kol2 + 1;
	}
	cout << kol2 - 1 << endl;
	kol3 = 0;
	puts(buff3); //принимает buff
	length = strlen(buff3);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff3[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol3 = kol3 + 1;
	}
	cout << kol3 - 1 << endl;
	kol4 = 0;
	puts(buff4); //принимает buff
	length = strlen(buff4);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff4[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol4 = kol4 + 1;
	}
	cout << kol4 - 1 << endl;
	kol5 = 0;
	puts(buff5); //принимает buff
	length = strlen(buff5);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff5[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol5 = kol5 + 1;
	}
	cout << kol5 - 1 << endl;
	kol6 = 0;
	puts(buff6); //принимает buff
	length = strlen(buff6);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff6[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol6 = kol6 + 1;
	}
	cout << kol6 - 1 << endl;
	kol7 = 0;
	puts(buff6); //принимает buff
	length = strlen(buff6);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff6[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
			kol7 = kol7 + 1;
	}
	cout << kol7 - 1 << endl;

	int ans = 0, ans2;
	if (kol1 > ans){
		ans = kol1;
	}
	if (kol2 > ans){
		ans = kol2;
	}
	if (kol3 > ans){
		ans = kol3;
	}
	if (kol4 > ans){
		ans = kol4;
	}
	if (kol5 > ans){
		ans = kol5;
	}
	if (kol6 > ans){
		ans = kol6;
	}
	if (kol7 > ans){
		ans = kol7;
	}
	ans2 = ans - 1;
	cout << ans2 << "гласных максимально" << endl;
	fin.close(); //закрывает файл
	char buff[100];
	ofstream fout1("File2.txt");    // создание объекта fin класса ifstream для чтения  
	
		if (ans2 != kol1 - 1){
			cout << "строка 1 записана в файл" << endl;
			fout1 << "Работа с файлами в С++" << endl; // запись строки в файл
		}
		if (ans2 != kol2 - 1){
			cout << "строка 2 записана в файл" << endl;
			fout1 << "Это вторая строка" << endl;
		}
		if (ans2 != kol3 - 1){
			cout << "строка 3 записана в файл" << endl;
			fout1 << "Немного текста здесь" << endl;
		}
		if (ans2 != kol4 - 1){
			cout << "строка 4 записана в файл" << endl;
			fout1 << "Скопировать из файла 1 в файл 2 все строки, кроме той строки, в которой больше всего гласных букв" << endl;
		}
		if (ans2 != kol5 - 1){
			cout << "строка 5 записана в файл" << endl;
			fout1 << "Напечатать номер этой строки" << endl;
		}
		if (ans2 != kol6 - 1){
			cout << "строка 6 записана в файл" << endl;
			fout1 << "произвольный текст" << endl;
		}
		if (ans2 != kol7 - 1){
			cout << "строка 7 записана в файл" << endl;

		}


		fout1.close(); //закрывает файл
		
	
	system("pause");
	return 0;
}
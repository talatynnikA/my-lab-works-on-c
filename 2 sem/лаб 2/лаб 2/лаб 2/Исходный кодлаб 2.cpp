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
	fout << "������ � ������� � �++" << endl; // ������ ������ � ����
	fout << "��� ������ ������" << endl;
	fout << "������� ������ �����" << endl;
	fout << "����������� �� ����� 1 � ���� 2 ��� ������, ����� ��� ������, � ������� ������ ����� ������� ����" << endl;
	fout << "���������� ����� ���� ������" << endl;
	fout << "������������ �����" << endl;
	fout.close(); // ��������� ����
	cout << "������ �������� � FILE1.txt" << endl;
	string str;
	ifstream fin("File1.txt");    // �������� ������� fin ������ ifstream ��� ������  
	if (!fin.is_open())
		cout << "���� �� ����� ���� ������!\n";
	else
	{
		fin.getline(buff1, 50); // ���������� ������ �� �����
		cout << buff1 << endl;   // ������ ������
		fin.getline(buff2, 100); // ���������� ������ �� �����
		cout << buff2 << endl;   // ������ ������
		fin.getline(buff3, 150); // ���������� ������ �� �����
		cout << buff3 << endl;   // ������ ������
		fin.getline(buff4, 200); // ���������� ������ �� �����
		cout << buff4 << endl;   // ������ ������
		fin.getline(buff5, 250); // ���������� ������ �� �����
		cout << buff5 << endl;   // ������ ������
		fin.getline(buff6, 300); // ���������� ������ �� �����
		cout << buff6 << endl;   // ������ ������
		fin.getline(buff7, 350); // ���������� ������ �� �����
		cout << buff7 << endl;   // ������ ������
	}
	int length, i, j, kol6 = 0, kol1 = 0, kol2 = 0, kol3 = 0, kol4 = 0, kol5 = 0, kol7 = 0;
	char vowel[] = "���������";
	puts(buff1); //��������� buff1
	length = strlen(buff1);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff1[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol1 = kol1 + 1;
	}
	cout << kol1 - 1 << endl;
	kol2 = 0;
	puts(buff2); //��������� buff2
	length = strlen(buff2);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff2[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol2 = kol2 + 1;
	}
	cout << kol2 - 1 << endl;
	kol3 = 0;
	puts(buff3); //��������� buff
	length = strlen(buff3);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff3[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol3 = kol3 + 1;
	}
	cout << kol3 - 1 << endl;
	kol4 = 0;
	puts(buff4); //��������� buff
	length = strlen(buff4);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff4[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol4 = kol4 + 1;
	}
	cout << kol4 - 1 << endl;
	kol5 = 0;
	puts(buff5); //��������� buff
	length = strlen(buff5);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff5[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol5 = kol5 + 1;
	}
	cout << kol5 - 1 << endl;
	kol6 = 0;
	puts(buff6); //��������� buff
	length = strlen(buff6);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff6[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
			kol6 = kol6 + 1;
	}
	cout << kol6 - 1 << endl;
	kol7 = 0;
	puts(buff6); //��������� buff
	length = strlen(buff6);
	for (j = 0; j <= 10; j++){
		for (i = 0; i <= length; i++)
		if (buff6[i] == vowel[j])//���������� �������� �������� � ��������� ���������� ������
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
	cout << ans2 << "������� �����������" << endl;
	fin.close(); //��������� ����
	char buff[100];
	ofstream fout1("File2.txt");    // �������� ������� fin ������ ifstream ��� ������  
	
		if (ans2 != kol1 - 1){
			cout << "������ 1 �������� � ����" << endl;
			fout1 << "������ � ������� � �++" << endl; // ������ ������ � ����
		}
		if (ans2 != kol2 - 1){
			cout << "������ 2 �������� � ����" << endl;
			fout1 << "��� ������ ������" << endl;
		}
		if (ans2 != kol3 - 1){
			cout << "������ 3 �������� � ����" << endl;
			fout1 << "������� ������ �����" << endl;
		}
		if (ans2 != kol4 - 1){
			cout << "������ 4 �������� � ����" << endl;
			fout1 << "����������� �� ����� 1 � ���� 2 ��� ������, ����� ��� ������, � ������� ������ ����� ������� ����" << endl;
		}
		if (ans2 != kol5 - 1){
			cout << "������ 5 �������� � ����" << endl;
			fout1 << "���������� ����� ���� ������" << endl;
		}
		if (ans2 != kol6 - 1){
			cout << "������ 6 �������� � ����" << endl;
			fout1 << "������������ �����" << endl;
		}
		if (ans2 != kol7 - 1){
			cout << "������ 7 �������� � ����" << endl;

		}


		fout1.close(); //��������� ����
		
	
	system("pause");
	return 0;
}
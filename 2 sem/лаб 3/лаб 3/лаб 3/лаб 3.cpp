
//#include <stdafx.h>
#include <iostream>                    
# define str_len 30                               
# define size 30  
using namespace std;
void enter_new();
void del();
void change();
void out();
struct Student
{
	char name[str_len];
	int year_of_birth;
	char department[5];
};
struct Student list_of_student[size];
struct Student bad;
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� �������� ������" << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ��������� ������" << endl;
	cout << "4-��� ������ ������(��)" << endl;
	cout << "5-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "���� ����������" << endl;
	if (current_size < size)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << "������� " << endl;
		cin >> list_of_student[current_size].name;
		cout << "��� �������� " << endl;
		cin >> list_of_student[current_size].year_of_birth;
		cout << "��������� " << endl;
		cin >> list_of_student[current_size].department;
		current_size++;
	}
	else
		cout << "������� ������������ ���-�� �����";
	cout << "��� ������?" << endl;
	cin >> choice;
}
void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
	for (int i = 0; i < size; i++)
		list_of_student[i] = bad;
	cout << "��� ������?" << endl;
	cin >> choice;
}
void change()
{
	int n, per;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������: " << endl;
		cout << "1-��� ��������� �������" << endl;
		cout << "2-��� ��������� ���� ��������" << endl;
		cout << "3-��� ��������� ����������" << endl;
		cout << "4-�����\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "����� �������";
			cin >> list_of_student[n - 1].name;   break;
		case 2: cout << "����� ��� ��������";
			cin >> list_of_student[n - 1].year_of_birth; break;
		case 3: cout << "����� ��������� ";
			cin >> list_of_student[n - 1].department; break;
		}
	} while (per != 4);
	cout << "��� ������?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-����� 1 ������" << endl;
	cout << "2-����� ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
		cout << "������� ";
		cout << list_of_student[n - 1].name << endl;
		cout << "��� �������� ";
		cout << list_of_student[n - 1].year_of_birth << endl;
		cout << "��������� ";
		cout << list_of_student[n - 1].department << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "������� ";
			cout << list_of_student[i].name << endl;
			cout << "��� �������� ";
			cout << list_of_student[i].year_of_birth << endl;
			cout << "��������� ";
			cout << list_of_student[i].department << endl;
		}
	}
	cout << "��� ������?" << endl;
	cin >> choice;
}

#include "stdafx.h"
#include <iostream>
#include "myStack.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack *myStk = new Stack, *stackNew; //��������� ������ ��� �����
	myStk->head = NULL;       //������������� ������� ��������	
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ����� �����" << endl;
		cout << "4 - �����" << endl;
		cout << "5 - ������� �����" << endl;
		cout << "6 - ������ ����� � ����" << endl;
		cout << "7 - ������ ����� �� �����" << endl;
		cout << "8 - ������������ ������ �� ����� ������ 50 � ������ 50" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "����������� �������: " << choice << endl;
			break;
		case 3: cout << "���� ����: " << endl;
			show(myStk);
			break;
		case 4: return 0;
			break;
		case 5: clear(myStk);
			cout << "���� ������" << endl;
			break;
		case 6: toFile(myStk);
			break;
		case 7: fromFile(myStk);
			break;
		case 8: stackNew = newStackless(myStk);
			cout << "���� ���������� �� ��������� ������� ������ ���� ����� 50:\n";
			show(stackNew);
			stackNew = newStackMore(myStk);
			cout << "���� ���������� �� ��������� ������� >50:\n";
			show(stackNew);
			break;
		default:
			cout << "�������� ����. ������� ������ �����:\n";
		}
	}
	return 0;
}

// ProectQueue.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//#include "stdafx.h"
#include<iostream>
#include "myQueue.h"
using namespace std;


int main()
{
	Number* begin = NULL;
	setlocale(LC_ALL, "Rus");
	int choice;
	for (;;)
	{
		cout << "O===================================================O" << endl;
		cout << " | 1 | ������� ������� ������� � ���� ������ " << endl;
		cout << " | 2 | ����� ������� " << endl;
		cout << " | 3 | ������� ������� " << endl;
		cout << " | 4 | ����� ������� ������������ �������� " << endl;
		cout << " | 5 | ����������� ������� ������� " << endl;
		cout << " | 6 | ����� " << endl;
		cout << "O===================================================O" << endl;
		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: 

			cout << "O===================================================O" << endl;
			/*void qwert();*/
			
			{
				Number  *end, *t;
				t = new Number;
				int p, size;
				cout << "O===================================================O" << endl;
				cout << "\nEnter size queue=";  cin >> size;
				cout << "Enter number= ";       cin >> p;
				t->info = p;        //������ �������
				t->next = NULL;
				begin = end = t;
				for (int i = 1; i < size; i++) //�������� �������
				{
					cout << "Enter number= ";    cin >> p;
					create(&begin, &end, p);
				}
			}
			break;
		case 2:
			view(begin);
			//void view(Number* begin);
			break;
		case 3:
			//queueclear(&begin, &t);
			void queueclear(Number** begin, Number** p);
			break;
		case 4:
			//RemoveFirstNegative(begin);
			void RemoveFirstNegative(Number*& begin);
			break;
		case 5:
			viewSize(begin);
			//void viewSize(Number* begin);
			 //����� ��������� ������� 
			//{
			//	int i = 0;
			//	Number* t = begin;
			//	if (t == NULL)
			//	{
			//		cout << "Number is empty\n";
			//		
			//	}
			//	else {

			//		while (t != NULL)
			//		{
			//			//cout << t->info << endl;
			//			t = t->next;
			//			i++;
			//			cout << i << endl;
			//		}
			//	}
			//	cout << "size of this queue is: " << i << endl;
			//}
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "�������� ����. ������� ������ �����:\n";
		}
	}
	return 0;
}


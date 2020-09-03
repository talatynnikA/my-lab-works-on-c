// ProectQueue.cpp: определяет точку входа для консольного приложения.
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
		cout << " | 1 | задание размера очереди и Ввод данных " << endl;
		cout << " | 2 | Вывод очереди " << endl;
		cout << " | 3 | Удалние очереди " << endl;
		cout << " | 4 | Поиск первого минимального элемента " << endl;
		cout << " | 5 | Определение размера очереди " << endl;
		cout << " | 6 | Выход " << endl;
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
				t->info = p;        //первый элемент
				t->next = NULL;
				begin = end = t;
				for (int i = 1; i < size; i++) //создание очереди
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
			 //Вывод элементов очереди 
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
			cout << "неверный ввод. введите другое число:\n";
		}
	}
	return 0;
}


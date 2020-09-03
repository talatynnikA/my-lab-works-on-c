//#include "stdafx.h"
#include<iostream> 
#include "myQueue.h"

using namespace std;

void qwert()
{
	Number* begin = NULL, *end, *t;
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
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
	Number* t = new Number;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}
void view(Number* begin) //Вывод элементов очереди 
{
	Number* t = begin;
	if (t == NULL)
	{
		cout << "Number is empty\n";
		return;
	}
	else
	while (t != NULL)
	{
		cout << t->info << endl;
		t = t->next;
	}
}
Number* minElem(Number* begin) //Опрделение минимального элемента
{
	Number* t = begin, *mn;
	int min;
	mn = NULL;
	if (t == NULL)
	{
		cout << "Number is empty\n"; return 0;
	}
	else
	{
		min = t->info;
		while (t != NULL)
		{
			if (t->info <= min)
			{
				min = t->info;
				mn = t;
			}
			t = t->next;
		}
	}
	return mn;
}
void DeltoMin(Number** begin, Number** p) //Удаление до минимального элемента 
{
	Number* t;
	t = new Number;
	while (*begin != *p)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}
void queueclear(Number** begin, Number** p)
{
	Number* t;
	t = new Number;
	while (*begin != NULL)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}
void viewSize(Number* begin) //Вывод элементов очереди 
{
	int i = 0;
	Number* t = begin;
	if (t == NULL)
	{
		cout << "Number is empty\n";
		return;
	}
	else {

		while (t != NULL)
		{
			//cout << t->info << endl;
			t = t->next;
			i++;
			//cout << i << endl;
		}
	}
	cout << "size of this queue is: " << i << endl;
}

void RemoveNode(Number* t)
{
	Number* to_del = t->next;
	if (!to_del) return; // Если следующего элемента нет, то уходим
	t->next = to_del->next; // вынимаем из списка
	delete to_del; // чистим память
}
void RemoveFirstNegative(Number*& begin)
{
	if (!begin) return;
	Number* t = begin;
	//  t = new Number;
	// Удаление головы
	if (begin->info < 0)
	{
		begin = begin->next;
		delete t;
		return;
	}
	// Итерируем по списку
	while (t->next != NULL)
	{

		// если нашли отрицательный элемент
		if (t->next->info < 0)
		{
			RemoveNode(t);
			return;
		}
		t = t->next;
	}
}
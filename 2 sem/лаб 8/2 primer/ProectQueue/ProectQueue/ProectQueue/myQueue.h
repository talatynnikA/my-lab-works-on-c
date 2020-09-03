//#include "stdafx.h"
#include<iostream> 

using namespace std;

struct Number
{
	int info;
	Number* next;
};
//прототип
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
Number* minElem(Number* begin); //функция определения минимального элемента 
void DeltoMin(Number** begin, Number** p); //функция удаления до минимального элемента 
void queueclear(Number** begin, Number** p);//Очистка(рабочая!!)
void viewSize(Number* begin); //для того чтобы узнать длину очереди
void RemoveFirstNegative(Number*& begin);
void qwert();


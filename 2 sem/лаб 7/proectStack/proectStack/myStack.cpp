//4. Создать проект, демонстрирующий работу со стеком, организованным на основе списка, в соответствии со своим вариантом для данных из таблицы ниже.Все операции со ст
//еком реализовать через функции.Дополнить проект функциями очистки стека clear(), сохранения в файл и считывания из файла.
//Проект должен содержать три части : главная функция, файл с функциями работы со стеком и заголовочный файл.Создать интерфейс в виде меню.(для доп добав.Еще 1 ф - ю)

//Разработать функцию, которая по одному стеку строит два новых : Stack1 из элементов, значение которых превы - шает число 50, и Stack2  из остальных элементов.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;
void push(int x, Stack *myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack *myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack *e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack *myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void clear(Stack *myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		//return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		while( myStk->head != NULL)
		{
		Stack *e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		//return a;                        //возврат значения удаляемого элемента
		}
	}
}
//void toFile(Stack  *myStk)
//{
//	FILE *f;
//	Stack *temp = myStk;
//	Stack buf;
//	if (!fopen_s(&f, "base.bin", "ab"))
//	{
//		while (myStk)
//		{
//			fwrite((char*)myStk, sizeof *myStk, 1, f);
//			myStk = myStk->next;
//		}
//	}
//	else {
//		cout << "Ошибка открытия файла";
//
//	}
//}
void toFile(Stack  *myStk)
{
	//Stack* e = myStk->head;
	Stack *temp = myStk->head;
	Stack buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char *)&buf.data, sizeof(Stack));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(Stack  *myStk)          //Считывание из файла
{
	Stack buf, *first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char *)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, myStk);
		cout << "-->" << buf.data;
		frm.read((char *)&buf, sizeof(Stack));
	}
	cout << "-->NULL" << endl;
	frm.close();
	myStk = first;
	cout << "\nСписок считан из файла mList.dat\n";
}


Stack *newStackless(Stack * myStk)
{


	Stack buf, *first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char *)&buf, sizeof(Stack));
	cout << "\nСписок из чисел <=50" << endl;
	while (!frm.eof())
	{
		if (buf.data <= 50){
			push(buf.data, myStk);

			cout << "-->" << buf.data;
		}
			frm.read((char *)&buf, sizeof(Stack));
		
	}
	cout << "-->NULL" << endl;
	frm.close();
	myStk = first;

}

Stack *newStackMore(Stack *myStk)
{

	Stack buf, *first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char *)&buf, sizeof(Stack));
	cout << "\nСписок из чисел >50"<<endl;
	while (!frm.eof())
	{
		if (buf.data > 50){
			push(buf.data, myStk);

			cout << "-->" << buf.data;
		}
		frm.read((char *)&buf, sizeof(Stack));

	}
	cout << "-->NULL" << endl;
	frm.close();
	myStk = first;

}
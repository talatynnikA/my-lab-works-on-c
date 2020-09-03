#include "stdafx.h"
#include <iostream>
#include "myStack.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack *myStk = new Stack, *stackNew; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Выход" << endl;
		cout << "5 - Очистка стека" << endl;
		cout << "6 - Запись стека в файл" << endl;
		cout << "7 - Чтение стека из файла" << endl;
		cout << "8 - Формирование стеков из чисел больше 50 и меньше 50" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: return 0;
			break;
		case 5: clear(myStk);
			cout << "стек очищен" << endl;
			break;
		case 6: toFile(myStk);
			break;
		case 7: fromFile(myStk);
			break;
		case 8: stackNew = newStackless(myStk);
			cout << "Стек полученный из элементов которые меньше либо равны 50:\n";
			show(stackNew);
			stackNew = newStackMore(myStk);
			cout << "Стек полученный из элементов которые >50:\n";
			show(stackNew);
			break;
		default:
			cout << "неверный ввод. введите другое число:\n";
		}
	}
	return 0;
}

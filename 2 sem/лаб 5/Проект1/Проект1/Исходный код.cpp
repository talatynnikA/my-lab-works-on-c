//4.  В соответствии со своим вариантом разработать программу с использованием односвязного списка по данным, представ - ленным в таблице ниже.
//Программа должна содержать меню с пунктами : добавление элемента, удаление элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла.
//8.Создать список, содержащий элементы целого типа.Найти сумму отрицательных элементов, кратных 2, или выдать со - общение, что таких элементов нет.
#include <fstream>
#include <iostream>
using namespace std;
struct list
{
	int number;
	list *next;
};
void toFile(list *&p);//функция записи списка в файл
void fromFile(list *&p);//функция считывания списка из файла

void insert(list *&, int); //функция добавления элемента, передается адрес спис-ка и символ, который добавляется 
int del(list *&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list *);         //функция, которая проверяет, пуст ли список
void printList(list *);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum7(list *);  //функция подсчета суммы чисел, больших 7  
int main()
{
	setlocale(LC_CTYPE, "Russian");
	list *first = NULL;
	int choice;
	int value;
	menu();    // вывести меню 
	cout << " ? ";
	cin >> choice;
	while (choice != 4)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите число "; // добавить число в список
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:   if (!IsEmpty(first)) // удалить число из списка
		{
					  cout << "Введите удаляемое число ";
					  cin >> value;
					  if (del(first, value))
					  {
						  cout << "Удалено число " << value << endl;
						  printList(first);
					  }
					  else
						  cout << "Число не найдено" << endl;
		}
				  else
					  cout << "Список пуст" << endl;
			break;
		case 3:   sum7(first);	// вычисление суммы	
			break;
		case 5:    toFile(first);
			break;
		case 6:    fromFile(first);
			break;

		default:  cout << "Неправильный выбор" << endl;
			menu();
			break;
		}
		cout << "?  ";
		cin >> choice;
	}
	cout << "Конец" << endl;
	return 0;
}

void menu(void)  //Вывод меню 
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вычисление суммы отрицательных элементов, кратных 2" << endl;
	cout << " 4 - Выход" << endl;
	cout << " 5 - Запись списка в файл" << endl;
	cout << " 6 - Чтение списка из файла" << endl;

}

void insert(list *&p, int value) //Добавление числа value в список 
{

	list *newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->number = value;
		newP->next = p;
		p = newP;


	}
	else
		cout << "Операция добавления не выполнена" << endl;

}
int del(list *&p, int value)  // Удаление числа 
{
	list *previous, *current, *temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			return value;
		}
	}
	return 0;
}

int IsEmpty(list *p) //Список  пустой? (1-да, 0-нет) 
{
	return p == NULL;
}


void printList(list *p)  //Вывод списка 
{
	ifstream fin("t.txt");
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void sum7(list *p)  // Подсчет суммы  отрицательных элементов, кратных 2
{
	int sm = 0;
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		while (p != NULL)
		{
			if (p->number < 0 && p->number % 2 == 0)
				sm = sm + (p->number);
			p = p->next;
		}
		if (sm == 0)
			cout << "отрицательных элементов, кратных 2 нет" << endl;
		else {
			cout << "Сумма = " << sm << endl;
		}
	}
}
void toFile(list *&p)
{
	list *temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char *)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "Список записан в файл mList.dat\n";
}

void fromFile(list *&p)          //Считывание из файла
{
	list buf, *first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char *)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char *)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\nСписок считан из файла mList.dat\n";
}


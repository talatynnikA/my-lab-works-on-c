// Таблица увеличивается втрое при достижении 70% заполнения
#include <iostream>
#include <fstream>
#include <ctime>
#include "Hash.h"

#define DEFAULT_SIZE 10

using namespace std;

struct AAA
{
	int key;
	char *mas;
	AAA(int k, char *z)
	{
		key = k;
		mas = z;
	}
	AAA() {}
};

inline int key(void *d)
{
	return ((AAA *)d)->key;
}

inline char *info(void *d)
{
	return ((AAA *)d)->mas;
}

inline void AAA_print(void *d)
{
	cout << info(d) << " [" << key(d) << "]\n";
}

inline void printAddit(void *d)
{
	cout << key(d) << " [" << info(d) << "]\n";
}

inline void pause()
{
	cout << "Введите <enter> чтобы продолжить.\n";
	cin.ignore(256, '\n');
}

void toFile(Object &f)
{
	ofstream fout("hash.txt");
	fout << f.hash << endl;
	for (size_t i = 0; i < f.size; i++)
	{
		if (f.data[i])
			fout << key(f.data[i]) << " " << ((AAA *)f.data[i])->mas << endl;
	}
	fout.close();
}

bool fromFile(Object &f)
{
	ifstream fin("hash.txt");
	if (fin.fail())
		return false;
	int num;
	fin >> num;
	if (fin.eof())
		return false;
	f = create(DEFAULT_SIZE, key, info, (Hashing)num);
	AAA *a;
	char *ch;
	while (!fin.eof())
	{
		fin >> num;
		if (fin.eof())
			break;
		ch = new char[20];
		fin >> ch;
		a = new AAA;
		a->key = num;
		a->mas = ch;
		f.insert(a);
		if (f.N >= (int)(f.size * 0.7))
			f = f.chSize(f.size * 3);
	}
	fin.close();
	return true;
}

int main()
{
	Hashing hash;
	HashKey key1;
	int siz = DEFAULT_SIZE, choice, k;
	AAA *elem;
	char *str;
	bool fl;
	clock_t clk1, clk2;
	Object H = create(siz, key, info, DEF);
	for (;;)
	{
		system("clear");
		cout << "Текущий метод хеширования - ";
		switch (H.hash)
		{
		case DEF:
			cout << "стандартный.\n";
			break;
		case UNIV:
			cout << "универсальный.\n";
			break;
		case MOD:
			cout << "модульный.\n";
			break;
		case ADDIT:
			cout << "адитивный.\n";
			break;
		}
		cout << "Введите число:\n";
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "5 - чтение из файла\n";
		cout << "6 - запись в файл\n";
		cout << "7 - смена метода хеширования\n";
		cout << "8 - сравнить время поиска информации при универсальном и модульном хешировании\n";
		cout << "0 - выход" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;
		cin.ignore(256, '\n');
		switch (choice)
		{
		case 0:
			cout << "До свидания.\n";
			return 0;
		case 1:
			if (H.hash == ADDIT)
				H.scan(printAddit);
			else
				H.scan(AAA_print);
			pause();
			break;
		case 2:
			elem = new AAA;
			str = new char[20];
			cout << "Введите число: ";
			cin >> k;
			elem->key = k;
			cout << "Введите строку: ";
			cin >> str;
			cin.ignore(256, '\n');
			elem->mas = str;
			H.insert(elem);
			if (H.N >= (int)((float)H.size * 0.7))
				H = H.chSize(H.size * 3);
			pause();
			break;
		case 3:
			cout << "Введите ключ для удаления: ";
			if (H.hash == ADDIT)
			{
				str = new char[20];
				cin >> str;
				key1.str = str;
			}
			else
			{
				cin >> k;
				key1.num = k;
			}
			cin.ignore(256, '\n');
			elem = (AAA *)H.deleteByKey(key1);
			if (elem)
				cout << "Элемент удален.\n";
			else
				cout << "Элемент не найден.\n";
			pause();
			break;
		case 4:
			cout << "Введите ключ для поиска: ";
			if (H.hash == ADDIT)
			{
				str = new char[20];
				cin >> str;
				key1.str = str;
			}
			else
			{
				cin >> k;
				key1.num = k;
			}
			cin.ignore(256, '\n');
			elem = (AAA *)H.search(key1);
			if (!elem)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Найден элемент ";
				AAA_print(elem);
			}
			pause();
			break;
		case 6:
			toFile(H);
			cout << "Таблица записана в файл.\n";
			pause();
			break;
		case 5:
			fl = fromFile(H);
			if (fl)
			{
				cout << "Таблица считана из файла. ";
				if (H.hash == ADDIT)
					H.scan(printAddit);
				else
					H.scan(AAA_print);
			}
			else
				cout << "Ошибка открытия файла или файл пуст.\n";
			pause();
			break;
		case 7:
			cout << "Введите, на какой метод хотите поменять:\n";
			cout << "1 - стандартный\n";
			cout << "2 - универсальный\n";
			cout << "3 - модульный\n";
			cout << "4 - аддитивный\n";
			cout << "0 - выход в главное меню\n";
			cout << "Ваш выбор: ";
			cin >> k;
			cin.ignore(256, '\n');
			if (!k)
				break;
			if (H.hash == (Hashing)k)
				cout << "Данный метод уже установлен.\n";
			else
			{
				H = H.chMethod((Hashing)k);
				cout << "Метод изменен.\n";
			}
			pause();
			break;
		case 8:
			hash = H.hash;
			if (H.hash != UNIV)
				H = H.chMethod(UNIV);
			cout << "Введите ключ-число для поиска: ";
			cin >> k;
			key1.num = k;
			cin.ignore(256, '\n');
			clk1 = clock();
			elem = (AAA *)H.search(key1);
			clk1 = clock() - clk1;
			if (!elem)
			{
				cout << "Такого элемента нет.\n";
				if (hash != UNIV)
					H = H.chMethod(hash);
			}
			else
			{
				H = H.chMethod(MOD);
				clk2 = clock();
				elem = (AAA *)H.search(key1);
				clk2 = clock() - clk2;
				cout << "Время поиска при универсальном хешировании - " << (float)clk1 / CLOCKS_PER_SEC;
				cout << "\nВремя поиска при модульном хешировании - " << (float)clk2 / CLOCKS_PER_SEC;
				cout << "\nСледовательно, " << (clk1 > clk2 ? "модульное" : "универсальное") << " быстрее.\n";
				if (hash != MOD)
					H = H.chMethod(hash);
			}
			pause();
			break;
		default:
			cout << "Неверный ввод. Введите число согласно расшифровке выше.\n";
			pause();
			break;
		}
	}
}

#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address *next;
	Address *prev;
};
struct Address2
{
	char name2[NAME_SIZE];
	char city2[CITY_SIZE];
	Address2 *next2;
	Address2 *prev2;
};
struct Address3
{
	char name3[NAME_SIZE];
	char city3[CITY_SIZE];
	Address2 *next3;
	Address2 *prev3;
};

//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Выход" << endl;
	cout << "6. Запись в файл" << endl;
	cout << "7. Считывание из файла" << endl;
	cout << "8. ввод имени в другой список" << endl;
	cout << "9. вывод другого списка на экран" << endl;
	cout << "10. Запись в файл другого списка" << endl;
	cout << "11. Считывание из файла другого списка" << endl;
	cout << "12. формирование списка To, включив в него поочередно элементы из списков from1 и from2.  " << endl;
	cout << "13. вывод 3-го списка" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 12);
	return c;
}
//-----------------------------------------------------------
void insert(Address *e, Address **phead, Address **plast) //Добавление в конец списка
{
	Address *p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address **phead, Address **plast)      //Вывод списка на экран
{
	Address *t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address **phead)    // Поиск имени в списке
{
	Address *t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address **phead, Address **plast)  // Удаление имени {	struct Address *t = *phead;	
{
	Address *t = *phead;
	while (t)
{
	if (!strcmp(name, t->name))  break;
	t = t->next;
}
if (!t)
cerr << "Имя не найдено" << endl;
else
{
	if (*phead == t)
	{
		*phead = t->next;
		if (*phead)
			(*phead)->prev = NULL;
		else
			*plast = NULL;
	}
	else
	{
		t->prev->next = t->next;
		if (t != *plast)
			t->next->prev = t->prev;
		else
			*plast = t->prev;
	}
	delete t;
	cout << "Элемент удален" << endl;
}
}
//-----------------------------------------------------------

void writeToFile(Address **phead)       //Запись в файл
{
	struct Address *t = *phead;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address **phead, Address **plast)          //Считывание из файла
{
	struct Address *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete *phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


//-----------------------------------------------------------
//                 ВТОРОЙ СПИСОК
//-----------------------------------------------------------
void insert2(Address2 *e2, Address2 **phead2, Address2 **plast2) //Добавление в конец списка другого списка
{
	Address2 *p = *plast2;
	if (*plast2 == NULL)
	{
		e2->next2 = NULL;
		e2->prev2 = NULL;
		*plast2 = e2;
		*phead2 = e2;
		return;
	}
	else
	{
		p->next2 = e2;
		e2->next2 = NULL;
		e2->prev2 = p;
		*plast2 = e2;
	}
}
//-----------------------------------------------------------
Address2* setElement2()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address2* temp = new  Address2();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name2, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city2, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next2 = NULL;
	temp->prev2 = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList2(Address2 **phead2, Address2 **plast2)      //Вывод списка на экран
{
	Address2 *two = *phead2;
	while (two)
	{
		cout << two->name2 << ' ' << two->city2 << endl;
		two = two->next2;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void writeToFile2(Address2 **phead2)       //Запись в файл
{
	struct Address2 *t2 = *phead2;
	FILE *fp2;
	errno_t err = fopen_s(&fp2, "mlist2", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t2)
	{
		fwrite(t2, sizeof(struct Address2), 1, fp2);
		t2 = t2->next2;
	}
	fclose(fp2);
}
//-----------------------------------------------------------
void readFromFile2(Address2 **phead2, Address2 **plast2)          //Считывание из файла
{
	struct Address2 *t2;
	FILE *fp2;
	errno_t err = fopen_s(&fp2, "mlist2", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead2)
	{
		*plast2 = (*phead2)->next2;
		delete *phead2;
		*phead2 = *plast2;
	}
	*phead2 = *plast2 = NULL;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp2))
	{
		t2 = new Address2();
		if (!t2)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t2, sizeof(struct Address2), 1, fp2)) break;
		insert2(t2, phead2, plast2);
	}
	fclose(fp2);
}
//-----------------------------------------------------------
//                 ТРЕТИЙ СПИСОК
//-----------------------------------------------------------
void insert3(Address2 **phead2, Address2 **plast2, Address3 *e3, Address3 **phead3, Address3 **plast3, Address **phead, Address **plast, Address *e) //Добавление в конец списка другого списка
{
	Address *p = *plast;
	Address2 *p2 = *plast2;
	Address3 *p3 = *plast3;
	if (*plast3 == NULL)
	{
		e3->next3 = NULL;
		e3->prev3 = NULL;
		*plast3 = e3;
		*phead3 = *plast2;
		return;
	}
	else
	{
		p3->next3 = e3;
		e3->next3 = NULL;
		e3->prev3 = p3;
		*plast3 = e3;
	}
}
//-----------------------------------------------------------

//void CopyAddress123(Address3* To, Address *From, Address2 *From2)
//{
//
//	//char * temp2228 = To->name3;
//	//char * temp2229 = To->city3;
//	//temp2228 = new char[NAME_SIZE];
//	//strcpy_s(To->name3, From->name);
//	//temp2229 = new char[CITY_SIZE];
//	//strcpy_s(To->city3, From->city);
//
//	//temp2228 = new char[NAME_SIZE];
//	//strcpy_s(To->name3, From2->name2);
//	//temp2229 = new char[CITY_SIZE];
//	//strcpy_s(To->city3, From2->city2);
//	//cout << "чето прошло" << endl;
//
//	Address3 *p1 = new Address3;
//	Address3 *p2 = new Address3;
//
//
//	strcpy_s(p1->name3, From->name);
//	strcpy_s(p1->city3, From->city);
//	strcpy_s(p2->name3, From2->name2);
//	strcpy_s(p2->city3, From2->city2);
//
//	cout << "чето прошло2" << endl;
//}
//-----------------------------------------------------------
//void outputList3(Address3 **phead3, Address3 **plast3)      //Вывод списка на экран
//{
//	Address3 *t = *phead3;
//	while (t)
//	{
//		cout << t->name3 << ' ' << t->city3 << endl;
//		t = t->next3;
//	}
//	cout << "" << endl;
//}
//-----------------------------------------------------------
int main(void)
{
	Address *head = NULL;
	Address *last = NULL;

	Address2 *head2 = NULL;
	Address2 *last2 = NULL;

	Address3 *head3 = NULL;
	Address3 *last3 = NULL;

	Address3* To = NULL;
	Address *From = NULL;
	Address2 *From2 = NULL;

	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2:  {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			break;
		case 3:  outputList(&head, &last);
			break;
		case 4:  {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			break;
		case 5:  exit(0);
		case 6: writeToFile(&head);
			break;
		case 7: readFromFile(&head, &last);
			break;
		case 8: insert2(setElement2(), &head2, &last2);
			break;
		case 9: outputList2(&head2, &last2);
			break;
		case 10: writeToFile2(&head2);
			break;
		case 11: readFromFile2(&head2, &last2);
			break;
		case 12: //CopyAddress123( To, From,  From2);
			//insert3(setElement3(), &head3, &last3);
			break;
		case 13:  /*outputList3(&head, &last);*/
			break;
		default: exit(1);
		}
	}
	return 0;
}

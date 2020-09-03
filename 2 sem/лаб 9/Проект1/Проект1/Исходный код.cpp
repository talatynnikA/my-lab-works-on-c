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
	cout << "1. ���� �����" << endl;
	cout << "2. �������� �����" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. �����" << endl;
	cout << "6. ������ � ����" << endl;
	cout << "7. ���������� �� �����" << endl;
	cout << "8. ���� ����� � ������ ������" << endl;
	cout << "9. ����� ������� ������ �� �����" << endl;
	cout << "10. ������ � ���� ������� ������" << endl;
	cout << "11. ���������� �� ����� ������� ������" << endl;
	cout << "12. ������������ ������ To, ������� � ���� ���������� �������� �� ������� from1 � from2.  " << endl;
	cout << "13. ����� 3-�� ������" << endl;
	cout << endl;
	do
	{
		cout << "��� �����: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 12);
	return c;
}
//-----------------------------------------------------------
void insert(Address *e, Address **phead, Address **plast) //���������� � ����� ������
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
Address* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address **phead, Address **plast)      //����� ������ �� �����
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
void find(char name[NAME_SIZE], Address **phead)    // ����� ����� � ������
{
	Address *t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address **phead, Address **plast)  // �������� ����� {	struct Address *t = *phead;	
{
	Address *t = *phead;
	while (t)
{
	if (!strcmp(name, t->name))  break;
	t = t->next;
}
if (!t)
cerr << "��� �� �������" << endl;
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
	cout << "������� ������" << endl;
}
}
//-----------------------------------------------------------

void writeToFile(Address **phead)       //������ � ����
{
	struct Address *t = *phead;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address **phead, Address **plast)          //���������� �� �����
{
	struct Address *t;
	FILE *fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete *phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "������ ��������� ������" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}


//-----------------------------------------------------------
//                 ������ ������
//-----------------------------------------------------------
void insert2(Address2 *e2, Address2 **phead2, Address2 **plast2) //���������� � ����� ������ ������� ������
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
Address2* setElement2()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Address2* temp = new  Address2();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.getline(temp->name2, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->city2, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next2 = NULL;
	temp->prev2 = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList2(Address2 **phead2, Address2 **plast2)      //����� ������ �� �����
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
void writeToFile2(Address2 **phead2)       //������ � ����
{
	struct Address2 *t2 = *phead2;
	FILE *fp2;
	errno_t err = fopen_s(&fp2, "mlist2", "wb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	cout << "���������� � ����" << endl;
	while (t2)
	{
		fwrite(t2, sizeof(struct Address2), 1, fp2);
		t2 = t2->next2;
	}
	fclose(fp2);
}
//-----------------------------------------------------------
void readFromFile2(Address2 **phead2, Address2 **plast2)          //���������� �� �����
{
	struct Address2 *t2;
	FILE *fp2;
	errno_t err = fopen_s(&fp2, "mlist2", "rb");
	if (err)
	{
		cerr << "���� �� �����������" << endl;
		exit(1);
	}
	while (*phead2)
	{
		*plast2 = (*phead2)->next2;
		delete *phead2;
		*phead2 = *plast2;
	}
	*phead2 = *plast2 = NULL;
	cout << "�������� �� �����" << endl;
	while (!feof(fp2))
	{
		t2 = new Address2();
		if (!t2)
		{
			cerr << "������ ��������� ������" << endl;
			return;
		}
		if (1 != fread(t2, sizeof(struct Address2), 1, fp2)) break;
		insert2(t2, phead2, plast2);
	}
	fclose(fp2);
}
//-----------------------------------------------------------
//                 ������ ������
//-----------------------------------------------------------
void insert3(Address2 **phead2, Address2 **plast2, Address3 *e3, Address3 **phead3, Address3 **plast3, Address **phead, Address **plast, Address *e) //���������� � ����� ������ ������� ������
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
//	//cout << "���� ������" << endl;
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
//	cout << "���� ������2" << endl;
//}
//-----------------------------------------------------------
//void outputList3(Address3 **phead3, Address3 **plast3)      //����� ������ �� �����
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
			cout << "������� ���: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			break;
		case 3:  outputList(&head, &last);
			break;
		case 4:  {	  char fname[NAME_SIZE];
			cout << "������� ���: ";
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

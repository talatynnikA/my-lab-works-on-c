#include <iostream>
using namespace std;
struct Tree          //������
{
	int key;         //����
	int number;    //����� 
	Tree *Left, *Right;
};
Tree* makeTree(Tree *Root);       //�������� ������
Tree* list(int i, int *s);       //�������� ������ ��������
Tree* insertElem(Tree *Root, int key, int *s);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree *Root, int key); //�������� �������� �� �����
void view(Tree *t, int level);    //����� ������ 
int count(Tree *t, int letter);  //������� ���������� ����
void delAll(Tree *t);             //������� ������


int c = 0;         //���������� ����( ��� ��������)
Tree *Root = NULL; 	//��������� �����

void main()
{
	setlocale(0, "Russian");
	int key, choice, n;
	Tree *rc; int s, letter;
	for (;;)
	{
		cout << "1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	����� �� �����\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -	������� ���������� ����\n";
		cout << "7 -	������� ������\n";
		cout << "8 -	�����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			insertElem(Root, key, *s); break;
		case 3:  cout << "\n������� ����: ";  cin >> key;
			rc = search(Root, key);
			cout << "��������� �����= ";
			puts(rc->number); break;
		case 4:  cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
					 cout << "������ ��������� �� 90 ����. �����" << endl;
					 view(Root, 0);
		}
				 else cout << "������ ������\n"; break;
		case 6:  cout << "\n������� �����: "; cin >> letter;
			n = count(Root, letter);
			cout << "���������� ����, ������������ � ����� " << letter;
			cout << " ����� " << n << endl; break;
		case 7:  delAll(Root); break;
		case 8:  exit(0);
		}
	}
}


Tree* makeTree(Tree *Root)    //�������� ������
{
	int key; int s;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s);	// ��������� ��������� �� ������
	}
	while (1)                //���������� ���������
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� �����: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}


// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void*  a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x  >  A2->x)
		rc = heap::GREAT;
	else
	if (A2->x  > A1->x)
		rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, choice, key;
	heap::Heap h1 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - ����� ���� �� �����" << endl;
		cout << "2 - �������� �������" << endl;
		cout << "3 - ������� ������������ �������" << endl;
		cout << "4 - ������� ����������� �������" << endl;
		cout << "5 - ������� �������� �������" << endl;

		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2:  {	AAA *a = new AAA;
			cout << "������� ����" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			break;
		case 3:   h1.extractMax();
			break;
		case 4:   h1.scan2(0);//h1.extractMin();
			break; 
		case 5:  	cout << "������� �������: " << endl;
			cin >> key;
			h1.search(key);
			break;
		default:  cout << endl << "������� �������� �������!" << endl;
		}
	} return 0;
}

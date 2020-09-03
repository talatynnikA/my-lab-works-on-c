#include "Heap.h"
heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
int q = 0;
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	heap::Heap h3 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - ����� ������ ���� �� �����" << endl;
		cout << "2 - �������� ������� � ������ ����" << endl;
		cout << "3 - ������� ������������ ������� ������ ���� " << endl;
		cout << "4 - ������� ����������� ������� ������ ����" << endl;
		cout << "5 - �������� ������� �� ������ ����" << endl;
		cout << "6 - ����� ������ ���� �� �����" << endl;
		cout << "7 - ����� ����" << endl;
		cout << "8 - ������� i-�� ������� ������ ����" << endl;
		/////////
		/*cout << "9 - ������� �������������� ���� ���������" << endl;
		cout << "10 - ���������� ���������" << endl;
		cout << "11 - ������� ��������" << endl;*/
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "������� ����" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:  h1.scan2();
			h1.extractMin();
			break;
		case 5: {
			AAA* a = new AAA;
			cout << "������� ����" << endl; 	cin >> k;
			a->x = k;
			h2.insert(a);
		}
			  break;
		case 6:
			h2.scan(0);
			break;

		case 7: h1.scanx1();
			h2.scanx1();
			int m;
			for (int i = 0; i < 20; i++) {
				m = arr(i);
				if (m == 0)
					break;
				AAA* a = new AAA;
				a->x = m;
				h3.insert(a);
			}
			h3.scan(0);
			break;
		case 8:
			cout << "������� ����� ��������: ";
			cin >> q;
			h1.ielem(q);
			break;
		case 9:  h1.average();
			break;
		case 10:  h1.amount();
			break;
		case 11:  h1.even();
			break;
		default:  cout << endl << "������� �������� �������!" << endl;
		}

	}
	return 0;
}

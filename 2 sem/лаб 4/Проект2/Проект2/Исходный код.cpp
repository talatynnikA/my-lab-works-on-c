/*5. ����������� ��������� � �������������� ��������� � ���� �����������, 
��� ������ � ������� �� �������, ����������� ����.����������� ������� ����� � ����������, ������ �� ����� � ������.
���������.����� �����, ����� ����������, ����� ������, ���� ������, ��������� ������, ���������� ����.
����� �� ������ ����������.*/
#include <iostream>
#include <string>
#include <iomanip>
# define size 30  
using namespace std;
//void enter_new();
//int main(void);//enter_new
//void main();
//int main(void);
void input(int size1);
void main();
//void del();
void search();
void out();
union flight
{
	char number;
	char destination;
	//char departrure_time;
	char hours;
	char minutes;
	char departrure_date;
	char cost;
	char number_of_seats;
	float srb;
	int group;
	int day;
	int mon;
	int year;
	char DAY;
	char MON;
	char YEAR;

}list_of_flight[size];

union flight bad;
int current_size = 0; int choice;
//struct bites
//{
//	char DAY;
//	char MON;
//	char YEAR;
//};
//struct bites list_of_date[size];
//enum Edestination{
//	Moscow = 1,
//	Kiev,
//	Minsk,
//	NewYork,
//	Vilnus,
//	Praha,
//	Stockholm
//} destination;
int number; FILE *f; errno_t err;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "�������: " << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ������ ������" << endl;
	cout << "4-��� ������ ������(��)" << endl;
	cout << "0-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		//case 1:  del();	break;
		case 2:  {cout << "������� ���������� �������: ";
			cin >> number;
			input(number);
			if (number == 0) exit(0); break; }
		case 3:  search();  break;
		case 4:  out();
			break;


		case 0: exit(0);  break;
		}

	} while (choice != 0);

}
void input(int size1)
{
	//bites list_of_date;
	//list_of_date = {};
	flight buf;
	int m, c_dest;
	//string c_dest;
	if (!fopen_s(&f, "base.bin", "ab"))
	{
		for (int p = 0; p < size1; p++)
		{
			cout << "����� �����: "; 	cin >> buf.number;
			cout << "����� ����������(1-7):";
			cin >> buf.destination;
			
			cout << "��� ������: "; 	cin >>  buf.hours;
			cout << "������ ������: "; 	cin >>  buf.minutes;
			cout << "���� ������(1-31): "; 	/*scanf_s("%d", &m);*/
			cin >> buf.DAY;//cin >> date.DAY; 
			cout << "����� ������(1-12): "; 	/*scanf_s("%d", &m);*/
			cin >> buf.MON;//cin >> date.MON;
			cout << "��� ������(0-99): "; 	/*scanf_s("%d", &m);*/
			cin >> buf.YEAR;//cin >> date.YEAR;
			cout << "��������� ������: ";
			cin >> buf.cost;
			cout << "���������� ����: ";
			cin >> buf.number_of_seats;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
		cout << "��� ������?" << endl;
		cin >> choice;
	}
	else {
		cout << "������ �������� �����";
		return;
	}
}
void del()
{
	int d;
	flight list_of_flight[size];
	fopen_s(&f, "base.bin", "ab");
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;  cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_flight[de1] = list_of_flight[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
	for (int i = 0; i < size; i++)
		list_of_flight[i] = bad;
	fclose(f);
	cout << "��� ������?" << endl;
	cin >> choice;
}
void search()
{
	setlocale(LC_CTYPE, "Russian");
	flight buf;
	int  per;
	char n;
	if (!fopen_s(&f, "base.bin", "rb"))
	{

		cout << setw(55) << setfill('-') << '-' << endl;
		cout << setfill(' ') << endl;
		cout << setw(15) << "����� ����� ";
		cout << setw(20) << "����� ����������";
		cout << setw(20) << "����� ������  ";
		cout << setw(15) << "���� ������ ";
		cout << setw(20) << "��������� ������ ";
		cout << setw(20) << "���������� ����  " << endl;
		cout << setw(55) << setfill('-') << '-' << endl;
		cout << setfill(' ');
		fread(&buf, sizeof(buf), 1, f);
		cout << "\n������� ���� ������" << endl; 	cin >> n;

		scanf_s("%s", &n);
		if (n == buf.departrure_date)
		{
			cout << "\n";
			cout << setw(15) << left << buf.number;

			cout << setw(15) << right << buf.destination;

			cout << setw(20) << buf.hours << ":" << buf.minutes;

			cout << setw(15) << buf.DAY << "_" << buf.MON << "_" << buf.YEAR;

			cout << setw(10) << buf.cost;

			cout << setw(15) << buf.number_of_seats;
			fread(&buf, sizeof(buf), 1, f);
		}
		else cout << "�������� ��������";
		cout << endl;
		fclose(f);
		cout << "��� ������?" << endl;
		cin >> choice;
	}
	else
	{
		cout << "������ �������� �����";
		cout << "��� ������?" << endl;
		cin >> choice;
	}
}
void out()
{
	setlocale(LC_CTYPE, "Russian");
	int sw, n;
	flight buf;
	int m;
	if (!fopen_s(&f, "base.bin", "rb"))
	{

		cout << setw(55) << setfill('-') << '-' << endl;
		cout << setfill(' ') << endl;
		cout << setw(15) << "����� ����� ";
		cout << setw(20) << "����� ����������";
		cout << setw(20) << "����� ������  ";
		cout << setw(15) << "���� ������ ";
		cout << setw(20) << "��������� ������ ";
		cout << setw(20) << "���������� ����  " << endl;
		cout << setw(55) << setfill('-') << '-' << endl;
		cout << setfill(' ');
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << "\n";
			cout << setw(15) << left << buf.number;

			cout << setw(15) << right << buf.destination;

			cout << setw(20)  << buf.hours << ":" << buf.minutes;

			cout << setw(15) << buf.DAY << "_" << buf.MON << "_" << buf.YEAR;

			cout << setw(10) << buf.cost;

			cout << setw(15) << buf.number_of_seats;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
		cout << "��� ������?" << endl;
		cin >> choice;
	}
	else
	{
		cout << "������ �������� �����";
		cout << "��� ������?" << endl;
		cin >> choice;
		return;
	}
}


//#include "stdafx.h"
#include<iostream> 

using namespace std;

struct Number
{
	int info;
	Number* next;
};
//��������
void create(Number** begin, Number** end, int p); //������������ ��������� �������
void view(Number* begin); //������� ������ ��������� ������� 
Number* minElem(Number* begin); //������� ����������� ������������ �������� 
void DeltoMin(Number** begin, Number** p); //������� �������� �� ������������ �������� 
void queueclear(Number** begin, Number** p);//�������(�������!!)
void viewSize(Number* begin); //��� ���� ����� ������ ����� �������
void RemoveFirstNegative(Number*& begin);
void qwert();


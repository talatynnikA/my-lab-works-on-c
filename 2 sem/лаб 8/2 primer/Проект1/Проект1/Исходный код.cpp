//Пример.Создать очередь для целых чисел.
//Создать функции для ввода, вывода  и  удаления  элементов  очереди.
//Найти минимальный элемент в очереди и удалить все элементы до него.
#pragma once
#include<iostream> 
using namespace std;

struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //формирование элементов очереди
void view(Number* begin); //функция вывода элементов очереди 
Number* minElem(Number* begin); //функция определения минимального элемента 
void DeltoMin(Number** begin, Number** p); //функция удаления до минимального элемента 
void queueclear(Number** begin, Number** p);//Очистка(рабочая!!)
void viewSize(Number* begin); //для того чтобы узнать длину очереди
void RemoveFirstNegative(Number*& begin);
int main()
{
    Number* begin = NULL, * end, * t;
    t = new Number;
    int p, size;
    cout << "\nEnter size queue=";  cin >> size;
    cout << "Enter number= ";       cin >> p;
    t->info = p;        //первый элемент
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //создание очереди
    {
        cout << "Enter number= ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //вывод на экран
        cout << "No elements" << endl;
    else
        view(begin);
    viewSize(begin);
    RemoveFirstNegative(begin);
    cout << "RemoveFirstNegative" << endl;
    view(begin);
    cout << "noviy spisok" << endl;
    t = minElem(begin);    //определение минимального
    cout << "minimum=" << t->info << endl;
    DeltoMin(&begin, &t);   //удаление до минимального
    cout << "\nnew Queue:\n";
    view(begin);
    viewSize(begin);
    
    //return 0;
    queueclear(&begin, &t);
    cout << "\nnew Queue:\n";
    view(begin);
    system("pause");
}
void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
}
Number* minElem(Number* begin) //Опрделение минимального элемента
{
    Number* t = begin, * mn;
    int min;
    mn = NULL;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        min = t->info;
        while (t != NULL)
        {
            if (t->info <= min)
            {
                min = t->info;
                mn = t;
            }
            t = t->next;
        }
    }
    return mn;
}
void DeltoMin(Number** begin, Number** p) //Удаление до минимального элемента 
{
    Number* t;
    t = new Number;
    while (*begin != *p)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
void queueclear(Number** begin, Number** p)
{
    Number* t;
    t = new Number;
    while (*begin != NULL)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
void viewSize(Number* begin) //Вывод элементов очереди 
{
    int i = 0;
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else {
        
        while (t != NULL)
        {
            //cout << t->info << endl;
            t = t->next;
            i++;
        }
    }
    cout << "size of this queue is: " << i << endl;
}

void RemoveNode(Number* t)
{
    Number* to_del = t->next;
    if (!to_del) return; // Если следующего элемента нет, то уходим
    t->next = to_del->next; // вынимаем из списка
    delete to_del; // чистим память
}
void RemoveFirstNegative(Number*& begin)
{
    if (!begin) return;
    Number* t = begin;
  //  t = new Number;
    // Удаление головы
    if (begin->info < 0)
    {
        begin = begin->next;
        delete t;
        return;
    }
// Итерируем по списку
while (t->next!=NULL)
{
    
    // если нашли отрицательный элемент
    if (t->next->info < 0)
    {
        RemoveNode(t);
        return;
    }
    t = t->next;
}
}
//Авиарейсы.Номер рейса, пункт назначения, время вылета, дата вылета, стоимость билета, количество мест.
//Выбор по дате вылета.Дату вылета реализовать с помощью битового поля, пункт назначения  с помо - щью перечисления.
struct student
{
	string name;
	string secondname;
	string lastmane;
	string spec;
	string faculty;
	float srb;
	int group;
	int day;
	int mon;
	int year;

};
struct bites
{
	unsigned DAY : 5;
	unsigned MON : 4;
	unsigned YEAR : 7;
};
if (sw == 2)
{
	cout << setw(55) << setfill('-') << '-' << endl;
	cout << setfill(' ') << endl;
	cout << setw(15) << "Фамилия ";
	cout <<setw(20)<< "Год рождения ";
	cout << setw(20) << "Факультет  "<< endl;
	cout << setw(55) << setfill('-')<<'-'<<endl;
	cout << setfill(' ');
	for (int i = 0; i < current_size; i++)
	{
		cout << setw(15) << left << list_of_student[i].name;
		cout << setw(15) << right << list_of_student[i].year_of_birth;
		cout << setw(20) << list_of_student[i].department
	}


}
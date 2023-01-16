#include "HRManagment.h"
Employee::Employee()
{
	cout << "Вызывался конструктор Employee" << endl;
	Income = 0;
	Experience = 0;
}

void Employee::Hire()
{
	Input(&Income, " прибыль сотрудника", InputType::Number);
	float experience;
	Input(&experience, " стаж сотрудника", InputType::Number);
	Experience = (int)experience;
	StringInput(&Name, " имя сотрудника");
}

void Employee::Show(TablePrinter tp)
{
	tp << Name << Experience << Income;
}

PermanentEmployee::PermanentEmployee()
{
	cout << "Вызвался конструктор Permanent Employee" << endl;
}

TemporaryEmployee::TemporaryEmployee()
{
	cout << "Вызвался конструктор Temporary Employee" << endl;
}

Manager::Manager()
{
	cout << "Вызвался конструктор Manager" << endl;
}

PermanentManager::PermanentManager()
{
	cout << "Вызвался конструктор PermanentManager" << endl;
}

Consultant::Consultant()
{
	cout << "Вызвался конструктор Consultant" << endl;
}

ConsultantManager::ConsultantManager()
{
	cout << "Вызвался конструктор ConsultantManager" << endl;
}

Director::Director()
{
	cout << "Вызвался конструктор Director" << endl;
}

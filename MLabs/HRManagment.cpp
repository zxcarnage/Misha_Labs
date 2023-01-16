#include "HRManagment.h"
Employee::Employee()
{
	cout << "��������� ����������� Employee" << endl;
	Income = 0;
	Experience = 0;
}

void Employee::Hire()
{
	Input(&Income, " ������� ����������", InputType::Number);
	float experience;
	Input(&experience, " ���� ����������", InputType::Number);
	Experience = (int)experience;
	StringInput(&Name, " ��� ����������");
}

void Employee::Show(TablePrinter tp)
{
	tp << Name << Experience << Income;
}

PermanentEmployee::PermanentEmployee()
{
	cout << "�������� ����������� Permanent Employee" << endl;
}

TemporaryEmployee::TemporaryEmployee()
{
	cout << "�������� ����������� Temporary Employee" << endl;
}

Manager::Manager()
{
	cout << "�������� ����������� Manager" << endl;
}

PermanentManager::PermanentManager()
{
	cout << "�������� ����������� PermanentManager" << endl;
}

Consultant::Consultant()
{
	cout << "�������� ����������� Consultant" << endl;
}

ConsultantManager::ConsultantManager()
{
	cout << "�������� ����������� ConsultantManager" << endl;
}

Director::Director()
{
	cout << "�������� ����������� Director" << endl;
}

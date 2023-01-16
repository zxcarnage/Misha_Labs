#include "HRManagment.h"
#include <Windows.h>

Employee* ReturnHire(int answer)
{
	switch (answer)
	{
	case 1:
		return new PermanentEmployee;
		break;
	case 2:
		return new TemporaryEmployee;
		break;
	case 3:
		return new Manager;
		break;
	case 4:
		return new PermanentManager;
		break;
	case 5:
		return new Consultant;
		break;
	case 6:
		return new ConsultantManager;
		break;
	case 7:
		return new Director;
		break;
	}
}

void HireEmployeePanel(vector<Employee*>* employees)
{
	float answer;
	cout << "=========== ���� �� ������ ������� =============" << endl;
	cout << "1.����������� ���������" << endl;
	cout << "2.���������� ���������" << endl;
	cout << "3.���������" << endl;
	cout << "4.����������� ���������" << endl;
	cout << "5.������������" << endl;
	cout << "6.������������ - ���������" << endl;
	cout << "7.���������" << endl;
	cout << "================================================" << endl;
	Input(&answer, " �����", InputType::Answer, 7);
	Employee* employee;
	employee = ReturnHire((int)answer);
	employee->Hire();
	employees->push_back(employee);
}

void ShowEmployees(vector<Employee*> employees)
{
	if (employees.size() == 0)
	{
		cout << "� ��� ��� ����������! ������� ������" << endl;
		return;
	}
	TablePrinter tp(&cout);
	tp.AddColumn("��� ����������", 15);
	tp.AddColumn("���� ����������", 16);
	tp.AddColumn("������� ����������", 20);
	tp.PrintHeader();
	for (int i = 0; i < employees.size(); i++)
		employees[i]->Show(tp);
	tp.PrintFooter();
}

void CallCurentFunction(int answer, vector<Employee*>* employees)
{
	switch (answer)
	{
	case 1:
		HireEmployeePanel(employees);
		break;
	case 2:
		ShowEmployees(*employees);
		break;
	case 3:
		exit(0);
		break;
	}
}

void ShowPanel(vector<Employee*>* employees)
{
	float answer;
	cout << "================ �������� ������� =================" << endl;
	cout << "1.������ ����� ����������" << endl;
	cout << "2.�������� �����������" << endl;
	cout << "3.�����" << endl;
	cout << "===================================================" << endl;
	Input(&answer, " �����", InputType::Answer, 3);
	CallCurentFunction((int)answer, employees);
}

int main()
{
	vector<Employee*> employees;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		ShowPanel(&employees);
	}
	return 0;
}
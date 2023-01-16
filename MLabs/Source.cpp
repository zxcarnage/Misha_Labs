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
	cout << "=========== Кого вы хотите создать =============" << endl;
	cout << "1.Постоянного работника" << endl;
	cout << "2.Временного работника" << endl;
	cout << "3.Менеджера" << endl;
	cout << "4.Постоянного менеджера" << endl;
	cout << "5.Консультанта" << endl;
	cout << "6.Консультанта - менеджера" << endl;
	cout << "7.Директора" << endl;
	cout << "================================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 7);
	Employee* employee;
	employee = ReturnHire((int)answer);
	employee->Hire();
	employees->push_back(employee);
}

void ShowEmployees(vector<Employee*> employees)
{
	if (employees.size() == 0)
	{
		cout << "У вас нет работников! Наймите одного" << endl;
		return;
	}
	TablePrinter tp(&cout);
	tp.AddColumn("Имя сотрудника", 15);
	tp.AddColumn("Стаж сотрудника", 16);
	tp.AddColumn("Прибыль сотрудника", 20);
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
	cout << "================ Выберите вариант =================" << endl;
	cout << "1.Панель найма сотрудника" << endl;
	cout << "2.Показать сотрудников" << endl;
	cout << "3.Выход" << endl;
	cout << "===================================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 3);
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
#include "Hospital.h"

string FrameworkToString(Framework framework)
{
	switch (framework)
	{
	case Framework::Reanimation:
		return "����������";
	case Framework::Neurology:
		return "����������";
	case Framework::Venerology:
		return "�����������";
	default:
		return "����������";
	}
}

string SexToString(Sex sex)
{
	switch (sex)
	{
	case Sex::Man:
		return "�������";
	case Sex::Woman:
		return "�������";
	default:
		return "����";
	}
}

Framework InputFramework()
{
	float answer;
	cout << "����� ��������� ����� � �����?" << endl;
	cout << "1.����������" << endl;
	cout << "2.����������" << endl;
	cout << "3.�����������" << endl;
	Input(&answer, " �����", InputType::Answer, 3);
	return Framework((int)answer - 1);
}

Sex InputSex()
{
	float answer;
	cout << "����� ��� �����?" << endl;
	cout << "1.�������" << endl;
	cout << "2.�������" << endl;
	Input(&answer, " �����", InputType::Answer, 2);
	return Sex((int)answer - 1);
}

Framework Doctor::GetFramework()
{
	return framework;
}

void Doctor::Create()
{
	CharInput(Name, " ��� �������");
	Input(&Age, " ������� �������", InputType::Age);
	framework = InputFramework();
	_sex = InputSex();
}

void Doctor::Show(TablePrinter tp)
{
	tp << Name << Age << FrameworkToString(framework) << SexToString(_sex);
}

Doctor::Doctor()
{
	memset(Name, '\0', 20);
	Age = 0;
	framework = Framework::Empty;
	_sex = Sex::Man;
}

Hospital::Hospital()
{
	for (int i = 0; i < 10; i++)
	{
		_doctors[i] = Doctor();
	}
	_maxEmployees = 0;
	_maxPatients = 0;
	_maxPayment = 0;
}

Hospital::Hospital(bool showException) : Hospital()
{
	if (showException == true)
		throw new exception("� ��� �������� � ������������!");
}

void Hospital::Create()
{
	int index = 0;
	bool going = true;
	while (going && index < 9)
	{
		_doctors[index].Create();
		index++;
		float answer;
		cout << "���������� �� ��� ��������?" << endl;
		cout << "1.������ ��������" << endl;
		cout << "2.������" << endl;
		Input(&answer, " �����", InputType::Answer, 2);
		if (answer == 2)
			going = false;
	}
	Input(&_maxPatients, " ������������ ���������� ���������", InputType::IntNumber);
	Input(&_maxEmployees, " ������������ ���������� �����������", InputType::IntNumber);
	Input(&_maxPayment, " ������������ ��������", InputType::Number);
}

void Hospital::Show()
{
	if (_maxPatients == 0)
		return;
	int index = 0;
	TablePrinter tp(&cout);
	tp.AddColumn("���", 20);
	tp.AddColumn("�������", 9);
	tp.AddColumn("���������", 15);
	tp.AddColumn("���", 10);
	tp.PrintHeader();
	while (_doctors[index].GetFramework() != Framework::Empty && index < 10)
	{
		_doctors[index].Show(tp);
		index++;
	}
	tp.PrintFooter();
	tp = TablePrinter(&cout);
	tp.AddColumn("������������ ���������� ���������", 35);
	tp.AddColumn("������������ ���������� �����������", 37);
	tp.AddColumn("������������ ������", 21);
	tp.PrintHeader();
	tp << _maxPatients << _maxEmployees << _maxPayment;
	tp.PrintFooter();
}
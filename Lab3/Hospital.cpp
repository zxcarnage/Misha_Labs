#include "Hospital.h"

string FrameworkToString(Framework framework)
{
	switch (framework)
	{
	case Framework::Reanimation:
		return "Реанимация";
	case Framework::Neurology:
		return "Неврология";
	case Framework::Venerology:
		return "Венерология";
	default:
		return "Неизвестно";
	}
}

string SexToString(Sex sex)
{
	switch (sex)
	{
	case Sex::Man:
		return "Мужчина";
	case Sex::Woman:
		return "Женщина";
	default:
		return "Иное";
	}
}

Framework InputFramework()
{
	float answer;
	cout << "Какое отделение будет у врача?" << endl;
	cout << "1.Реанимация" << endl;
	cout << "2.Неврология" << endl;
	cout << "3.Венерология" << endl;
	Input(&answer, " ответ", InputType::Answer, 3);
	return Framework((int)answer - 1);
}

Sex InputSex()
{
	float answer;
	cout << "Какое пол врача?" << endl;
	cout << "1.Мужчина" << endl;
	cout << "2.Женщина" << endl;
	Input(&answer, " ответ", InputType::Answer, 2);
	return Sex((int)answer - 1);
}

Framework Doctor::GetFramework()
{
	return framework;
}

void Doctor::Create()
{
	CharInput(Name, " имя доктора");
	Input(&Age, " возраст доктора", InputType::Age);
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
		throw new exception("У вас проблема в конструкторе!");
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
		cout << "Достаточно ли вам докторов?" << endl;
		cout << "1.БОЛЬШЕ ДОКТОРОВ" << endl;
		cout << "2.Хватит" << endl;
		Input(&answer, " ответ", InputType::Answer, 2);
		if (answer == 2)
			going = false;
	}
	Input(&_maxPatients, " максимальное количество пациентов", InputType::IntNumber);
	Input(&_maxEmployees, " максимальное количество сотрудников", InputType::IntNumber);
	Input(&_maxPayment, " максимальную платежку", InputType::Number);
}

void Hospital::Show()
{
	if (_maxPatients == 0)
		return;
	int index = 0;
	TablePrinter tp(&cout);
	tp.AddColumn("Имя", 20);
	tp.AddColumn("Возраст", 9);
	tp.AddColumn("Отделение", 15);
	tp.AddColumn("Пол", 10);
	tp.PrintHeader();
	while (_doctors[index].GetFramework() != Framework::Empty && index < 10)
	{
		_doctors[index].Show(tp);
		index++;
	}
	tp.PrintFooter();
	tp = TablePrinter(&cout);
	tp.AddColumn("Максимальное количество пациентов", 35);
	tp.AddColumn("Максимальное количество сотрудников", 37);
	tp.AddColumn("Максимальный платеж", 21);
	tp.PrintHeader();
	tp << _maxPatients << _maxEmployees << _maxPayment;
	tp.PrintFooter();
}
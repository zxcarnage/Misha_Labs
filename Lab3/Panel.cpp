#include "Panel.h"

Hospital ShowException()
{
	try
	{
		return new Hospital(true);
	}
	catch (...)
	{
		cout << "Исключение в конструкторе" << endl;
	}
}

void CallCurrentFunction(int answer, Hospital* hospital)
{
	switch (answer)
	{
	case 1:
		hospital->Create();
		break;
	case 2:
		hospital->Show();
		break;
	case 3:
		ShowException();
		break;
	case 4:
		exit(0);
	}
}

void ShowPanel(Hospital* hospital)
{	
	float answer;
	cout << "================= Выберите =================" << endl;
	cout << "1.Создать больницу" << endl;
	cout << "2.Показать созданную больницу" << endl;
	cout << "3.Показать исключение в конструкторе" << endl;
	cout << "4.Выход" << endl;
	cout << "============================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 4);
	CallCurrentFunction((int)answer, hospital);
}
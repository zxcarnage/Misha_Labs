#include "Panel.h"

Hospital ShowException()
{
	try
	{
		return new Hospital(true);
	}
	catch (...)
	{
		cout << "���������� � ������������" << endl;
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
	cout << "================= �������� =================" << endl;
	cout << "1.������� ��������" << endl;
	cout << "2.�������� ��������� ��������" << endl;
	cout << "3.�������� ���������� � ������������" << endl;
	cout << "4.�����" << endl;
	cout << "============================================" << endl;
	Input(&answer, " �����", InputType::Answer, 4);
	CallCurrentFunction((int)answer, hospital);
}
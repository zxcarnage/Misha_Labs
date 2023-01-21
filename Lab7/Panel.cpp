#include "Panel.h"

void Panel::CallCurrent(int answer)
{
	switch (answer)
	{
	case 1:
		_delivery.Order();
		break;
	case 2:
		_delivery.Delete();
		break;
	case 3:
		_delivery.Show();
		break;
	case 4:
		_delivery.Edit();
		break;
	case 5:
		exit(0);
		break;
	}
}

void Panel::ShowPanel()
{
	float answer;
	cout << "================= �������� =================" << endl;
	cout << "1.�������� ��������" << endl;
	cout << "2.������� �����" << endl;
	cout << "3.�������� �������" << endl;
	cout << "4.������������� �����" << endl;
	cout << "5.�����" << endl;
	cout << "============================================" << endl;
	Input(&answer, " �����", Answer, 5);
	system("cls");
	CallCurrent((int)answer);
}
#include "Panel.h"

void Panel::ShowAirtickets(vector<Airticket> airtickets)
{
	if (airtickets.empty())
		return;
	TablePrinter tp(&cout);
	tp.AddColumn("ID", 4);
	tp.AddColumn("��� ���������", 15);
	tp.AddColumn("�������", 15);
	tp.AddColumn("���� ������", 15);
	tp.AddColumn("������ ������", 15);
	tp.AddColumn("������ �������", 20);
	tp.PrintHeader();
	for (int i = 0; i < airtickets.size(); i++)
	{
		Airticket airticket = airtickets.at(i);
		tp << i + 1 << airticket.GetName() << airticket.GetAge() << airticket.GetDate() << airticket.GetDepature() << airticket.GetDestination();
	}
	tp.PrintFooter();
}

void Panel::WriteAirtickets()
{
	ofstream("dataBase.txt");
	ofstream fout;
	fout.open("dataBase.txt", ofstream::app);
	TablePrinter tp(&fout);
	tp.AddColumn("ID", 4);
	tp.AddColumn("��� ���������", 15);
	tp.AddColumn("�������", 15);
	tp.AddColumn("���� ������", 15);
	tp.AddColumn("������ ������", 15);
	tp.AddColumn("������ �������", 20);
	tp.PrintHeader();
	for (int i = 0; i < _airtickets.size(); i++)
	{
		Airticket airticket = _airtickets.at(i);
		tp << i + 1 << airticket.GetName() << airticket.GetAge() << airticket.GetDate() << airticket.GetDepature() << airticket.GetDestination();
	}
	tp.PrintFooter();
	fout.close();
}

void Panel::DeleteTicket()
{
	float answer;
	ShowAirtickets(_airtickets);
	cout << "��� ����� ������� ������ �� ������ �������?" << endl;
	Input(&answer, " �����", InputType::IndexNumber, _airtickets.size());
	_airtickets.erase(_airtickets.begin() + (int)answer - 1);
}

void Panel::OrderTicket()
{
	Airticket airticket;
	airticket.Create();
	_airtickets.push_back(airticket);
}

void Panel::EditTicket()
{
	float answer;
	ShowAirtickets(_airtickets);
	cout << "��� ����� ������� ������ �� ������ �������������?" << endl;
	Input(&answer, " �����", InputType::IndexNumber, _airtickets.size());
	_airtickets.at((int)answer - 1).Create();
}

void Panel::SortName()
{
	map<string, Airticket> airtickets;
	for (int i = 0; i < _airtickets.size(); i++)
	{
		Airticket airticket = _airtickets.at(i);
		airtickets.insert({ airticket.GetName(), airticket });
	}
	_airtickets.clear();
	for (auto element : airtickets)
		_airtickets.push_back(element.second);
}

void Panel::SortAge()
{
	map<int, Airticket> airtickets;
	for (int i = 0; i < _airtickets.size(); i++)
	{
		Airticket airticket = _airtickets.at(i);
		airtickets.insert({ airticket.GetAge(), airticket });
	}
	_airtickets.clear();
	for (auto element : airtickets)
		_airtickets.push_back(element.second);
}

void Panel::SortYear()
{
	map<int, Airticket> airtickets;
	for (int i = 0; i < _airtickets.size(); i++)
	{
		Airticket airticket = _airtickets.at(i);
		airtickets.insert({ airticket.GetYear(), airticket });
	}
	_airtickets.clear();
	for (auto element : airtickets)
		_airtickets.push_back(element.second);
}

void Panel::CallSort(int answer)
{
	switch (answer)
	{
	case 1:
		SortName();
		break;
	case 2:
		SortAge();
		break;
	case 3:
		SortYear();
		break;
	}
}

void Panel::SortTicket()
{
	float answer;
	cout << "�� ������ �������� ����� �����������?" << endl;
	cout << "1.�����" << endl;
	cout << "2.��������" << endl;
	cout << "3.���� ������ ������" << endl;
	cout << "4.���������" << endl;
	Input(&answer, " �����", InputType::Answer, 4);
	CallSort((int)answer);
}

vector<Airticket> Panel::FindName()
{
	vector<Airticket> airtickets;
	string name;
	StringInput(&name, " ���");
	for (int i = 0; i < _airtickets.size(); i++)
	{
		if (_airtickets.at(i).GetName() == name)
			airtickets.push_back(_airtickets.at(i));
	}
	return airtickets;
}

vector<Airticket> Panel::FindAge()
{
	vector<Airticket> airtickets;
	float age;
	Input(&age, " �������", InputType::IntNumber);
	for (int i = 0; i < _airtickets.size(); i++)
	{
		if (_airtickets.at(i).GetAge() == (int)age)
			airtickets.push_back(_airtickets.at(i));
	}
	return airtickets;
}

vector<Airticket> Panel::FindYear()
{
	vector<Airticket> airtickets;
	float year;
	Input(&year, " ���", InputType::IntNumber);
	for (int i = 0; i < _airtickets.size(); i++)
	{
		if (_airtickets.at(i).GetYear() == (int)year)
			airtickets.push_back(_airtickets.at(i));
	}
	return airtickets;
}

void Panel::CallFind(int answer)
{
	vector<Airticket> findedAirticket;
	switch (answer)
	{
	case 1:
		findedAirticket = FindName();
		break;
	case 2:
		findedAirticket = FindAge();
		break;
	case 3:
		findedAirticket = FindYear();
		break;
	}
	ShowAirtickets(findedAirticket);
}

void Panel::FindTicket()
{
	float answer;
	cout << "�� ������ �������� ����� ������?" << endl;
	cout << "1.�����" << endl;
	cout << "2.��������" << endl;
	cout << "3.���� ������ ������" << endl;
	cout << "4.���������" << endl;
	Input(&answer, " �����", InputType::Answer, 4);
	CallFind((int)answer);
}

void Panel::CallCurrent(int answer)
{
	switch (answer)
	{
	case 1:
		OrderTicket();
		break;
	case 2:
		DeleteTicket();
		break;
	case 3:
		EditTicket();
		break;
	case 4:
		SortTicket();
		break;
	case 5:
		FindTicket();
		break;
	case 6:
		ShowAirtickets(_airtickets);
		break;
	case 7:
		WriteAirtickets();
		break;
	case 8:
		exit(0);
		break;
	}
}

void Panel::ShowPanel()
{
	float answer;
	cout << "================= �������� =================" << endl;
	cout << "1.�������� �����" << endl;
	cout << "2.������� �����" << endl;
	cout << "3.������������� ������" << endl;
	cout << "4.����������� ������" << endl;
	cout << "5.����� �����" << endl;
	cout << "6.�������� ������" << endl;
	cout << "7.�������� ������ � ����" << endl;
	cout << "8.�����" << endl;
	cout << "============================================" << endl;
	Input(&answer, " �����", InputType::Answer, 8);
	system("cls");
	CallCurrent((int)answer);
}
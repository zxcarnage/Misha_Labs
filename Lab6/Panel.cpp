#include "Panel.h"

void Panel::ShowAirtickets(vector<Airticket> airtickets)
{
	if (airtickets.empty())
		return;
	TablePrinter tp(&cout);
	tp.AddColumn("ID", 4);
	tp.AddColumn("Имя заказчика", 15);
	tp.AddColumn("Возраст", 15);
	tp.AddColumn("Дата заказа", 15);
	tp.AddColumn("Страна вылета", 15);
	tp.AddColumn("Страна прилета", 20);
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
	tp.AddColumn("Имя заказчика", 15);
	tp.AddColumn("Возраст", 15);
	tp.AddColumn("Дата заказа", 15);
	tp.AddColumn("Страна вылета", 15);
	tp.AddColumn("Страна прилета", 20);
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
	cout << "Под каким номером билета вы хотите удалить?" << endl;
	Input(&answer, " ответ", InputType::IndexNumber, _airtickets.size());
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
	cout << "Под каким номером билета вы хотите редактировать?" << endl;
	Input(&answer, " ответ", InputType::IndexNumber, _airtickets.size());
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
	cout << "По какому признаку будем сортировать?" << endl;
	cout << "1.Имени" << endl;
	cout << "2.Возрасту" << endl;
	cout << "3.Году заказа билета" << endl;
	cout << "4.Вернуться" << endl;
	Input(&answer, " ответ", InputType::Answer, 4);
	CallSort((int)answer);
}

vector<Airticket> Panel::FindName()
{
	vector<Airticket> airtickets;
	string name;
	StringInput(&name, " имя");
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
	Input(&age, " возраст", InputType::IntNumber);
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
	Input(&year, " год", InputType::IntNumber);
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
	cout << "По какому признаку будем искать?" << endl;
	cout << "1.Имени" << endl;
	cout << "2.Возрасту" << endl;
	cout << "3.Году заказа билета" << endl;
	cout << "4.Вернуться" << endl;
	Input(&answer, " ответ", InputType::Answer, 4);
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
	cout << "================= Выберите =================" << endl;
	cout << "1.Заказать билет" << endl;
	cout << "2.Удалить билет" << endl;
	cout << "3.Редактировать билеты" << endl;
	cout << "4.Сортировать билеты" << endl;
	cout << "5.Найти билет" << endl;
	cout << "6.Показать билеты" << endl;
	cout << "7.Записать билеты в файл" << endl;
	cout << "8.Выйти" << endl;
	cout << "============================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 8);
	system("cls");
	CallCurrent((int)answer);
}
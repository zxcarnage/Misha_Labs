#include "Ticket.h"

void InputEnum(Country& country)
{
	float answer;
	cout << "1.������" << endl;
	cout << "2.������" << endl;
	cout << "3.������" << endl;
	cout << "4.���" << endl;
	cout << "5.��������" << endl;
	Input(&answer, " �����", Answer, 5);
	country = Country((int)answer - 1);
}

void Person::Create()
{
	StringInput(&_name, " ���");
	Input(&_age, " �������", Age);
}

string Airticket::EnumToString(Country country)
{
	switch (country)
	{
	case Country::Egypt:
		return "������";
	case Country::Turkey:
		return "������";
	case Country::Russia:
		return "������";
	case Country::USA:
		return "���";
	case Country::Germany:
		return "��������";
	}
}

void Airticket::Create()
{
	Customer.Create();
	DateInput(Date, " ���� ������");
	cout << "������� ������ ������" << endl;
	InputEnum(_depature);
	cout << "������� ������ �������" << endl;
	InputEnum(_destination);
}

string Airticket::GetName()
{
	return Customer.GetName();
}

int Airticket::GetAge()
{
	return Customer.GetAge();
}

int Airticket::GetYear()
{
	int year;
	year = (Date[6] - 48) * 1000 + (Date[7] - 48) * 100 + (Date[8] - 48) * 10 + (Date[9] - 48);
	return year;
}

string Airticket::GetDate()
{
	return Date;
}

string Airticket::GetDestination()
{
	return EnumToString(_destination);
}

string Airticket::GetDepature()
{
	return EnumToString(_depature);
}

string Person::GetName()
{
	return _name;
}

float Person::GetAge()
{
	return _age;
}

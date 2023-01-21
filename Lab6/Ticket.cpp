#include "Ticket.h"

void InputEnum(Country& country)
{
	float answer;
	cout << "1.Египет" << endl;
	cout << "2.Турция" << endl;
	cout << "3.Россия" << endl;
	cout << "4.США" << endl;
	cout << "5.Германия" << endl;
	Input(&answer, " ответ", Answer, 5);
	country = Country((int)answer - 1);
}

void Person::Create()
{
	StringInput(&_name, " имя");
	Input(&_age, " возраст", Age);
}

string Airticket::EnumToString(Country country)
{
	switch (country)
	{
	case Country::Egypt:
		return "Египет";
	case Country::Turkey:
		return "Турция";
	case Country::Russia:
		return "Россия";
	case Country::USA:
		return "США";
	case Country::Germany:
		return "Германия";
	}
}

void Airticket::Create()
{
	Customer.Create();
	DateInput(Date, " дату вылета");
	cout << "Введите страну вылета" << endl;
	InputEnum(_depature);
	cout << "Введите страну прилета" << endl;
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

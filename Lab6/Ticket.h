#pragma once
#include <iostream>
#include "TablePrinter.h"
#include "Input.h"
using std::string;

enum class Country
{
	Egypt,
	Turkey,
	Russia,
	USA,
	Germany
};

class Customer
{
	string _name;
	float _age;
public:
	string GetName();
	float GetAge();
	void Create();
};

class Ticket
{
protected:
	Customer Customer;
	string Date;
};

class Airticket : Ticket
{
	Country _depature;
	Country _destination;
	string EnumToString(Country country);
public:
	void Create();
	string GetName();
	int GetAge();
	int GetYear();
	string GetDate();
	string GetDestination();
	string GetDepature();
};
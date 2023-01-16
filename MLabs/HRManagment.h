#pragma once
#include <vector>
#include "Input.h"
#include "TablePrinter.h"
using std::vector;
class Employee
{
protected:
	string Name;
	float Income;
	int Experience;
public:
	Employee();
	void Hire();
	void Show(TablePrinter tp);
};

class PermanentEmployee : public virtual Employee
{
public:
	PermanentEmployee();
};

class TemporaryEmployee : public virtual Employee
{
public:
	TemporaryEmployee();
};

class Manager : public virtual Employee
{
public:
	Manager();
};

class PermanentManager : public PermanentEmployee, public Manager
{
public:
	PermanentManager();
};
	
class Consultant : public virtual TemporaryEmployee
{
public:
	Consultant();
};

class ConsultantManager : public Consultant, public Manager
{
public:
	ConsultantManager();
};

class Director : public Manager
{
public:
	Director();
};


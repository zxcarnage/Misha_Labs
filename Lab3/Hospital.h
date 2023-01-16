#pragma once
#include "Input.h"
#include "TablePrinter.h"
enum class Framework
{
	Reanimation,
	Neurology,
	Venerology,
	Empty
};

enum class Sex
{
	Man,
	Woman
};

class Employee
{
protected:
	char Name[20];
	float Age;
};

class HospitalEmployee : public Employee
{
protected:
	Framework framework;
};

class Doctor : HospitalEmployee
{
	Sex _sex;
public:
	Doctor();
	void Create();
	void Show(TablePrinter tp);
	Framework GetFramework();
};

class Hospital
{
	Doctor _doctors[10];
	float _maxPatients;
	float _maxEmployees;
	float _maxPayment;
public:
	Hospital();
	Hospital(bool showException);
	void Create();
	void Show();
};
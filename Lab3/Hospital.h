#pragma once
#include "Input.h"
#include "TablePrinter.h"
#include <fstream>
#include <Algorithm>
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::sort;

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
	char* GetName();
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
	void Show(TablePrinter tp = TablePrinter(&cout), int index = 1);
	void Write();
	float GetPrice();
	float GetEmployees();
	float GetPatients();
	bool ContainsDoctor(string name);
	static void SortFile();
	static void EditFile();
	static void DeleteFile();
	static void Search();
	static vector<Hospital> ShowFile();
	friend istream& operator >>(istream& stream, Hospital &hospital);
	friend ostream& operator <<(ostream& sstream, Hospital& hospital);
};
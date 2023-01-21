#include "Hospital.h"

istream& operator >>(istream& stream, Hospital& hospital) {
	hospital.Create();
	return stream;
}
ostream& operator <<(ostream& stream, Hospital& hospital) {
	hospital.Show();
	return stream;
}

string FrameworkToString(Framework framework)
{
	switch (framework)
	{
	case Framework::Reanimation:
		return "Реанимация";
	case Framework::Neurology:
		return "Неврология";
	case Framework::Venerology:
		return "Венерология";
	default:
		return "Неизвестно";
	}
}

string SexToString(Sex sex)
{
	switch (sex)
	{
	case Sex::Man:
		return "Мужчина";
	case Sex::Woman:
		return "Женщина";
	default:
		return "Иное";
	}
}

Framework InputFramework()
{
	float answer;
	cout << "Какое отделение будет у врача?" << endl;
	cout << "1.Реанимация" << endl;
	cout << "2.Неврология" << endl;
	cout << "3.Венерология" << endl;
	Input(&answer, " ответ", InputType::Answer, 3);
	return Framework((int)answer - 1);
}

Sex InputSex()
{
	float answer;
	cout << "Какое пол врача?" << endl;
	cout << "1.Мужчина" << endl;
	cout << "2.Женщина" << endl;
	Input(&answer, " ответ", InputType::Answer, 2);
	return Sex((int)answer - 1);
}

Framework Doctor::GetFramework()
{
	return framework;
}

void Doctor::Create()
{
	CharInput(Name, " имя доктора");
	Input(&Age, " возраст доктора", InputType::Age);
	framework = InputFramework();
	_sex = InputSex();
}

char* Doctor::GetName()
{
	return Name;
}

void Doctor::Show(TablePrinter tp)
{
	tp << Name << Age << FrameworkToString(framework) << SexToString(_sex);
}

Doctor::Doctor()
{
	memset(Name, '\0', 20);
	Age = 0;
	framework = Framework::Empty;
	_sex = Sex::Man;
}

Hospital::Hospital()
{
	for (int i = 0; i < 10; i++)
	{
		_doctors[i] = Doctor();
	}
	_maxEmployees = 0;
	_maxPatients = 0;
	_maxPayment = 0;
}

Hospital::Hospital(bool showException) : Hospital()
{
	if (showException == true)
		throw new exception("У вас проблема в конструкторе!");
}

void Hospital::Create()
{
	int index = 0;
	bool going = true;
	while (going && index < 9)
	{
		_doctors[index].Create();
		index++;
		float answer;
		cout << "Достаточно ли вам докторов?" << endl;
		cout << "1.БОЛЬШЕ ДОКТОРОВ" << endl;
		cout << "2.Хватит" << endl;
		Input(&answer, " ответ", InputType::Answer, 2);
		if (answer == 2)
			going = false;
	}
	Input(&_maxPatients, " максимальное количество пациентов", InputType::IntNumber);
	Input(&_maxEmployees, " максимальное количество сотрудников", InputType::IntNumber);
	Input(&_maxPayment, " максимальную платежку", InputType::Number);
}

void Hospital::Show(TablePrinter tp, int hospitalIndex)
{
	if (_maxPatients == 0)
		return;
	int index = 0;
	tp.AddColumn("ID", 4);
	tp.PrintHeader();
	tp << hospitalIndex;
	tp.PrintFooter();
	tp = TablePrinter(&cout);
	tp.AddColumn("Имя", 20);
	tp.AddColumn("Возраст", 9);
	tp.AddColumn("Отделение", 15);
	tp.AddColumn("Пол", 10);
	tp.PrintHeader();
	while (_doctors[index].GetFramework() != Framework::Empty && index < 10)
	{
		_doctors[index].Show(tp);
		index++;
	}
	tp.PrintFooter();
	tp = TablePrinter(&cout);
	tp.AddColumn("Максимальное количество пациентов", 35);
	tp.AddColumn("Максимальное количество сотрудников", 37);
	tp.AddColumn("Максимальный платеж", 21);
	tp.PrintHeader();
	tp << _maxPatients << _maxEmployees << _maxPayment;
	tp.PrintFooter();
}

void WriteVectorInFile(vector <Hospital> hospitals)
{
	ofstream fout;
	fout.open("dataBase.txt", ofstream::binary | ofstream::app);
	if (!fout.good() || fout.fail())
		return;
	for (int i = 0; i < hospitals.size(); i++)
	{
		hospitals.at(i).Write();
	}
	if (!fout.eof())
		return;
	fout.close();
}

void Hospital::Write()
{
	ofstream fout;
	fout.open("dataBase.txt", ofstream::app | ofstream::binary);
	fout.write((char*)this, sizeof(Hospital));
	fout.close();
}

float Hospital::GetPrice()
{
	return _maxPayment;
}

float Hospital::GetEmployees()
{
	return _maxEmployees;
}

float Hospital::GetPatients()
{
	return _maxPatients;
}

void Hospital::EditFile()
{
	float answer;
	vector<Hospital> hospitals;
	hospitals = ShowFile();
	cout.setf(ios::boolalpha | ios::hex | ios::showbase);
	cout << "Под каким номером больницу вы хотите редактировать?" << endl;
	Input(&answer, " ответ", InputType::IndexNumber, hospitals.size());
	hospitals.at((int)answer - 1).Create();
	ofstream("dataBase.txt");
	WriteVectorInFile(hospitals);
}

vector<Hospital> Hospital::ShowFile()
{
	int index = 1;
	ifstream fin;
	Hospital hospital;
	vector <Hospital> hospitals;
	TablePrinter tp(&cout);
	fin.open("dataBase.txt", ifstream::binary);
	if (!fin.is_open() || fin.bad())
		cout << "Что-то пошло не так" << endl;
	while (fin.read((char*)&hospital, sizeof(Hospital)))
	{
		hospitals.push_back(hospital);
		hospital.Show(tp, index);
		index++;
	}
	fin.close();
	return hospitals;
}

void Hospital::DeleteFile()
{
	float answer;
	vector<Hospital> hospitals;
	hospitals = ShowFile();
	cout << "Под каким номером больницу вы хотите удалить?" << endl;
	Input(&answer, " ответ", InputType::IndexNumber, hospitals.size());
	hospitals.erase(hospitals.begin() + (int)answer - 1);
	ofstream("dataBase.txt");
	WriteVectorInFile(hospitals);
}

bool Hospital::ContainsDoctor(string name)
{
	int index = 0;
	while (_doctors[index].GetFramework() != Framework::Empty)
		if (_doctors[index].GetName() == name)
			return true;

	return false;
}

vector<Hospital> SearchName()
{
	string name;
	ifstream fin;
	Hospital hospital;
	vector<Hospital> findedHospitals;
	fin.open("dataBase.txt");
	StringInput(&name, " имя доктора");
	while (fin.read((char*)&hospital, sizeof(Hospital)))
	{
		if (hospital.ContainsDoctor(name))
			findedHospitals.push_back(hospital);
	}
	return findedHospitals;
}

vector<Hospital> SearchPrice()
{
	float price;
	ifstream fin;
	Hospital hospital;
	vector<Hospital> findedHospitals;
	fin.open("dataBase.txt");
	Input(&price, " верхнюю грань цены", InputType::Number);
	while (fin.read((char*)&hospital, sizeof(Hospital)))
	{
		if (hospital.GetPrice() < price)
			findedHospitals.push_back(hospital);
	}
	return findedHospitals;
}

void CallCurrentSearch(int answer)
{
	vector<Hospital> hospitals;
	switch (answer)
	{
	case 1:
		hospitals = SearchName();
		break;
	case 2:
		hospitals = SearchPrice();
		break;
	}
	for (int i = 0; i < hospitals.size(); i++)
	{
		hospitals.at(i).Show();
	}
}

void ShowSearch()
{
	float answer;
	cout << "По каким признакам вы хотите искать?" << endl;
	cout << "1.Все где есть доктор с именем..." << endl;
	cout << "2.Все где плата меньше чем..." << endl;
	Input(&answer, " ответ", InputType::Answer, 2);
	CallCurrentSearch((int)answer);
}

void Hospital::Search()
{
	ShowSearch();
}

bool EmployeesPredicate(Hospital& first, Hospital& second)
{
	return first.GetEmployees() < second.GetEmployees();
}

bool PatientPredicate(Hospital& first, Hospital& second)
{
	return first.GetPatients() < second.GetPatients();
}

bool PaymentPredicate(Hospital& first, Hospital& second)
{
	return first.GetPrice() < second.GetPrice();
}

void SortEmployees(vector<Hospital>* sortedHospitals)
{
	sort((*sortedHospitals).begin(), (*sortedHospitals).end(), EmployeesPredicate);
}

void SortPatients(vector<Hospital>* sortedHospitals)
{
	sort((*sortedHospitals).begin(), (*sortedHospitals).end(), PatientPredicate);
}

void SortPayment(vector<Hospital>* sortedHospitals)
{
	sort((*sortedHospitals).begin(), (*sortedHospitals).end(), PaymentPredicate);
}

void CallCurrentSort(int answer)
{
	Hospital hospital;
	ofstream fout;
	cout << "Предыдущее содержание " << endl;
	vector<Hospital> sortedHospitals = Hospital::ShowFile();
	ofstream("dataBase.txt");
	fout.open("dataBase.txt", ofstream::binary | ofstream::app);
	switch (answer)
	{
	case 1:
		SortEmployees(&sortedHospitals);
		break;
	case 2:
		SortPatients(&sortedHospitals);
		break;
	case 3:
		SortPayment(&sortedHospitals);
		break;
	}
	for (int i = 0; i < sortedHospitals.size(); i++)
	{
		fout.write((char*)&sortedHospitals.at(i), sizeof(Hospital));
	}
	cout << "Отсортировано!" << endl;
	fout.close();
}

void ShowSort()
{
	float answer;
	cout << "По каким признакам вы хотите сортировать?" << endl;
	cout << "1.По максимальному количеству состава" << endl;
	cout << "2.По максимальному количеству пациентов" << endl;
	cout << "3.По максимальному платежу" << endl;
	Input(&answer, " ответ", InputType::Answer, 3);
	CallCurrentSort((int)answer);
}

void Hospital::SortFile()
{
	ShowSort();
}
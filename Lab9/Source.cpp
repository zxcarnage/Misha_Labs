#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int intInput(int min_val = INT_MIN, int max_val = INT_MAX) {
	int input;
	while (!(cin >> input) || input < min_val || input > max_val) {
		if (!cin)
			cout << "Ошибочные данные на вводе. ";
		else
			cout << "Выход за пределы допустимого значения. ";
		cin.clear();
		cin.ignore(10, '\n');
		cout << "Повторите ввод целочисленного значения\n";
	}
	cin.ignore(10, '\n');
	return input;
}
class format
{
protected:
	string what;
	string form;
};
enum Editors { PHOTOSHOP, PAINT };
class Editor
{
public:
	virtual void add() = 0;
	virtual void print() = 0;
	virtual void edit() = 0;
	virtual void del() = 0;
	virtual ~Editor() {};
};

class EditFormat
{
public:
	virtual format* makeFormat() const = 0;
};

class EditorSpec
{
public:
	virtual Editors EditorType() const = 0;
};
class PhotoshopSpec : public EditorSpec
{
public:
	Editors EditorType() const { return PHOTOSHOP; };
	bool is_vector;
};


class PSD : public format
{

public:
	void add()
	{
		ofstream fout("format.txt", ios::app);
		fout << "Photoshop" << '\t' << ".PSD" << endl;
		cout << "Информация была успешно добавлена" << endl;
		fout.close();
	}
	void print()
	{
		ifstream fin("format.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		cout << "\n\n";
		cout << "|" << setw(2) << "id" << setw(12) << "Editor" << setw(18) << "Format" << " |" << endl;
		cout << "|                                 |" << endl;
		int i = 1;
		while (!fin.eof())
		{
			fin >> this->what >> this->form;
			if (fin.eof())
				break;
			cout << "|" << setw(2) << i << setw(12) << this->what << setw(18) << this->form << " |" << endl;
			i++;
		}
		fin.close();
	}
};
class JPEG : public format
{
public:
	void add()
	{
		ofstream fout("format.txt", ios::app);
		fout << "Paint" << '\t' << ".JPEG" << endl;
		cout << "Информация была успешно добавлена" << endl;
		fout.close();
	}
	void print()
	{
		ifstream fin("format.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		cout << "\n\n";
		cout << "|" << setw(2) << "id" << setw(12) << "Editor" << setw(18) << "Format" << " |" << endl;
		cout << "|                                 |" << endl;
		int i = 1;
		while (!fin.eof())
		{
			fin >> this->what >> this->form;
			if (fin.eof())
				break;
			cout << "|" << setw(2) << i << setw(12) << this->what << setw(18) << this->form << " |" << endl;
			i++;
		}
		fin.close();
	}
};

class Base
{
public:
	virtual void add() = 0;
	virtual void print() = 0;
	virtual void edit() = 0;
	virtual void del() = 0;
	virtual Base* clone() const = 0;
};

class Photoshop : public Editor
{
	string LayerName;
	string FontName;
public:
	Photoshop() {}
	Photoshop(const PhotoshopSpec* buildingSpec) {}
	void add()
	{
		ofstream fout("Photoshop.txt", ios::app);
		cout << "Введите название нового слоя: ";
		cin >> this->LayerName;
		cout << "Введите название шрифта: ";
		cin >> this->FontName;
		fout << this->LayerName << '\t' << this->FontName << endl;
	}
	void print()
	{
		ifstream fin("Photoshop.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		cout << "\n\n";
		cout << "|" << setw(2) << "id" << setw(12) << "Layer" << setw(18) << "Font" << " |" << endl;
		cout << "|                                 |" << endl;
		int i = 1;
		while (fin.peek() != EOF)
		{
			fin >> this->LayerName >> this->FontName;
			if (fin.eof())
				break;
			cout << "|" << setw(2) << i << setw(12) << this->LayerName << setw(18) << this->FontName << " |" << endl;
			i++;
		}
		fin.close();
	}
	void in_file()
	{
		ifstream fin("temp.txt");
		ofstream fout("Photoshop.txt", ios::app);
		Photoshop ps;
		cout << "Что вы хотите изменить?\n1. Назавние слоя\n2. Шрифт" << endl;
		int ch = intInput(1, 2);
		if (ch == 1)
		{
			fin >> ps.LayerName >> ps.FontName;
			cout << "Введите новое название слоя: ";
			cin >> ps.LayerName;
			fout << ps.LayerName << '\t' << ps.FontName << endl;
		}
		else
		{
			fin >> ps.LayerName >> ps.FontName;
			cout << "Введите новый шрифт: ";
			cin >> ps.FontName;
			fout << ps.LayerName << '\t' << ps.FontName << endl;
		}
		fin.close();
		fout.close();
	}
	void edit()
	{
		ifstream fin("Photoshop.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		Photoshop ps;
		vector<Photoshop> v;
		while (!fin.eof())
		{
			fin >> ps.LayerName >> ps.FontName;
			if (fin.eof())
				break;
			v.push_back(ps);
		}
		fin.close();
		cout << "Ввыберите какой слой вы хотите изменить: ";
		int ch = intInput(1, v.size());
		ch--;
		ofstream fout1("temp.txt");
		fout1 << v.at(ch).LayerName << '\t' << v.at(ch).FontName << endl;
		v.erase(v.begin() + ch);
		fout1.close();
		ofstream fout("Photoshop.txt");
		for (size_t i = 0; i < v.size(); i++)
			fout << v.at(i).LayerName << '\t' << v.at(i).FontName << endl;
		fout.close();
		ps.in_file();
		cout << "Изменение прошло успешно!" << endl;
	}
	void del()
	{
		ifstream fin("Photoshop.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}

		vector<string> v;
		string s;
		while (getline(fin, s))
			v.push_back(s);
		fin.close();
		cout << "Какой слой вы хотите удалить? ";
		int ch = intInput(1, v.size());
		ch--;
		v.erase(v.begin() + ch);
		ofstream fout("Photoshop.txt");
		copy(v.begin(), v.end(),
			ostream_iterator<string>(fout, "\n"));
		fout.close();
		cout << "Удаление прошло успешно!" << endl;

	}
	static Editor* make() { return new Photoshop; }
	PSD* makeFormat() const { return new PSD; };
};
class Paint : public Editor
{
	string LayerName;
	string FontName;
public:
	Paint() {}
	void add()
	{
		ofstream fout("Paint.txt", ios::app);
		cout << "Введите название нового слоя: ";
		cin >> this->LayerName;
		cout << "Введите название шрифта: ";
		cin >> this->FontName;
		fout << this->LayerName << '\t' << this->FontName << endl;
	}
	void print()
	{
		ifstream fin("Paint.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		cout << "\n\n";
		cout << "|" << setw(2) << "id" << setw(12) << "Layer" << setw(18) << "Font" << " |" << endl;
		cout << "|                                 |" << endl;
		int i = 1;
		while (fin.peek() != EOF)
		{
			fin >> this->LayerName >> this->FontName;
			if (fin.eof())
				break;
			cout << "|" << setw(2) << i << setw(12) << this->LayerName << setw(18) << this->FontName << " |" << endl;
			i++;
		}
		fin.close();
	}
	void in_file()
	{
		ifstream fin("temp.txt");
		ofstream fout("Paint.txt", ios::app);
		Paint p;
		cout << "Что вы хотите изменить?\n1. Назавние слоя\n2. Шрифт" << endl;
		int ch = intInput(1, 2);
		if (ch == 1)
		{
			fin >> p.LayerName >> p.FontName;
			cout << "Введите новое название слоя: ";
			cin >> p.LayerName;
			fout << p.LayerName << '\t' << p.FontName << endl;
		}
		else
		{
			fin >> p.LayerName >> p.FontName;
			cout << "Введите новый шрифт: ";
			cin >> p.FontName;
			fout << p.LayerName << '\t' << p.FontName << endl;
		}
		fin.close();
		fout.close();
	}
	void edit()
	{
		ifstream fin("Paint.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		Paint p;
		vector<Paint> v;
		while (!fin.eof())
		{
			fin >> p.LayerName >> p.FontName;
			if (fin.eof())
				break;
			v.push_back(p);
		}
		fin.close();
		cout << "Ввыберите какой слой вы хотите изменить: ";
		int ch = intInput(1, v.size());
		ch--;
		ofstream fout1("temp.txt");
		fout1 << v.at(ch).LayerName << '\t' << v.at(ch).FontName << endl;
		v.erase(v.begin() + ch);
		fout1.close();
		ofstream fout("Paint.txt");
		for (size_t i = 0; i < v.size(); i++)
			fout << v.at(i).LayerName << '\t' << v.at(i).FontName << endl;
		fout.close();
		p.in_file();
		cout << "Изменение прошло успешно!" << endl;
	}
	void del()
	{
		ifstream fin("Paint.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}

		vector<string> v;
		string s;
		while (getline(fin, s))
			v.push_back(s);
		fin.close();
		cout << "Какой слой вы хотите удалить? ";
		int ch = intInput(1, v.size());
		ch--;
		v.erase(v.begin() + ch);
		ofstream fout("Paint.txt");
		copy(v.begin(), v.end(),
			ostream_iterator<string>(fout, "\n"));
		fout.close();
		cout << "Удаление прошло успешно!" << endl;

	}
	static Editor* make() { return new Paint; }
	JPEG* makeFormat() const { return new JPEG; };
};


Editor* MakeEdit(Editors EditType)
{
	switch (EditType)
	{
	case PHOTOSHOP: return new Photoshop();
	case PAINT: return new Paint();
	}
}
Editor* MakeEditors(const EditorSpec* editorSpec)
{
	switch (editorSpec->EditorType())
	{
	case PHOTOSHOP: return new Photoshop(static_cast<const PhotoshopSpec*>(editorSpec));
	}
}

class CorelDraw : public Base
{
	string LayerName;
	string FontName;
public:
	void add()
	{
		ofstream fout("CDraw.txt", ios::app);
		cout << "Введите название нового слоя: ";
		cin >> this->LayerName;
		cout << "Введите название шрифта: ";
		cin >> this->FontName;
		fout << this->LayerName << '\t' << this->FontName << endl;
	}
	void print()
	{
		ifstream fin("CDraw.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		cout << "\n\n";
		cout << "|" << setw(2) << "id" << setw(12) << "Layer" << setw(18) << "Font" << " |" << endl;
		cout << "|                                 |" << endl;
		int i = 1;
		while (fin.peek() != EOF)
		{
			fin >> this->LayerName >> this->FontName;
			if (fin.eof())
				break;
			cout << "|" << setw(2) << i << setw(12) << this->LayerName << setw(18) << this->FontName << " |" << endl;
			i++;
		}
		fin.close();
	}
	void in_file()
	{
		ifstream fin("temp.txt");
		ofstream fout("CDraw.txt", ios::app);
		CorelDraw ps;
		cout << "Что вы хотите изменить?\n1. Назавние слоя\n2. Шрифт" << endl;
		int ch = intInput(1, 2);
		if (ch == 1)
		{
			fin >> ps.LayerName >> ps.FontName;
			cout << "Введите новое название слоя: ";
			cin >> ps.LayerName;
			fout << ps.LayerName << '\t' << ps.FontName << endl;
		}
		else
		{
			fin >> ps.LayerName >> ps.FontName;
			cout << "Введите новый шрифт: ";
			cin >> ps.FontName;
			fout << ps.LayerName << '\t' << ps.FontName << endl;
		}
		fin.close();
		fout.close();
	}
	void edit()
	{
		ifstream fin("CDraw.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}
		CorelDraw ps;
		vector<CorelDraw> v;
		while (!fin.eof())
		{
			fin >> ps.LayerName >> ps.FontName;
			if (fin.eof())
				break;
			v.push_back(ps);
		}
		fin.close();
		cout << "Ввыберите какой слой вы хотите изменить: ";
		int ch = intInput(1, v.size());
		ch--;
		ofstream fout1("temp.txt");
		fout1 << v.at(ch).LayerName << '\t' << v.at(ch).FontName << endl;
		v.erase(v.begin() + ch);
		fout1.close();
		ofstream fout("CDraw.txt");
		for (size_t i = 0; i < v.size(); i++)
			fout << v.at(i).LayerName << '\t' << v.at(i).FontName << endl;
		fout.close();
		ps.in_file();
		cout << "Изменение прошло успешно!" << endl;
	}
	void del()
	{
		ifstream fin("CDraw.txt");
		if (!fin.is_open())
		{
			cout << "Файл не был создан!" << endl;
			return;
		}

		vector<string> v;
		string s;
		while (getline(fin, s))
			v.push_back(s);
		fin.close();
		cout << "Какой слой вы хотите удалить? ";
		int ch = intInput(1, v.size());
		ch--;
		v.erase(v.begin() + ch);
		ofstream fout("CDraw.txt");
		copy(v.begin(), v.end(),
			ostream_iterator<string>(fout, "\n"));
		fout.close();
		cout << "Удаление прошло успешно!" << endl;

	}
	CorelDraw* clone() const { return new CorelDraw(*this); }
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Editors EdType;
	int ch, i, j;
	while (true)
	{
		system("cls");
		cout << "Выберите какой тип паттерна Вы будете использовать\n\n1. 'Фабрика'\n2. 'Фабричный метод с аргументами'\n3. 'Фабричный конструктор'\n4. 'Полиморфная фабрика'\n5. 'Полиморфное копирование'\n\n--------------------\n0. Выход" << endl;
		ch = intInput(0, 5);
		switch (ch)
		{
		default:
			return 0;
		case 1:
		{
			int ch1, ch2;
			i = 1;
			while (i == 1)
			{
				system("cls");
				cout << "Какую программу Вы будете использовать?\n\n1. Photoshop\n2. Paint\n\n-----------------------\n0. Назад" << endl;
				ch1 = intInput(0, 2);
				if (ch1 == 1)
					EdType = PHOTOSHOP;
				else
					EdType = PAINT;
				Editor* Ed = MakeEdit(EdType);
				switch (ch1)
				{
				case 1:
					j = 1;
					while (j == 1)
					{
						system("cls");
						cout << "Выберите действие\n\n1. Добавить слой/шрифт\n2. Просмотреть данные\n3. Редактировать данные\n4. Удалить данные\n\n-------------------------\n0. Назад" << endl;
						ch2 = intInput(0, 4);
						switch (ch2)
						{
						case 1:
							system("cls");
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						case 3:
							system("cls");
							Ed->print();
							Ed->edit();
							system("pause");
							break;
						case 4:
							system("cls");
							Ed->print();
							Ed->del();
							system("pause");
							break;
						default:
							j = 0;
							break;
						}
					}
				case 2:
					j = 1;
					while (j == 1)
					{
						system("cls");
						cout << "Выберите действие\n\n1. Добавить слой/шрифт\n2. Просмотреть данные\n3. Редактировать данные\n4. Удалить данные\n\n-------------------------\n0. Назад" << endl;
						ch2 = intInput(0, 4);
						switch (ch2)
						{
						case 1:
							system("cls");
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						case 3:
							system("cls");
							Ed->print();
							Ed->edit();
							system("pause");
							break;
						case 4:
							system("cls");
							Ed->print();
							Ed->del();
							system("pause");
							break;
						default:
							j = 0;
							break;
						}
					}
				default:
					i = 0;
					break;
				}

			}
			break;
		}
		case 2:
		{
			j = 1;
			int ch1;
			PhotoshopSpec* EdiType = new PhotoshopSpec;
			Editor* Ed = MakeEditors(EdiType);
			while (j == 1)
			{
				system("cls");
				cout << "Выберите действие\n\n1. Добавить слой/шрифт\n2. Просмотреть данные\n3. Редактировать данные\n4. Удалить данные\n\n-------------------------\n0. Назад" << endl;
				ch1 = intInput(0, 4);
				switch (ch1)
				{
				case 1:
					system("cls");
					Ed->add();
					system("pause");
					break;
				case 2:
					system("cls");
					Ed->print();
					system("pause");
					break;
				case 3:
					system("cls");
					Ed->print();
					Ed->edit();
					system("pause");
					break;
				case 4:
					system("cls");
					Ed->print();
					Ed->del();
					system("pause");
					break;
				default:
					j = 0;
					break;
				}
			}
			break;
		}
		case 3:
		{
			int ch1, ch2;
			i = 1;
			while (i == 1)
			{
				system("cls");
				cout << "Какую программу Вы будете использовать?\n\n1. Photoshop\n2. Paint\n\n-----------------------\n0. Назад" << endl;
				ch1 = intInput(0, 2);
				Editor* Ed = Photoshop::make();
				if (ch1 == 1)
					Editor* Ed = Photoshop::make();
				else
					Editor* Ed = Paint::make();
				switch (ch1)
				{
				case 1:
					j = 1;
					while (j == 1)
					{
						system("cls");
						cout << "Выберите действие\n\n1. Добавить слой/шрифт\n2. Просмотреть данные\n3. Редактировать данные\n4. Удалить данные\n\n-------------------------\n0. Назад" << endl;
						ch2 = intInput(0, 4);
						switch (ch2)
						{
						case 1:
							system("cls");
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						case 3:
							system("cls");
							Ed->print();
							Ed->edit();
							system("pause");
							break;
						case 4:
							system("cls");
							Ed->print();
							Ed->del();
							system("pause");
							break;
						default:
							j = 0;
							break;
						}
					}
				case 2:
					j = 1;
					while (j == 1)
					{
						system("cls");
						cout << "Выберите действие\n\n1. Добавить слой/шрифт\n2. Просмотреть данные\n3. Редактировать данные\n4. Удалить данные\n\n-------------------------\n0. Назад" << endl;
						ch2 = intInput(0, 4);
						switch (ch2)
						{
						case 1:
							system("cls");
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						case 3:
							system("cls");
							Ed->print();
							Ed->edit();
							system("pause");
							break;
						case 4:
							system("cls");
							Ed->print();
							Ed->del();
							system("pause");
							break;
						default:
							j = 0;
							break;
						}
					}
				default:
					i = 0;
					break;
				}

			}
			break;
		}
		case 4:
		{
			int ch1, ch2;
			i = 1;

			while (i == 1)
			{
				system("cls");
				cout << "Какую программу Вы будете использовать?\n\n1. Photoshop\n2. Paint\n\n-----------------------\n0. Назад" << endl;
				ch1 = intInput(0, 2);
				j = 1;
				if (ch1 == 1)
				{
					Photoshop ad;
					PSD* Ed = ad.makeFormat();
					while (j == 1)
					{
						system("cls");
						cout << "1. Добавить данные про формат файла\n2. Показать данные\n\n\-----------------------\n0. Назад" << endl;
						ch2 = intInput(0, 2);
						switch (ch2)
						{
						default:
							j = 0;
							break;
						case 1:
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						}
					}
				}
				else if (ch1 == 2)
				{
					Paint pa;
					JPEG* Ed = pa.makeFormat();
					while (j == 1)
					{
						system("cls");
						cout << "1. Добавить данные про формат файла\n2. Показать данные\n\n\-----------------------\n0. Назад" << endl;
						ch2 = intInput(0, 2);
						switch (ch2)
						{
						default:
							j = 0;
							break;
						case 1:
							Ed->add();
							system("pause");
							break;
						case 2:
							system("cls");
							Ed->print();
							system("pause");
							break;
						}
					}
				}
				else
					break;
			}
			break;
		}
		case 5:
		{
			int ch2;
			system("cls");
			cout << "Используется графический редактор: CorelDraw\n\n";
			Base* b = new CorelDraw;
			cout << "Создался основной объект!" << endl;
			Base* b1 = b->clone();
			cout << "\nСоздался клон основного объекта!" << endl;
			system("pause");
			j = 1;
			while (j == 1)
			{
				system("cls");
				cout << "1. Добавить данные\n2. Показать данные\n3. Редактировать данные\n4. Удалить данные\n\n\-----------------------\n0. Назад" << endl;
				ch2 = intInput(0, 4);
				switch (ch2)
				{
				case 1:
					system("cls");
					b1->add();
					break;
				case 2:
					system("cls");
					b1->print();
					system("pause");
					break;
				case 3:
					system("cls");
					b1->edit();
					system("pause");
					break;
				case 4:
					system("cls");
					b1->del();
					system("pause");
					break;
				default:
					j = 0;
					break;
				}
			}
			break;
		}
		}
	}
}
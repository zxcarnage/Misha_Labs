#include "Panel.h"

void TechnicalExcersize()
{
	ofstream fout;
	ifstream fin;
	string line;
	fin.open("helloWorld.txt");
	fout.open("helloWorld.txt");
	fout << "Hello World!" << endl;
	cout << "Изначальное состояние файла:" << endl;
	fin >> line;
	cout << line << endl;
	fin.seekg(5);
	cout << "Текущий указатель чтения: " << fin.tellg() << endl;
	fin >> line;
	cout << "Прочтено: " << line << endl;
	fout.seekp(1);
	cout << "Текущий указатель записи: " << fout.tellp() << endl;
	cout << "Запишем Goodbye" << endl;
	fout << "Goodbye" << endl;
	fin.seekg(0);
	fin >> line;
	cout << "Прочтено: " << line << endl;
	fin.close();
	fout.close();
}

Hospital ShowException()
{
	try
	{
		return new Hospital(true);
	}
	catch (...)
	{
		cout << "Исключение в конструкторе" << endl;
	}
}

void CallFileFunction(int answer,Hospital* hospital)
{
	switch (answer)
	{
	case 1:
		hospital->Write();
		system("cls");
		break;
	case 2:
		Hospital::EditFile();
		system("cls");
		break;
	case 3:
		Hospital::DeleteFile();
		system("cls");
		break;
	case 4:
		Hospital::ShowFile();
		break;
	case 5:
		TechnicalExcersize();
		break;
	case 6:
		Hospital::Search();
		break;
	case 7:
		Hospital::SortFile();
		break;
	}
}

void ShowFilePanel(Hospital* hospital)
{
	float answer;
	cout << "================= Выберите =================" << endl;
	cout << "1.Записать больницу в файл" << endl;
	cout << "2.Редактировать больницу из файла" << endl;
	cout << "3.Удалить больницу из файла" << endl;
	cout << "4.Показать данные из файла" << endl;
	cout << "5.Продемонстрировать seekp,seekg,tellg" << endl;
	cout << "6.Поиск" << endl;
	cout << "7.Сортировать данные в файле" << endl;
	cout << "8.Вернуться" << endl;
	cout << "============================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 8);
	system("cls");
	CallFileFunction((int)answer, hospital);
}

void CallCurrentFunction(int answer, Hospital* hospital)
{
	switch (answer)
	{
	case 1:
		hospital->Create();
		system("cls");
		break;
	case 2:
		hospital->Show();
		break;
	case 3:
		ShowException();
		break;
	case 4:
		ShowFilePanel(hospital);
		break;
	case 5:
		exit(0);
	}
}

void ShowPanel(Hospital* hospital)
{	
	float answer;
	cout << "================= Выберите =================" << endl;
	cout << "1.Создать больницу" << endl;
	cout << "2.Показать созданную больницу" << endl;
	cout << "3.Показать исключение в конструкторе" << endl;
	cout << "4.Работа с файлами" << endl;
	cout << "5.Выход" << endl;
	cout << "============================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 5);
	system("cls");
	CallCurrentFunction((int)answer, hospital);
}
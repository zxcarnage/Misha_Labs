#include "Panel.h"

void TechnicalExcersize()
{
	ofstream fout;
	ifstream fin;
	string line;
	fin.open("helloWorld.txt");
	fout.open("helloWorld.txt");
	fout << "Hello World!" << endl;
	cout << "����������� ��������� �����:" << endl;
	fin >> line;
	cout << line << endl;
	fin.seekg(5);
	cout << "������� ��������� ������: " << fin.tellg() << endl;
	fin >> line;
	cout << "��������: " << line << endl;
	fout.seekp(1);
	cout << "������� ��������� ������: " << fout.tellp() << endl;
	cout << "������� Goodbye" << endl;
	fout << "Goodbye" << endl;
	fin.seekg(0);
	fin >> line;
	cout << "��������: " << line << endl;
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
		cout << "���������� � ������������" << endl;
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
	cout << "================= �������� =================" << endl;
	cout << "1.�������� �������� � ����" << endl;
	cout << "2.������������� �������� �� �����" << endl;
	cout << "3.������� �������� �� �����" << endl;
	cout << "4.�������� ������ �� �����" << endl;
	cout << "5.������������������ seekp,seekg,tellg" << endl;
	cout << "6.�����" << endl;
	cout << "7.����������� ������ � �����" << endl;
	cout << "8.���������" << endl;
	cout << "============================================" << endl;
	Input(&answer, " �����", InputType::Answer, 8);
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
	cout << "================= �������� =================" << endl;
	cout << "1.������� ��������" << endl;
	cout << "2.�������� ��������� ��������" << endl;
	cout << "3.�������� ���������� � ������������" << endl;
	cout << "4.������ � �������" << endl;
	cout << "5.�����" << endl;
	cout << "============================================" << endl;
	Input(&answer, " �����", InputType::Answer, 5);
	system("cls");
	CallCurrentFunction((int)answer, hospital);
}
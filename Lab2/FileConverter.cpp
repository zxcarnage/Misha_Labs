#include "FileConverter.h"
Json::Json()
{
	ExtensionName = "Json";
}

string Json::GetName()
{
	return ExtensionName;
}

FileConverter::FileConverter()
{
	_success = false;
	Input(&MaxFileSize, " ������������ ������ ����� ��� ����������", InputType::Number);
}

FileConverter::FileConverter(File file) : FileConverter()
{
	_file = file;
}

void FileConverter::Show()
{
	_file.Show();
	cout << "������������ ������ �����: " << MaxFileSize << endl;
	cout << "������ �����: " << _file.GetSize() << endl;
	cout << "����������� ";
	if (_success = true)
		cout << "������" << endl;
	else
		cout << "��������" << endl;
}

void File::Create()
{
	_extension = Json();
	StringInput(&_fileName, " ��� �����");
	Input(&_size, " ������ �����", InputType::Number);
}

void File::Show()
{
	cout << "����������: " << _extension.GetName() << endl;
	cout << "��� �����: " << _fileName << endl;
}

float File::GetSize()
{
	return _size;
}

void File::WriteInfo(string stateName)
{
	ofstream fout("dataBase.txt", ofstream::app);
	if (stateName == "��� ����������� ���������")
	{
		fout << "��� ����������� ���������\n" << endl;
		return;
	}
	fout << stateName << endl;
	fout << _extension.GetName() << endl;
	fout << _fileName << endl;
	fout << _size << endl;
	fout << endl;
}

void FileConverter::Convert()
{
	if (MaxFileSize >= _file.GetSize())
		_success = true;
	Show();
}
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
	Input(&MaxFileSize, " максимальный размер файла для конвертера", InputType::Number);
}

FileConverter::FileConverter(File file) : FileConverter()
{
	_file = file;
}

void FileConverter::Show()
{
	_file.Show();
	cout << "Максимальный размер файла: " << MaxFileSize << endl;
	cout << "Размер файла: " << _file.GetSize() << endl;
	cout << "Конвертация ";
	if (_success = true)
		cout << "удачна" << endl;
	else
		cout << "неудачна" << endl;
}

void File::Create()
{
	_extension = Json();
	StringInput(&_fileName, " имя файла");
	Input(&_size, " размер файла", InputType::Number);
}

void File::Show()
{
	cout << "Расширение: " << _extension.GetName() << endl;
	cout << "Имя файла: " << _fileName << endl;
}

float File::GetSize()
{
	return _size;
}

void File::WriteInfo(string stateName)
{
	ofstream fout("dataBase.txt", ofstream::app);
	if (stateName == "Нет предыдущего состояния")
	{
		fout << "Нет предыдущего состояния\n" << endl;
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
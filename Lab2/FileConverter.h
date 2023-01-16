#pragma once
#include "Input.h"
#include <fstream>
using std::ofstream;

class Extension
{
protected:
	string ExtensionName;
};

class Json : public Extension
{
public:
	Json();
	string GetName();
};

class Converter
{
protected:
	float MaxFileSize = 0;
};

class File
{
	Json _extension;
	string _fileName;
	float _size;
public:
	float GetSize();
	void Create();
	void Show();
	void WriteInfo(string stateName);
};


class FileConverter : Converter
{
	File _file;
	bool _success;
	void Show();
public:
	FileConverter();
	FileConverter(File file);
	void Convert();
};
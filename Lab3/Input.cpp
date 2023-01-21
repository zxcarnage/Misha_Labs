#include "Input.h"
#include <conio.h>

void AgeInput(float tempData, string dataName)
{
	if (tempData < 0 || tempData > 120)
		throw InputException("Неверное количество лет", tempData);
}

void NumberInput(float tempData, string dataName)
{
	if (tempData < 0 || tempData > INT_MAX)
		throw InputException("Неверные данные", tempData);
}

void IntNumberInput(float tempData, string dataName)
{
	if (tempData < 0 || tempData > INT_MAX || (int)tempData != tempData)
		throw InputException("Неверные данные, попробуйте целое число", tempData);
}

void IndexNumberInput(float tempData, int ceilNum = 0)
{
	if ((int)tempData != tempData || tempData < 0 || (ceilNum > 0 && tempData > ceilNum))
		throw new exception("Неверный индекс/айди, попробуйте ввести в пределах предложенного");
}

void AnswerInput(float tempData, string dataName, int ceilNum = 0)
{
	if ((int)tempData != tempData || (int)tempData > ceilNum)
		throw InputException("Неверный тип ответа, попробуйте целое число", tempData);
}

void DateCheck(char date[])
{
	int day;
	int month;
	int year;
	try
	{
		day = (date[0] - 48) * 10 + (date[1] - 48);
		month = (date[3] - 48) * 10 + (date[4] - 48);
		year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + (date[9] - 48);
	}
	catch (...)
	{
		throw exception("Wrong date view, try DD.MM.YYYY");
	}
	if (date[2] != '.' || date[5] != '.')
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (day > 31 || day < 1)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (month < 1 || month > 12)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (year < 1980 || year > 2023)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (date[0] == '\r')
		throw exception("Wrong date view, try DD.MM.YYYY");
}

void DateCheck(string date)
{
	int day;
	int month;
	int year;
	try
	{
		day = (date[0] - 48) * 10 + (date[1] - 48);
		month = (date[3] - 48) * 10 + (date[4] - 48);
		year = (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + (date[9] - 48);
	}
	catch (...)
	{
		throw exception("Wrong date view, try DD.MM.YYYY");
	}
	if (date[2] != '.' || date[5] != '.')
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (day > 31 || day < 1)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (month < 1 || month > 12)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (year < 1980 || year > 2023)
		throw exception("Wrong date view, try DD.MM.YYYY");
	if (date[0] == '\r')
		throw exception("Wrong date view, try DD.MM.YYYY");
}

void DateInput(char date[], string dataName)
{
	bool isRunning = true;
	while (isRunning)
	{
		try
		{
			char tempData[20];
			cout << "Введите " << dataName << endl;
			memset(tempData, 0, sizeof tempData);
			memset(date, 0, sizeof date);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.getline(tempData, 20);
			DateCheck(tempData);
			strcpy(date, tempData);
			isRunning = false;

		}
		catch (InputException& iEx)
		{
			cout << iEx.what() << endl;
			cout << "Ошибочные данные: " << iEx.GetErrorData() << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}

void DateInput(string& date, string dataName)
{
	bool isRunning = true;
	while (isRunning)
	{
		try
		{
			string tempData;
			cout << "Введите " << dataName << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			DateCheck(tempData);
			date = tempData;
			isRunning = false;

		}
		catch (InputException& iEx)
		{
			cout << iEx.what() << endl;
			cout << "Ошибочные данные: " << iEx.GetErrorData() << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}

char* PasswordInput()
{
	char symbol;
	int i = 0;
	char password[50] = { '\0' };
	while (true && i < 50)
	{
		symbol = _getch();
		switch (symbol)
		{
		default:
			cout << '*';
			password[i] = (char)symbol;
			i++;
			break;
		case 13:
			cout << endl;
			return password;
			break;
		case 27:
			exit(0);
			break;
		case 8:
			cout << '\b' << " " << '\b';
			i--;
			break;
		}
	}
	cout << endl;
}


void CharInput(char data[], string dataName)
{
	char tempData[20];
	cout << "Введите " << dataName << endl;
	memset(tempData, 0, sizeof tempData);
	memset(data, 0, sizeof data);
	cin.get();
	cin.getline(tempData, 20);
	strcpy(data, tempData);
}

void SingleCharInput(char* data, string dataName)
{
	char tempData;
	cout << "Введите " << dataName << endl;
	cin.get();
	cin >> tempData;
	*data = tempData;
}

void StringInput(string* data, string dataName)
{
	string tempData;
	cout << "Введите " << dataName << endl;
	cin >> tempData;
	*data = tempData;
}

float InputException::GetErrorData()
{
	return _errorData;
}

void InputMenu(float* data, string dataName, InputType inputType, int ceilNum)
{
	float tempData;
	cout << "Введите " << dataName << endl;
	cin >> tempData;
	if (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw exception("Неверный тип введенных данных!");
	}
	switch (inputType)
	{
	case Number:
		NumberInput(tempData, dataName);
		*data = tempData;
		break;
	case IntNumber:
		IntNumberInput(tempData, dataName);
		*data = tempData;
		break;
	case IndexNumber:
		IndexNumberInput(tempData, ceilNum);
		*data = tempData;
		break;
	case Age:
		AgeInput(tempData, dataName);
		*data = tempData;
		break;
	case Answer:
		AnswerInput(tempData, dataName, ceilNum);
		*data = tempData;
		break;
	default:
		throw exception("Некорректный тип введенных данных!!!");
		break;
	}
}

void Input(float* data, string dataName, InputType inputType, int ceilNum)
{

	bool isRunning = true;
	while (isRunning)
	{
		try
		{
			InputMenu(data, dataName, inputType, ceilNum);
			isRunning = false;

		}
		catch (InputException& iEx)
		{
			cout << iEx.what() << endl;
			cout << "Ошибка в данных: " << iEx.GetErrorData() << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}
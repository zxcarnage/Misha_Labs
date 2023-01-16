#include "Panel.h"

void CreateFile(Transaction<File>* transaction)
{
	File file;
	file.Create();
	transaction->Begin(file);
}

void ConvertFile(Transaction<File>* transaction)
{
	FileConverter fileConverter(*transaction->GetObj());
	fileConverter.Convert();
}

void CallCurrentFunction(int answer, Transaction<File>* transaction)
{
	if (transaction->Empty() && answer != 1)
	{
		cout << "Вы не можете производить эти операции, не создав файл" << endl;
		return;
	}
	switch (answer)
	{
	case 1:
		CreateFile(transaction);
		break;
	case 2:
		transaction->Show();
		break;
	case 3:
		transaction->Commit();
		break;
	case 4:
		transaction->Undo();
		break;
	case 5:
		transaction->Write();
		break;
	case 6:
		ConvertFile(transaction);
		break;
	case 7:
		exit(0);
		break;
	}
}

void ShowPanel(Transaction<File>* transaction)
{
	float answer;
	cout << "============== Выберите вариант ===============" << endl;
	cout << "1.Создать файл" << endl;
	cout << "2.Показать файл" << endl;
	cout << "3.Подтвердить изменения" << endl;
	cout << "4.Откатить изменения" << endl;
	cout << "5.Записать в файл" << endl;
	cout << "6.Конвертировать файл" << endl;
	cout << "7.Выход" << endl;
	cout << "===============================================" << endl;
	Input(&answer, " ответ", InputType::Answer, 7);
	CallCurrentFunction((int)answer, transaction);
}
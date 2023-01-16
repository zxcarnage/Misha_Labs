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
		cout << "�� �� ������ ����������� ��� ��������, �� ������ ����" << endl;
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
	cout << "============== �������� ������� ===============" << endl;
	cout << "1.������� ����" << endl;
	cout << "2.�������� ����" << endl;
	cout << "3.����������� ���������" << endl;
	cout << "4.�������� ���������" << endl;
	cout << "5.�������� � ����" << endl;
	cout << "6.�������������� ����" << endl;
	cout << "7.�����" << endl;
	cout << "===============================================" << endl;
	Input(&answer, " �����", InputType::Answer, 7);
	CallCurrentFunction((int)answer, transaction);
}
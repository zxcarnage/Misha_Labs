#include "Delivery.h"

string Customer::GetName()
{
	return _name;
}

float Customer::GetAge()
{
	return _age;
}

string Customer::GetObject()
{
	switch (_deliveryObject)
	{
	case DeliveryObject::Box:
		return "�������";
	case DeliveryObject::Food:
		return "���";
	}
}

void Customer::Create()
{
	float answer;
	StringInput(&_name, " ���� ���");
	Input(&_age, " ��� �������", Age);
	cout << "��� ����� ����������?" << endl;
	cout << "1.������� � ���-����" << endl;
	cout << "2.���" << endl;
	Input(&answer, " �����", Answer, 2);
	_deliveryObject = DeliveryObject((int)answer - 1);
}

void Delivery::Order()
{
	Customer customer;
	customer.Create();
	_deliveryQueue.push(customer);
}

void Delivery::Show()
{
	if (_deliveryQueue.empty())
		return;
	TablePrinter tp(&cout);
	Customer customer;
	queue<Customer> deliveryCopy;
	deliveryCopy = _deliveryQueue;
	tp.AddColumn("ID", 4);
	tp.AddColumn("���", 15);
	tp.AddColumn("�������", 10);
	tp.AddColumn("������� ��������", 20);
	tp.PrintHeader();
	for (int i = 0; i < _deliveryQueue.size(); i++)
	{
		customer = deliveryCopy.front();
		tp << i + 1 << customer.GetName() << customer.GetAge() << customer.GetObject();
		deliveryCopy.pop();
	}
	tp.PrintFooter();
}

void Delivery::Delete()
{
	float answer;
	int index = 1;
	Customer customer;
	queue<Customer> deliveryCopy;
	Show();
	Input(&answer, "  ����� ������� ������� ������ �������", IndexNumber, _deliveryQueue.size());
	while (!_deliveryQueue.empty())
	{
		customer = _deliveryQueue.front();
		if (index != answer)
			deliveryCopy.push(customer);
		index++;
		_deliveryQueue.pop();
	}
	_deliveryQueue = deliveryCopy;
}

void Delivery::Edit()
{
	float answer;
	int index = 1;
	Customer customer;
	queue<Customer> deliveryCopy;
	Show();
	Input(&answer, "  ����� ������� ������� ������ �������������", IndexNumber, _deliveryQueue.size());
	while (!_deliveryQueue.empty())
	{
		customer = _deliveryQueue.front();
		if (index == answer)
			customer.Create();
		deliveryCopy.push(customer);
		index++;
		_deliveryQueue.pop();
	}
	_deliveryQueue = deliveryCopy;
}
#pragma once
#include "Input.h"
#include "TablePrinter.h"
#include <queue>
using std::queue;

enum class DeliveryObject
{
	Box,
	Food
};

class Customer
{
	string _name;
	DeliveryObject _deliveryObject;
	float _age;
public:
	void Create();
	string GetName();
	float GetAge();
	string GetObject();
};

class Delivery
{
	queue<Customer> _deliveryQueue;
public:
	void Order();
	void Delete();
	void Show();
	void Edit();
};
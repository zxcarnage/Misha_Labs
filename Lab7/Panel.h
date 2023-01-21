#pragma once
#include "Input.h"
#include "Delivery.h"
class Panel
{
	Delivery _delivery;
	void CallCurrent(int answer);
public:
	void ShowPanel();
};


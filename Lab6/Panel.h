#pragma once
#include "Input.h"
#include "Ticket.h"
#include <map>
#include <fstream>
#include <vector>
#include <Algorithm>
using std::map;
using std::vector;
using std::ofstream;
using std::ifstream;

class Panel
{
	vector<Airticket> _airtickets;
	void SortName();
	void FindTicket();
	void SortAge();
	void SortYear();
	vector<Airticket>  FindName();
	vector<Airticket> FindAge();
	vector<Airticket> FindYear();
	void CallCurrent(int answer);
	void EditTicket();
	void ShowAirtickets(vector<Airticket> airticket);
	void CallFind(int answer);
	void WriteAirtickets();
	void OrderTicket();
	void DeleteTicket();
	void SortTicket();
	void CallSort(int answer);
public:
	void ShowPanel();
};

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Date.h"


class Ticket
{
private:
	std::string destination;
	std::string flight_number;
	std::string plane_model;
	std::string FIO;
	Date date;
public:

	Ticket() {};
	Ticket(const std::string& dest, const std::string& fl_num, const std::string& pl_mod, const std::string& FIO, const Date& date) :
		destination(dest), flight_number(fl_num), plane_model(pl_mod), FIO(FIO), date(date) {};
	std::string get_dest()
	{
		return destination;
	}
	std::string get_flight_num()
	{
		return flight_number;
	}
	std::string get_plane_model()
	{
		return plane_model;
	}
	std::string get_FIO()
	{
		return FIO;
	}
	Date get_date()
	{
		return date;
	}
	friend std::istream& operator>>(std::istream& in, Ticket& t);
	friend std::ostream& operator<<(std::ostream& out,const Ticket&t);
	bool operator<(const Ticket& ticket);
	bool operator>=(const Ticket& ticket);
	bool operator<=(const Ticket& ticket);
	bool operator==(const Ticket& ticket);
	bool operator >(const Ticket& ticket);
	bool operator !=(const Ticket& ticket);
};

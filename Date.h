#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date() {};
	Date(int day, int month, int year)
	{
		if (day > 30 || day < 1)
			this->day = 1;
		else
			this->day = day;
		if (month > 12 || month < 1)
			this->month = 1;
		else
			this->month = month;
		if (year < 0)
			this->year = 2024;
		else
			this->year = year;
	}
	int get_day() const
	{
		return day;
	}
	int get_month() const
	{
		return month;
	}
	int get_year() const
	{
		return year;
	}
	void set_day(int day)
	{
		this->day = day;
	}
	void set_month(int month)
	{
		this->month = month;
	}
	void set_year(int year)
	{
		this->year = year;
	}

	bool operator<(const Date& date);
	bool operator<=(const Date& date);
	bool operator>(const Date& date);
	bool operator>=(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
	friend std::ostream& operator <<(std::ostream& out, const Date& date);
};
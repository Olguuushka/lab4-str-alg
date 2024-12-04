#include "Date.h"

bool Date::operator<(const Date& date)
{
	bool res = true;
	if (this->year > date.get_year())
		res = false;
	else
	{
		if (this->year == date.get_year())
		{
			if (this->month > date.get_month())
				res = false;
			else
				if (this->month == date.get_month())
					res = this->day < date.get_day();
		}
	}
	return res;
}

bool Date::operator<=(const Date& date)
{
	return *this < date || *this == date;
}

bool Date::operator>(const Date& date)
{
	bool res = true;
	if (this->year < date.get_year())
		res = false;
	else
	{
		if (this->year == date.get_year())
		{

			if (this->month < date.get_month())
				res = false;
			else
				if(this->month == date.get_month())
				res = this->day > date.get_day();
		}
	}
	return res;
}

bool Date::operator>=(const Date& date)
{
	return *this > date || *this == date;
}

bool Date::operator==(const Date& date)
{
	return (this->year == date.get_year() && this->month == date.get_month() && this->day == date.get_day());
}

bool Date::operator!=(const Date& date)
{
	return !(*this == date);
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << "День:\t" << date.get_day() << '\n';
	out << "Месяц:\t" << date.get_month() << '\n';
	out << "Год:\t" << date.get_year() << '\n';
	return out;
}

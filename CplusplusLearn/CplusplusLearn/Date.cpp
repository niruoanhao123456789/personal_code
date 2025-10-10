#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
	}
	return *this;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while(_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}

//Date Date::operator+(int day)
//{
//	Date tmp(*this);
//
//	tmp._day += day;
//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//	{
//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//		if (tmp._month > 12)
//		{
//			tmp._month = 1;
//			tmp._year++;
//		}
//	}
//
//	return tmp;
//}

Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;

	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month < 1)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}



// 2025 10  8
// 2025 11 10
//--------------
//   -1  10 29
//
//int Date::operator-(const Date& d)
//{
//	Date tmp(*this);
//	int day = tmp._day - d._day;
//	if (day < 1)
//	{
//		tmp._month--;
//		if (tmp._month < 1)
//		{
//
//			tmp._year--;
//		}
//	}
//}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return tmp;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
		return true;
	if (_year > d._year)
		return false;
	if (_month < d._month)
		return true;
	if (_month > d._month)
		return false;
	return _day < d._day;
}

bool Date::operator<=(const Date& d)
{
	if (_year < d._year)
		return true;
	if (_year > d._year)
		return false;
	if (_month < d._month)
		return true;
	if (_month > d._month)
		return false;
	return _day <= d._day;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year < d._year)
		return false;
	if (_month > d._month)
		return true;
	if (_month < d._month)
		return false;
	return _day > d._day;
}

bool Date::operator>=(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year < d._year)
		return false;
	if (_month > d._month)
		return true;
	if (_month < d._month)
		return false;
	return _day >= d._day;
}

// 4 6

// 2025  11 10
// 2024  10 11
//         30 
int Date::operator-(const Date& d)
{
	Date Dlarge(*this);
	Date Dsmall = d;
	int flag = 0;
	if (Dsmall > Dlarge)
	{
		Date tmp = Dsmall;
		Dsmall = Dlarge;
		Dlarge = tmp;
		flag = 1;
	}
	int day = Dlarge._day - Dsmall._day;
	while (day < 0)
	{
		Dlarge._month--;
		if (Dlarge._month < 1)
		{
			Dlarge._month = 12;
			Dlarge._year--;
		}
		day += GetMonthDay(Dlarge._year, Dlarge._month);
	}
	int i = 0;
	for (i = 1; i < Dlarge._month; i++)
	{
		day += GetMonthDay(Dlarge._year, i);
	}
	Dlarge._year--;
	for (i = Dsmall._month; i <= 12; i++)
	{
		day += GetMonthDay(Dsmall._year, i);
	}
	Dsmall._year++;
	for (i = Dsmall._year; i <= Dlarge._year; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)
			day += 366;
		else
			day += 365;
	}
	if (flag)
		return (0 - day);
	else
		return day;
}
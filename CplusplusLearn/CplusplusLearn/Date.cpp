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
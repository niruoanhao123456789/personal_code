#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
	//加上关键字friend就是友元函数声明
	//在这个类里声明的友元函数可以调用类里的私有变量
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);

		int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}

	bool CheckDate();

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date& operator=(const Date& d);

	// d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day);
	// d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day);

	// d1 - d2
	int operator-(const Date& d);

	// ++d1 -> d1.operator++()
	Date& operator++();

	// d1++ -> d1.operator++(0)
	// 为了区分，构成重载，给后置++，强行增加了一个int形参
	// 这里不需要写形参名，因为接收值是多少不重要，也不需要用
	// 这个参数仅仅是为了跟前置++构成重载区分
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	//void operator<<(ostream& out);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);

void testDate1();
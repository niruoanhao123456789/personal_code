#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//友元类中的成员函数都可以是另⼀个类的友元函数，都可以访问另⼀个类中的私有和保护成员
class C
{
	friend class D;
public:
	void fun1(const D& dd);
private:
	int _a1 = 1;
	int _b1 = 2;
};

class D
{
	friend class C;
public:
	void fun1(const C& cc);
	void fun2(const C& cc);
private:
	int _a2 = 3;
	int _b2 = 4;
};
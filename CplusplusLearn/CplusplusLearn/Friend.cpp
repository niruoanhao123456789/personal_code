#include"Friend.h"

void C::fun1(const D& dd)
{
	cout << dd._a2 << endl;
}

void D::fun1(const C& cc)
{
	cout << cc._a1 << endl;
	cout << _b2 << endl;
}

void D::fun2(const C& cc)
{
	cout << cc._a1 << endl;
	cout << _b2 << endl;
}
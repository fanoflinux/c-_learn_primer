#pragma once
#ifndef X2Y
#define X2Y
#include<iostream>
#include<string>

//����һ���������
class X;
class Y;

class X
{
public:
	Y y;
	Y* y_prt = &y;
};
class Y
{
public:
	X x1;
};

class book
{
	book() = default;
	book(std::string w, std::string n, std::string d, std::string p) :writer(w),name(n),data(d),price(p);
	explicit book(std::istream& in)
	{
		in >> writer >> name >> data >>price;
	}

	//��Ҫ�Ĳ���
	std::string writer;
	std::string name;
	std::string data;
	std::string price;
};
class A
{
	A(int);
};

struct B
{
	A a;
};
#endif // !X2Y
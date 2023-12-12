#pragma once

#ifndef  PERSON_CLASS
#define PERSON_CLASS
#include<iostream>
#include<string>

using namespace std;

class Person
{
	//声明友元相关的内容
	friend istream& read(istream& is, Person& person);
	friend ostream& print(ostream& os, Person& person);
public:
	//无事发生时调用的构造函数
	Person() = default;
	//已经有两个参数进行初始化
	Person(const string& per_name, string const& per_adress) :name(per_name), adress(pre_adress) {};
	//从全局函数read中进行初始化
	Person(iostream& is) { read(is, *this); };

	auto pre_name()const->string const&;
	//读取个人的地址
	auto pre_adress()const->string const& { return adress; };
private:
	string name;
	string adress;
};
//读取个人的姓名
auto Person::pre_name() const -> string const& { return name; };
//输入个人信息的函数
istream& read(istream& is, Person& person)
{
	return is >> person.name >> person.adress;
}
//打印个人信息的函数
ostream& print(ostream& os, Person& person)
{
	return os << person.name << " " << person.name;
}

#endif // ! PERSON_CLASS


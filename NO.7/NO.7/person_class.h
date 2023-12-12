#pragma once

#ifndef  PERSON_CLASS
#define PERSON_CLASS
#include<iostream>
#include<string>

using namespace std;

class Person
{
	//������Ԫ��ص�����
	friend istream& read(istream& is, Person& person);
	friend ostream& print(ostream& os, Person& person);
public:
	//���·���ʱ���õĹ��캯��
	Person() = default;
	//�Ѿ��������������г�ʼ��
	Person(const string& per_name, string const& per_adress) :name(per_name), adress(pre_adress) {};
	//��ȫ�ֺ���read�н��г�ʼ��
	Person(iostream& is) { read(is, *this); };

	auto pre_name()const->string const&;
	//��ȡ���˵ĵ�ַ
	auto pre_adress()const->string const& { return adress; };
private:
	string name;
	string adress;
};
//��ȡ���˵�����
auto Person::pre_name() const -> string const& { return name; };
//���������Ϣ�ĺ���
istream& read(istream& is, Person& person)
{
	return is >> person.name >> person.adress;
}
//��ӡ������Ϣ�ĺ���
ostream& print(ostream& os, Person& person)
{
	return os << person.name << " " << person.name;
}

#endif // ! PERSON_CLASS


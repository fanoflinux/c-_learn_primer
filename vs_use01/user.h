#pragma once
#ifndef USER
#define USER
#include<iostream>
#include<string>

class User
{
public:
	User() = default;
	User(const std::string use_name, const int use_age) :name(use_name), age(use_age)
	{
		std::cout << "��ɹ���" << std::endl;
		std::cout << name << ";" << age << std::endl;
	}
	//ί�й��캯��
	User(const std::string use_sex) :User("����", 20)
	{
		
		std::cout << "ί�й��캯��" << std::endl;
		std::cout << name << ";" << age <<";"<<use_sex << std::endl;
	}

	void func01(int& a, int& b);
	void func01(int a); 

private:
	std::string name="����";
	int age=18;
	std::string sex;
};

void User::func01(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void User::func01(int a)
{
	int c = a * a;
	std::cout << "a��ƽ��Ϊ��" << c << std::endl;
}

#endif // !USER

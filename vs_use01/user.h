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
		std::cout << "完成构造" << std::endl;
		std::cout << name << ";" << age << std::endl;
	}
	//委托构造函数
	User(const std::string use_sex) :User("张三", 20)
	{
		
		std::cout << "委托构造函数" << std::endl;
		std::cout << name << ";" << age <<";"<<use_sex << std::endl;
	}

	void func01(int& a, int& b);
	void func01(int a); 

private:
	std::string name="张三";
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
	std::cout << "a的平方为：" << c << std::endl;
}

#endif // !USER

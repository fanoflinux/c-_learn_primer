#include<iostream>
#include<vector>
#include<string>

using namespace std;

//define hasptr class
class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);

public:
	//默认构造函数
	HasPtr() = default;
	//定义构造函数
	HasPtr(const string &s)
		:has_name(new string(s)),has_num(1)
	{
		std::cout << "创建has_ptr:" << *(this->has_name) << "编号为:" << this->has_num << std::endl;
	}
	//定义拷贝构造函数
	HasPtr(const HasPtr& pri_has)
	{
		this->has_num = pri_has.has_num + 1;
		std::cout << "定义拷贝对象的编号" << this->has_num << std::endl;
		this->has_name = (new string(*(pri_has.has_name)));
		std::cout << "定义拷贝对象的名字" << *(this->has_name) << "其地址为" << this->has_name << std::endl;
	}
	//定义赋值拷贝函数
	HasPtr& operator=(HasPtr& pri_has)
	{
		swap(pri_has);
		return *this;
	}
	//定义类中的交换函数用于赋值拷贝函数
	
	void swap(HasPtr& pri_has)
	{
		std::cout << "交换前的名字:" << *(pri_has.has_name) << std::endl;
		std::cout << "交换前的名字内存:" << pri_has.has_name << std::endl;
		std::cout << "交换前的数值" << pri_has.has_num << std::endl;
		std::cout << "交换前的名字:" << *(this->has_name) << std::endl;
		std::cout << "交换前的名字内存:" << this->has_name << std::endl;
		std::cout << "交换前的数值" << this->has_num << std::endl;
		std::cout << std::endl;
		using std::swap;
		swap(this->has_name, pri_has.has_name);
		swap(this->has_num, pri_has.has_num);
		std::cout << "--调用类内的交换函数--" << std::endl;
		std::cout << "交换后的名字:" << *(pri_has.has_name) << std::endl;
		std::cout << "交换后的名字内存:" << pri_has.has_name << std::endl;
		std::cout << "交换后的数值" << pri_has.has_num << std::endl;
		std::cout << "交换后的名字:" << *(this->has_name) << std::endl;
		std::cout << "交换后的名字内存:" << this->has_name << std::endl;
		std::cout << "交换后的数值" << this->has_num << std::endl;
	}
	~HasPtr()
	{
		delete has_name;
	}

private:
	string *has_name;
	int has_num;
};

/*
void swap(HasPtr& lhas, HasPtr& rhas)
{
	using std::swap;
	std::cout << "交换前的名字:" << *(lhas.has_name) << std::endl;
	std::cout << "交换前的名字内存:" << lhas.has_name << std::endl;
	std::cout << "交换前的数值" << lhas.has_num << std::endl;
	std::cout << "交换前的名字:" << *(rhas.has_name) << std::endl;
	std::cout << "交换前的名字内存:" << rhas.has_name << std::endl;
	std::cout << "交换前的数值" << rhas.has_num << std::endl;
	std::cout << "调用自定义的友函数swap" << std::endl;
	swap(lhas.has_name, rhas.has_name);
	swap(lhas.has_num, rhas.has_num);
	std::cout << "交换后的名字:" << *(lhas.has_name) << std::endl;
	std::cout << "交换后的名字内存:" << lhas.has_name << std::endl;
	std::cout << "交换后的数值" << lhas.has_num << std::endl;
	std::cout << "交换后的名字:" << *(rhas.has_name) << std::endl;
	std::cout << "交换后的名字内存:" << rhas.has_name << std::endl;
	std::cout << "交换后的数值" << rhas.has_num << std::endl;
}
*/

int main()
{
	string str1 = { "test01" };
	string str2 = { "test02" };
	HasPtr obj1(str1);
	HasPtr obj2(str2);
	obj2 = obj1;

	system("pause");
	return 0;
}
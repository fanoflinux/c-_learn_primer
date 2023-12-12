#include<iostream>
#include<string>


class HasPtr
{

public:
	//默认构造
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) 
	{ 
		std::cout << "in constructor" << std::endl;
	}
	//拷贝构造
	HasPtr(const HasPtr& hp) 
		:ps(new std::string(*hp.ps)), i(hp.i)
	{
		std::cout << "in copy constructor" << std::endl;
	}
	//重载
	HasPtr& operator=(const HasPtr& hp)
	{
		std::cout << "in operator constructor" << std::endl;
		//开辟一个新空间
		std::string* new_ps = new std::string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	//析构函数
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string* ps;
	int i;
};

int main()
{
	HasPtr has1("lingo");
	HasPtr has2;
	has2 = has1;

	system("pause");
	return 0;
}
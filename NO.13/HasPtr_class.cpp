#include<iostream>
#include<string>


class HasPtr
{

public:
	//Ĭ�Ϲ���
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) 
	{ 
		std::cout << "in constructor" << std::endl;
	}
	//��������
	HasPtr(const HasPtr& hp) 
		:ps(new std::string(*hp.ps)), i(hp.i)
	{
		std::cout << "in copy constructor" << std::endl;
	}
	//����
	HasPtr& operator=(const HasPtr& hp)
	{
		std::cout << "in operator constructor" << std::endl;
		//����һ���¿ռ�
		std::string* new_ps = new std::string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}
	//��������
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
#include<iostream>
#include<string>

using std::string;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator>(HasPtr&, HasPtr&);
	//construct function
	HasPtr() = default;
	HasPtr(const string &s)
		:ps(new string(s)),i(0)
	{
		std::cout << s << std::endl;
		std::cout << "construct function" << std::endl;
	}
	//copy construct
	HasPtr(const HasPtr&copy_has)
	{
		std::cout << "copy construct function" << std::endl;
		this->ps = new string(*(copy_has.ps));
		this->i = new int(*(copy_has.i));
	}
	HasPtr& operator=(const HasPtr& copy_has)
	{
		std::cout << "operator construct function" << std::endl;
		this->ps = new string(*(copy_has.ps));//开辟自己的空间
		this->i = new int(*(copy_has.i));//开辟新空间
		return *this;
	}
	~HasPtr()
	{
		delete this->ps;
		delete this->i;
	}
private:
	string* ps;
	int* i;
};

void swap(HasPtr& lhas, HasPtr& rhas)
{
	using std::swap;
	swap(lhas.ps, rhas.ps);
	swap(lhas.i, rhas.i);
	std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}


int main()
{
	string str1 = { "has1" };
	HasPtr has1(str1);
	HasPtr has2;
	has2 = has1;

	system("pause");
	return 0;
}
#include<iostream>


//定义一个类A
class A
{
public:
	int data_a;
	A(int a) :data_a(a) 
	{
		std::cout << "构造A对象--" << std::endl;
	}
	~A()
	{
		std::cout << "--析构A对象" << std::endl;
	}
};

class B
{
public:
	int data_b;
	B(int b) :data_b(b)
	{
		std::cout << "构造B对象--" << std::endl;
	}
	B(const B& former_b)
	{
		this->data_b = former_b.data_b;
		std::cout << "拷贝构造B对象--" << std::endl;
	}
	~B()
	{
		std::cout << "--析构B对象" << std::endl;
	}
};


void test_cop_constru()
{
	A a1(10);
	A a2(a1);//使用编译器给的默认拷贝构造函数,一直使用编译器的默认拷贝构造
	A a3 = a2;

	B b1(5);
	B b2(b1);
	B b3 = b1;
}

int main()
{
	test_cop_constru();

	system("pause");
	return 0;
}
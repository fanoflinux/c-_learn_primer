#include<iostream>


//����һ����A
class A
{
public:
	int data_a;
	A(int a) :data_a(a) 
	{
		std::cout << "����A����--" << std::endl;
	}
	~A()
	{
		std::cout << "--����A����" << std::endl;
	}
};

class B
{
public:
	int data_b;
	B(int b) :data_b(b)
	{
		std::cout << "����B����--" << std::endl;
	}
	B(const B& former_b)
	{
		this->data_b = former_b.data_b;
		std::cout << "��������B����--" << std::endl;
	}
	~B()
	{
		std::cout << "--����B����" << std::endl;
	}
};


void test_cop_constru()
{
	A a1(10);
	A a2(a1);//ʹ�ñ���������Ĭ�Ͽ������캯��,һֱʹ�ñ�������Ĭ�Ͽ�������
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
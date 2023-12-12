#include<iostream>
#include<vector>

class X
{
public:
	//构造函数
	X(const int value)
		:data_x(value)
	{
		std::cout << "使用X的构造函数" << std::endl;
	}
	//拷贝构造函数
	X(const X& copy_x)
	{
		std::cout << "X的拷贝构造函数" << std::endl;
		this->data_x = copy_x.data_x;
	}
	//运算符
	X& operator=(const X& copy_x)
	{
		std::cout << "赋值运算符号" << std::endl;
		this->data_x = copy_x.data_x;
	}
	~X()
	{
		std::cout << "析构函数" << std::endl;
	}
private:
	int data_x;
};

void func13_13()
{
	//初始化一个X对象并引用或者非引用使用这个对象
	X x1(5);
	X x2(x1);
	//使用容器防止X对象
	X x3 = x2;
	std::vector<X> vec1;
	vec1.push_back(x3);

}

int main()
{
	func13_13();

	system("pause");
	return 0;
}
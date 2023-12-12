#include<iostream>
using namespace std;

template <typename T>
void swap_fun(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T,typename D>
void swap_fun2(T& a, D& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int i1 = 1, i2 = 3;
	double d1 = 0.024, d2 = 9.258;

	cout << "交换前的i1为" <<i1<<"交换前的i2为：" <<i2<<endl;
	cout << "先进行int类型值的交换" << endl;
	swap_fun(i1, i2);
	cout << "交换后的i1为" << i1 << "交换后的i2为：" << i2 << endl;
	cout << endl;

	cout << "交换前的d1为" << d1 << "交换前的i2为：" << d2 << endl;
	cout << "先进行double类型值的交换" << endl;
	swap_fun(d1, d2);
	cout << "交换后的d1为" << d1 << "交换后的d2为：" << d2 << endl;

	swap_fun2(i1, d2);
}



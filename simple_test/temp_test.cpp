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

	cout << "����ǰ��i1Ϊ" <<i1<<"����ǰ��i2Ϊ��" <<i2<<endl;
	cout << "�Ƚ���int����ֵ�Ľ���" << endl;
	swap_fun(i1, i2);
	cout << "�������i1Ϊ" << i1 << "�������i2Ϊ��" << i2 << endl;
	cout << endl;

	cout << "����ǰ��d1Ϊ" << d1 << "����ǰ��i2Ϊ��" << d2 << endl;
	cout << "�Ƚ���double����ֵ�Ľ���" << endl;
	swap_fun(d1, d2);
	cout << "�������d1Ϊ" << d1 << "�������d2Ϊ��" << d2 << endl;

	swap_fun2(i1, d2);
}



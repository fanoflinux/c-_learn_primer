#include<iostream>
#include<vector>

class X
{
public:
	//���캯��
	X(const int value)
		:data_x(value)
	{
		std::cout << "ʹ��X�Ĺ��캯��" << std::endl;
	}
	//�������캯��
	X(const X& copy_x)
	{
		std::cout << "X�Ŀ������캯��" << std::endl;
		this->data_x = copy_x.data_x;
	}
	//�����
	X& operator=(const X& copy_x)
	{
		std::cout << "��ֵ�������" << std::endl;
		this->data_x = copy_x.data_x;
	}
	~X()
	{
		std::cout << "��������" << std::endl;
	}
private:
	int data_x;
};

void func13_13()
{
	//��ʼ��һ��X�������û��߷�����ʹ���������
	X x1(5);
	X x2(x1);
	//ʹ��������ֹX����
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
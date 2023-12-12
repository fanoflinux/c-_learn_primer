#include<iostream>
#include<vector>
#include<string>

using namespace std;

//define hasptr class
class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);

public:
	//Ĭ�Ϲ��캯��
	HasPtr() = default;
	//���幹�캯��
	HasPtr(const string &s)
		:has_name(new string(s)),has_num(1)
	{
		std::cout << "����has_ptr:" << *(this->has_name) << "���Ϊ:" << this->has_num << std::endl;
	}
	//���忽�����캯��
	HasPtr(const HasPtr& pri_has)
	{
		this->has_num = pri_has.has_num + 1;
		std::cout << "���忽������ı��" << this->has_num << std::endl;
		this->has_name = (new string(*(pri_has.has_name)));
		std::cout << "���忽�����������" << *(this->has_name) << "���ַΪ" << this->has_name << std::endl;
	}
	//���帳ֵ��������
	HasPtr& operator=(HasPtr& pri_has)
	{
		swap(pri_has);
		return *this;
	}
	//�������еĽ����������ڸ�ֵ��������
	
	void swap(HasPtr& pri_has)
	{
		std::cout << "����ǰ������:" << *(pri_has.has_name) << std::endl;
		std::cout << "����ǰ�������ڴ�:" << pri_has.has_name << std::endl;
		std::cout << "����ǰ����ֵ" << pri_has.has_num << std::endl;
		std::cout << "����ǰ������:" << *(this->has_name) << std::endl;
		std::cout << "����ǰ�������ڴ�:" << this->has_name << std::endl;
		std::cout << "����ǰ����ֵ" << this->has_num << std::endl;
		std::cout << std::endl;
		using std::swap;
		swap(this->has_name, pri_has.has_name);
		swap(this->has_num, pri_has.has_num);
		std::cout << "--�������ڵĽ�������--" << std::endl;
		std::cout << "�����������:" << *(pri_has.has_name) << std::endl;
		std::cout << "������������ڴ�:" << pri_has.has_name << std::endl;
		std::cout << "���������ֵ" << pri_has.has_num << std::endl;
		std::cout << "�����������:" << *(this->has_name) << std::endl;
		std::cout << "������������ڴ�:" << this->has_name << std::endl;
		std::cout << "���������ֵ" << this->has_num << std::endl;
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
	std::cout << "����ǰ������:" << *(lhas.has_name) << std::endl;
	std::cout << "����ǰ�������ڴ�:" << lhas.has_name << std::endl;
	std::cout << "����ǰ����ֵ" << lhas.has_num << std::endl;
	std::cout << "����ǰ������:" << *(rhas.has_name) << std::endl;
	std::cout << "����ǰ�������ڴ�:" << rhas.has_name << std::endl;
	std::cout << "����ǰ����ֵ" << rhas.has_num << std::endl;
	std::cout << "�����Զ�����Ѻ���swap" << std::endl;
	swap(lhas.has_name, rhas.has_name);
	swap(lhas.has_num, rhas.has_num);
	std::cout << "�����������:" << *(lhas.has_name) << std::endl;
	std::cout << "������������ڴ�:" << lhas.has_name << std::endl;
	std::cout << "���������ֵ" << lhas.has_num << std::endl;
	std::cout << "�����������:" << *(rhas.has_name) << std::endl;
	std::cout << "������������ڴ�:" << rhas.has_name << std::endl;
	std::cout << "���������ֵ" << rhas.has_num << std::endl;
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
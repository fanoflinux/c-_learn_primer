#include<iostream>
#include<vector>
#include<memory>
#include<initializer_list>
#include<exception>
#include<string>

using std::vector;
using std::string;

class strBlob
{
public:
	//���ͱ���
	typedef vector<string>::size_type size_type;
	strBlob() = default;
	strBlob(std::initializer_list<string> i1) 
		:data(std::make_shared<vector<string>>(i1)) 
	{}
	//�жϴ�С����
	size_type size() const
	{
		return data->size();
	}
	//�пպ���
	bool empty() const 
	{
		return data->empty();
	}
	//�����ɾ��Ԫ�صĲ���
	void push_back(const string& str)
	{
		data->push_back(str);
	}
	void pop_back()
	{
		//ִ�в�ѯ�����Ƿ�Ϊ�յĲ���
		check(0, "��������Ϊ�գ��޷��ٽ��з��ʣ�");
		data->pop_back();
	}
	//Ԫ�ط���
	string& front()
	{
		check(0, "������Ϊ������");
		return data->front();
	}
	string& back()
	{
		check(0, "������Ϊ������");
		return data->back();
	}
	const string& front()const
	{
		check(0, "������Ϊ������");
		return data->front();
	}
	const string& back()const
	{
		check(0, "������Ϊ������");
		return data->back();
	}

private:
	//����ָ������û��ĵײ��ڴ�
	std::shared_ptr<vector<string>> data;
	//���������ݵĺ���,��ֹ�Գ����������ֽ�����ֹ
	void check(size_type i, const string& msg)const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};


int main()
{
	strBlob str1{ "hello", "world" };
	strBlob cstr1{ "const", "hello", "world", "aaa" };
	std::cout << "str1:" << str1.front() << " " << str1.back() << std::endl;
	std::cout << "cstr1:" << cstr1.front() << " " << cstr1.back() << std::endl;

	system("pause");
	return 0;

}
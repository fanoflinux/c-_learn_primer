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
	//类型别名
	typedef vector<string>::size_type size_type;
	strBlob() = default;
	strBlob(std::initializer_list<string> i1) 
		:data(std::make_shared<vector<string>>(i1)) 
	{}
	//判断大小函数
	size_type size() const
	{
		return data->size();
	}
	//判空函数
	bool empty() const 
	{
		return data->empty();
	}
	//添加与删除元素的操作
	void push_back(const string& str)
	{
		data->push_back(str);
	}
	void pop_back()
	{
		//执行查询容器是否为空的操作
		check(0, "容器内容为空，无法再进行访问！");
		data->pop_back();
	}
	//元素访问
	string& front()
	{
		check(0, "该容器为空容器");
		return data->front();
	}
	string& back()
	{
		check(0, "该容器为空容器");
		return data->back();
	}
	const string& front()const
	{
		check(0, "该容器为空容器");
		return data->front();
	}
	const string& back()const
	{
		check(0, "该容器为空容器");
		return data->back();
	}

private:
	//定义指针操作用户的底层内存
	std::shared_ptr<vector<string>> data;
	//定义检查内容的函数,防止对超过索引部分进行阻止
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
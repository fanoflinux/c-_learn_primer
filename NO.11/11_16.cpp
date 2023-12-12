#include<iostream>
#include<map>
#include<vector>
#include<string>

using std::vector;
using std::map;
using std::string;

void func11_16(map<int,string> &map_int_str)
{
	//制作普通迭代器
	map<int, string>::iterator insert_iter = map_int_str.begin();
	//指定自己的迭代器
	std::insert_iterator<map<int, string>> iter(map_int_str, insert_iter);
	//添加元素
	std::cout << "输入要进行填充的编号内容";
	int find_num=0;
	std::cin >> find_num;
	map<int, string>::iterator iter_find = map_int_str.find(find_num);
	if (iter_find != map_int_str.end())
	{
		std::cout << "找到了相关值" << std::endl;
		string modify_value;
		std::cout << "插入的值为:";
		std::cin >> modify_value;
		iter_find->second = modify_value;
	}
	else
	{
		std::cout << "未找到相关值" << std::endl;
	}
}

int main()
{
	map<int, string> map_int_dtr = { {1,"jake"},{2,"jim"},{3,"rose"} };
	std::cout << "map中的值为" << std::endl;
	for (const auto& i : map_int_dtr)
	{
		std::cout << "编号为:" << i.first << "名字为:" << i.second << std::endl;
	}
	func11_16(map_int_dtr);
	std::cout << "修改后map中的值为" << std::endl;
	for (const auto& i : map_int_dtr)
	{
		std::cout << "编号为:" << i.first << "名字为:" << i.second << std::endl;
	}

	system("pause");
	return 0;
}
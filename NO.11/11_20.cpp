#include<iostream>
#include<map>
#include<vector>
#include<string>

using std::vector;
using std::map;
using std::string;

void func11_20(map<int, string>& map_int_str)
{
	std::cout << "����Ҫ�������ı������";
	int find_num = 0;
	std::cin >> find_num;
	map<int, string>::iterator iter_find = map_int_str.find(find_num);
	if (iter_find != map_int_str.end())
	{
		std::cout << "�ҵ������ֵ" << std::endl;
		string modify_value;
		std::cout << "�����ֵΪ:";
		std::cin >> modify_value;
		//auto ret = map_int_str.insert(std::make_pair(modify_value, find_num));
		auto ret = map_int_str.insert(std::make_pair(find_num,modify_value));
		if (ret.second)
		{
			std::cout << "����ɹ�" << std::endl;
		}
		else
			std::cout << "����ʧ��" << std::endl;
	}
	else
	{
		std::cout << "δ�ҵ����ֵ" << std::endl;
	}
}

int main()
{
	map<int, string> map_int_dtr = { {1,"jake"},{2,"jim"},{3,"rose"} };
	std::cout << "map�е�ֵΪ" << std::endl;
	for (const auto& i : map_int_dtr)
	{
		std::cout << "���Ϊ:" << i.first << "����Ϊ:" << i.second << std::endl;
	}
	func11_20(map_int_dtr);
	std::cout << "�޸ĺ�map�е�ֵΪ" << std::endl;
	for (const auto& i : map_int_dtr)
	{
		std::cout << "���Ϊ:" << i.first << "����Ϊ:" << i.second << std::endl;
	}

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

void func10_9(std::vector<std::string>& str1)
{
	//进行排序
	std::sort(str1.begin(), str1.end());
	//进行重复元素去除
	auto end_unique = std::unique(str1.begin(), str1.end());
	//去除重复元素
	str1.erase(end_unique, str1.end());
	/*for (auto iter = str1.begin(); iter < end_unique; iter++)
	{
		std::cout << *iter << ";";
	}*/
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> str1 = { "a","s","d","f","f","g""h" };
	func10_9(str1);
	for (auto& i : str1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
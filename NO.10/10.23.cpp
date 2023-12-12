#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std::placeholders;

bool check_size(std::string str1 , size_t len)
{
	if (len > str1.size())
		return true;
	else
		return false;
	return true;
}

int main()
{
	std::vector<int> vec1 = { 1,2,3,4,5,6,7,8,9,0 };
	std::string str1 = { "asdf" };
	std::cout << "字符串的长度为：" << str1.size() << std::endl;
	std::cout << std::endl;
	auto iter= std::find_if(vec1.begin(), vec1.end(),
		std::bind(check_size, str1, _1));

	if (iter != vec1.end())
		std::cout << *iter;

	system("pause");
	return 0;
}
#include<string>
#include<iostream>

void func9_47()
{
	std::string num = { "123456789" };
	std::string str = { "ab2c3d7r4e6" };
	std::cout << "原字符串为：" << std::endl;
	for (const auto& i : str)
	{
		std::cout << i ;
	}
	std::cout << std::endl;
	//查找第一次出现数字的位置
	auto pos1=str.find_first_of(num);
	std::cout << "第一次出现数字的位置" << pos1+1 << std::endl;
	//查找最后一次出现数字的位置
	auto pos2 = str.find_last_of(num);
	std::cout << "最后一次出现数字的位置" << pos2+1 << std::endl;

	//查找第一次出现字母的位置
	auto pos3 = str.find_first_not_of(num);
	std::cout << "第一次出现字母的位置" << pos3 + 1 << std::endl;
	//查找最后一次出现字母的位置
	auto pos4 = str.find_last_not_of(num);
	std::cout << "最后一次出现字母的位置" << pos4 + 1 << std::endl;

}

int main()
{
	func9_47();

	system("pause");
	return 0;
}
#include<iostream>
#include<string>

void func9_49(const std::string target)
{
	std::string mid{"bdfghjklpqty"};
	size_t pos = target.find_first_of(mid);
	std::cout << "第一个中部字母：" << pos << std::endl;
	while (pos < target.size())
	{

	}

}



int main()
{
	std::string target = { "hpuoufdihsouifhouewhqfuehdbhavbl" };


	system("pause");
	return 0;
}
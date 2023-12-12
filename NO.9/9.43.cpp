#include<iostream>
#include<string>

void func9_43(std::string &s1,const std::string oldval,std::string newval)
{
	auto itr = s1.begin();
	while (itr!=s1.end()-oldval.size())
	{
		if (oldval == std::string(itr, itr + oldval.size()))
		{
			itr = s1.erase(itr, itr + oldval.size());
			itr = s1.insert(itr, newval.begin(), newval.end());
			itr += newval.size();
		}
		else
		{
			itr++;
		}
	}
	for (const auto& i : s1)
	{
		std::cout << i;
	}

}

int main()
{
	std::cout << "调整之前的内容为：" << std::endl;
	std::string s("To drive straight thru is a foolish, tho courageous act.");
	for (const auto& i : s)
	{
		std::cout << i;
	}
	std::cout <<std::endl;
	std::cout << "调整之后的内容为：" << std::endl;
	func9_43(s, "tho", "though");
	std::cout << "over" << std::endl;
	system("pause");
	return 0;
}
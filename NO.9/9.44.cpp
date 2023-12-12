#include<iostream>
#include<string>

void func9_44(std::string& s1, const std::string oldval, std::string newval)
{
	for (auto pos = 0; pos < s1.size() - oldval.size(); )
	{
		if (s1[pos] == oldval[0] && s1.substr(pos,oldval.size()) == oldval)
		{
			s1.replace(pos, oldval.size(), newval);
			pos += newval.size();
		}
		else
		{
			pos++;
		}
	}

	for (const auto& i : s1)
	{
		std::cout << i;
	}

}

int main()
{
	std::cout << "����֮ǰ������Ϊ��" << std::endl;
	std::string s("To drive straight thru is a foolish, tho courageous act.");
	for (const auto& i : s)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	std::cout << "����֮�������Ϊ��" << std::endl;
	func9_44(s, "tho", "though");
	std::cout << "over" << std::endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<string>

std::string func9_46(std::string& name, const std::string& pr, const std::string& ed)
{
	size_t len_name = name.size();
	size_t pos = 0;
	name.insert(pos, pr);
	name.insert(len_name, ed);
	for (const auto& i : name)
	{
		std::cout << i;
	}
	std::cout << std::endl;
	return name;
}

int main()
{
	std::string name = "Jack";
	std::string str;
	str = func9_46(name, "Mr-", "-03");

	system("pause");
	return 0;
}
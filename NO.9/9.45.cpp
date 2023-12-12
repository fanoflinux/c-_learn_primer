#include<iostream>
#include<string>

std::string func9_45(std::string& name, const std::string& pr, const std::string& ed)
{
	auto itr_name_be = name.begin();
	//auto itr_name_ed = name.end();
	auto itr_pr = pr.begin();
	//auto itr_ed = ed.begin();
	name.insert(itr_name_be, itr_pr, itr_pr + pr.size());
	name.append(ed);
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
	str=func9_45(name, "Mr-", "-03");
	system("pause");
	return 0;
}
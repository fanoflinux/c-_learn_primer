#include<iostream>
#include<string>
#include<utility>
#include<vector>

int main()
{
	std::pair<std::string, int> pair_str_int;
	std::vector<std::pair<std::string, int>> vec;
	std::string word;
	int i = 0;
	while (word!="end")
	{
		std::cout << "����wordֵ";
		std::cin >> word;
		std::cout << "����iֵ";
		std::cin >> i;
		vec.push_back(std::pair<std::string, int>(word, i));
	}

	for (const auto& j : vec)
	{
		std::cout << j.first << ";" << j.second << ";";
	}

	system("pause");
	return 0;
}
#include<iostream>
#include<map>
#include<list>
#include<string>

int main()
{
	std::map < std::string, std::list<int>> word_map;
	std::cout << "�������봦��" << std::endl;
	std::string word;
	int line_num = 0;
	while (word!="eof")
	{
		for (auto& i : word_map)
		{

			std::cout << "���뵥��:";
			std::cin >> word;
		}
		
	}


	system("pause");
	return 0;
}
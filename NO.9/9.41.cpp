#include<iostream>
#include<string>
#include<vector>

void func9_41()
{
	std::vector<char> vec1 = {'a','b','c','d'};
	std::string str1(vec1.begin(),vec1.end());
	for (const auto& i : str1)
	{
		std::cout << i << ";";
	}
}

int main()
{
	std::cout << "Á·Ï°9£¬41"<<std::endl;
	func9_41();
	std::cout << std::endl;
	system("pause");
	return 0;
}
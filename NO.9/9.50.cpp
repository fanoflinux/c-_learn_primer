#include<iostream>
#include<vector>
#include<string>


void func9_50()
{
	std::vector < std::string> vec1 = { "1","2","3" };
	int sum = 0;
	for (auto iter = vec1.begin(); iter != vec1.end(); iter++)
	{
		sum += std::stoi(*iter);
	}
	std::cout << "ºÍÎª£º" << sum;
}

int main()
{
	func9_50();
	system("pause");
	return 0;
}
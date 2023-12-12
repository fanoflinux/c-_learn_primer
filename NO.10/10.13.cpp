#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

bool func10_13(const std::string &str)
{
	if (str.size() >= 5)
		return true;
	else
		return false;

	return true;
}

int main()
{
	std::vector < std::string > vec1 = { "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
	std::partition(vec1.begin(), vec1.end(), func10_13);
	for (auto& i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
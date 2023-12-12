#include<iostream>
#include<algorithm>
#include<vector>

void func10_6(std::vector<int> &vec1)
{
	std::fill_n(vec1.begin(), vec1.size(), 0);
}

int main()
{
	std::vector<int> vec1 { 1,2,3,4,5,6,7,8,9 };
	std::cout << "原容器中的元素为：" << std::endl;
	for (const auto& i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout<<std::endl;
	func10_6(vec1);
	std::cout << "改变后容器中的元素为：" << std::endl;
	for (const auto& i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
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
	std::cout << "ԭ�����е�Ԫ��Ϊ��" << std::endl;
	for (const auto& i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout<<std::endl;
	func10_6(vec1);
	std::cout << "�ı�������е�Ԫ��Ϊ��" << std::endl;
	for (const auto& i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
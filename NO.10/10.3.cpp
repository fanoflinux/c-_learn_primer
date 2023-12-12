#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

int func10_3(std::vector<int> vec1)
{
	int retult = std::accumulate(vec1.begin(), vec1.end(), 0);
	return retult;
}

int main()
{
	std::vector<int> vec1 = { 1,2,3,4,5 };
	int retult = func10_3(vec1);
	std::cout << "vector容器中的和为" << retult << std::endl;

	system("pause");
	return 0;
}
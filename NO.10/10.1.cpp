#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

//int find_num(const int arr[])
int func10_1(const int arr[], int length)
{
	std::vector<int> vec1;
	for (int i = 0; i < length; i++)
	{
		vec1.push_back(arr[i]);
	}
	int num_of_vec = std::count(vec1.begin(), vec1.end(), 6);
	return num_of_vec;
}

int func10_2(const std::string &str)
{
	//std::list<std::string> l1;
	std::list<char> l1(str.begin(), str.end());
	int num_of_str = std::count(l1.begin(), l1.end(), "6");
	return num_of_str;
}

int main()
{
	int arr[] = { 1,2,3,3,4,5,6,6,6,7,8,9,0 };
	int length1 = sizeof(arr) / sizeof(arr[0]);
	int num_of_vec = func10_1(arr,length1);
	std::cout << "数组中6的个数为" << num_of_vec << std::endl;

	std::string str="166";
	int num_of_str = func10_2(str);
	std::cout << "字符串中6的个数为" << num_of_str << std::endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<map>
#include<set>

//初始vector容器
std::vector<int> initialization_vec_func()
{
	std::vector<int> vec0;
	for (auto i = 0; i < 10; i++)
	{
		vec0.push_back(i);
		vec0.push_back(i);
	}
	std::cout << "输出vector值" << ":" << std:: endl;
	for (auto& i : vec0)
		std::cout << i << ";";
	std::cout << std::endl;
	return vec0;
}

//进行set的初始化
void initialization_set(std::vector<int> vec)
{
	std::set<int> vec2set(vec.begin(), vec.end());
	std::cout << "输出set的相关值" << std::endl;
	for (auto& i : vec2set)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	std::cout << "输出multiset的相关值" << std::endl;
	std::multiset<int> vec2mlset(vec.begin(), vec.end());
	for (auto& i : vec2mlset)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
}
//使用指定迭代器的方法
void Specifying_an_Iterator(std::vector<int> &vec)
{
	for (const auto& i : vec)
		std::cout << i << ";";
	std::cout << "进行迭代器添加" << std::endl;
	std::vector<int>::iterator it = vec.begin() + 1;//指定迭代器再开始位置加一的位置(基础迭代器）
	std::insert_iterator<std::vector<int>> init_it = std::inserter(vec, it);//创建一个进阶版本的迭代器
	init_it = 1;
	init_it = 5;
	init_it = 7;
	init_it = 9;
	for (const auto& i : vec)
		std::cout << i << ";";
}

int main()
{
	std::vector<int> vec1 = initialization_vec_func();
	initialization_set(vec1);

	//测试指定迭代器的方法
	std::vector<int> vec2 = { 1,2,3,4,5 };
	Specifying_an_Iterator(vec2);

	system("pause");
	return 0;
}
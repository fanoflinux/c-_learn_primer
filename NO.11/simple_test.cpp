#include<iostream>
#include<vector>
#include<map>
#include<set>

//��ʼvector����
std::vector<int> initialization_vec_func()
{
	std::vector<int> vec0;
	for (auto i = 0; i < 10; i++)
	{
		vec0.push_back(i);
		vec0.push_back(i);
	}
	std::cout << "���vectorֵ" << ":" << std:: endl;
	for (auto& i : vec0)
		std::cout << i << ";";
	std::cout << std::endl;
	return vec0;
}

//����set�ĳ�ʼ��
void initialization_set(std::vector<int> vec)
{
	std::set<int> vec2set(vec.begin(), vec.end());
	std::cout << "���set�����ֵ" << std::endl;
	for (auto& i : vec2set)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	std::cout << "���multiset�����ֵ" << std::endl;
	std::multiset<int> vec2mlset(vec.begin(), vec.end());
	for (auto& i : vec2mlset)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
}
//ʹ��ָ���������ķ���
void Specifying_an_Iterator(std::vector<int> &vec)
{
	for (const auto& i : vec)
		std::cout << i << ";";
	std::cout << "���е��������" << std::endl;
	std::vector<int>::iterator it = vec.begin() + 1;//ָ���������ٿ�ʼλ�ü�һ��λ��(������������
	std::insert_iterator<std::vector<int>> init_it = std::inserter(vec, it);//����һ�����װ汾�ĵ�����
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

	//����ָ���������ķ���
	std::vector<int> vec2 = { 1,2,3,4,5 };
	Specifying_an_Iterator(vec2);

	system("pause");
	return 0;
}
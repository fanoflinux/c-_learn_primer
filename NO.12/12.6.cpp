#include<iostream>
#include<vector>
#include<memory>

using std::vector;

//创建vector容器
vector<int>* func_new_vec()
{
	vector<int>* vec1 = new vector<int>;
	return vec1;
}
//分配内容
void func_write_vec(vector<int> *vec1)
{
	std::cout << "输入要进行存储的数字(输入-1停止输入）" << std::endl;
	int p=0;
	while (p!=-1)
	{
		std::cin >> p;
		vec1->push_back(p);
	}
}
//输出相关内容
void func_print_vec(vector<int> *vec1)
{
	std::cout << "输出相关数据" << std::endl;
	size_t len = vec1->size();
	for (auto i=vec1->begin();i<vec1->end()-1;i++)
	{
		std::cout << *i << ";";
	}
	std::cout << std::endl;
}

int main()
{
	auto vec1 = func_new_vec();
	func_write_vec(vec1);
	func_print_vec(vec1);
	delete vec1;
	system("pause");
	return 0;
}
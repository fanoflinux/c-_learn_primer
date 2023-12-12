#include<iostream>
#include<vector>
#include<memory>

using std::vector;

std::shared_ptr<vector<int>> func_new_vec()
{
	return std::make_shared<vector<int>>();
}
//分配内容
void func_write_vec(std::shared_ptr<vector<int>> sh_ptr_vec1)
{
	std::cout << "输入要进行存储的数字(输入-1停止输入）" << std::endl;
	int p = 0;
	while (p!=-1)
	{
		std::cin >> p;
		sh_ptr_vec1->push_back(p);
	}
}
//输出内容
void func_print_vec(std::shared_ptr<vector<int>> sh_ptr_vec1)
{
	std::cout << "输出相关数据" << std::endl;
	size_t len = sh_ptr_vec1->size();
	for (auto i = sh_ptr_vec1->begin(); i < sh_ptr_vec1->end() - 1; i++)
	{
		std::cout << *i << ";";
	}
	std::cout << std::endl;
}

int main()
{
	auto sh_ptr_vec1=func_new_vec();
	func_write_vec(sh_ptr_vec1);
	func_print_vec(sh_ptr_vec1);


	system("pause");
	return 0;
}
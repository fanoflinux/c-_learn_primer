#include<iostream>
#include<memory>
#include<vector>

using std::vector;

int* func_est_arr()
{
	std::allocator<int> all1;
	//分配5个内存空间
	auto *arr = all1.allocate(5);
	std::cout << "输入要初始化的值" << std::endl;
	int p = 0;
	for (int i=0; i < 5; i++)
	{
		std::cin >> p;
		arr[i] = p;
	}
	std::cout << "打印初始化的值" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ";";
	}
	std::cout << "释放相关内存" << std::endl;
	all1.deallocate(arr,5);
	std::cout << "打印初始化的值" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ";";
	}
	std::cout << std::endl;

	return arr;
}
int main()
{
	int* arr = func_est_arr();
	

	system("pause");
	return 0;
}
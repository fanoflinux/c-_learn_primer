#include<iostream>
#include<memory>
#include<vector>

using std::vector;

int* func_est_arr()
{
	std::allocator<int> all1;
	//����5���ڴ�ռ�
	auto *arr = all1.allocate(5);
	std::cout << "����Ҫ��ʼ����ֵ" << std::endl;
	int p = 0;
	for (int i=0; i < 5; i++)
	{
		std::cin >> p;
		arr[i] = p;
	}
	std::cout << "��ӡ��ʼ����ֵ" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ";";
	}
	std::cout << "�ͷ�����ڴ�" << std::endl;
	all1.deallocate(arr,5);
	std::cout << "��ӡ��ʼ����ֵ" << std::endl;
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
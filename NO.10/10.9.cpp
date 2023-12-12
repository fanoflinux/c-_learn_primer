#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

void func10_9(std::vector<std::string>& str1)
{
	//��������
	std::sort(str1.begin(), str1.end());
	//�����ظ�Ԫ��ȥ��
	auto end_unique = std::unique(str1.begin(), str1.end());
	//ȥ���ظ�Ԫ��
	str1.erase(end_unique, str1.end());
	/*for (auto iter = str1.begin(); iter < end_unique; iter++)
	{
		std::cout << *iter << ";";
	}*/
	std::cout << std::endl;
}

int main()
{
	std::vector<std::string> str1 = { "a","s","d","f","f","g""h" };
	func10_9(str1);
	for (auto& i : str1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
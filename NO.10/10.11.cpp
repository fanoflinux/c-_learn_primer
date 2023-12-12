#include<iostream>
#include<vector>
#include<algorithm>

bool isShoerter(const std::string& str1, const std::string& str2)
{
	return str1.size() < str2.size();
}

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
	std::vector<std::string> str1 = { "1234", "1234", "1234", "Hi", "alan", "wang" };
	func10_9(str1);
	std::stable_sort(str1.begin(), str1.end(), isShoerter);
	for (auto& i : str1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
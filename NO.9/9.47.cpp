#include<string>
#include<iostream>

void func9_47()
{
	std::string num = { "123456789" };
	std::string str = { "ab2c3d7r4e6" };
	std::cout << "ԭ�ַ���Ϊ��" << std::endl;
	for (const auto& i : str)
	{
		std::cout << i ;
	}
	std::cout << std::endl;
	//���ҵ�һ�γ������ֵ�λ��
	auto pos1=str.find_first_of(num);
	std::cout << "��һ�γ������ֵ�λ��" << pos1+1 << std::endl;
	//�������һ�γ������ֵ�λ��
	auto pos2 = str.find_last_of(num);
	std::cout << "���һ�γ������ֵ�λ��" << pos2+1 << std::endl;

	//���ҵ�һ�γ�����ĸ��λ��
	auto pos3 = str.find_first_not_of(num);
	std::cout << "��һ�γ�����ĸ��λ��" << pos3 + 1 << std::endl;
	//�������һ�γ�����ĸ��λ��
	auto pos4 = str.find_last_not_of(num);
	std::cout << "���һ�γ�����ĸ��λ��" << pos4 + 1 << std::endl;

}

int main()
{
	func9_47();

	system("pause");
	return 0;
}
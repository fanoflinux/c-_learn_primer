#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using std::vector;
using std::string;

void func11_7(std::map<string,vector<string>> fam_map0)
{
	std::cout << "ѡ����ع���" << std::endl;
	std::cout << "--1--�鿴���м�ͥ" << std::endl;
	std::cout << "--2--����µļ�ͥ" << std::endl;
	std::cout << "--3--����µĳ�Ա" << std::endl;
	int choice = 0;
	std::cout << "����Ҫʹ�õĹ���" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (auto& i : fam_map0)
		{
			std::cout << "��ͥ:" << i.first<<";";
			std::cout << "��ͥ��Ա:";
			for (auto& j : i.second)
			{
				std::cout << j << ";";
			}
		}
		break;
	}
	case 2:
	{
		//����µļ�ͥ
		string new_fam_name;
		std::cout << "�¼�ͥ�����֣�";
		std::cin >> new_fam_name;
		fam_map0[new_fam_name];
		std::cout << "���ڼ�ͥ����Ϊ��" << std::endl;
		for (auto& i : fam_map0)
		{
			std :: cout << "" << i.first<<";";
		}
		break;
	}
	case 3:
	{
		for (auto& i : fam_map0)
		{
			std::cout << "��ͥ:" << i.first << ";";
			std::cout << "��ͥ��Ա:";
			for (auto& j : i.second)
			{
				std::cout << j << ";";
			}
		}
		vector<string> new_fam_num;
		string new_num;
		std::cout << "�����ͥ��Ա������(����eof��������)";
		for (const size_t i=0;;)
		{
			std::cin >> new_num;
			if (new_num == "eof")
				break;
			else
			{
				fam_map0["1�ż�ͥ"].push_back(new_num);
			}
		}
		std::cout << "��Ӻ�ļ�ͥ��"<<std::endl;
		for (auto& i : fam_map0)
		{
			std::cout << "��ͥ:" << i.first << ";";
			std::cout << "��ͥ��Ա:";
			for (auto& j : i.second)
			{
				std::cout << j << ";";
			}
		}
		break;
	}
	default:
		break;
	}

}

int main()
{
	std::map<string, vector<string>> fam_map0 = { {"1�ż�ͥ",{"lily,mark"} } };
	func11_7(fam_map0);


	system("pause");
	return 0;
}
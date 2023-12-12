#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using std::vector;
using std::string;

void func11_7(std::map<string,vector<string>> fam_map0)
{
	std::cout << "选择相关功能" << std::endl;
	std::cout << "--1--查看现有家庭" << std::endl;
	std::cout << "--2--添加新的家庭" << std::endl;
	std::cout << "--3--添加新的成员" << std::endl;
	int choice = 0;
	std::cout << "输入要使用的功能" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (auto& i : fam_map0)
		{
			std::cout << "家庭:" << i.first<<";";
			std::cout << "家庭成员:";
			for (auto& j : i.second)
			{
				std::cout << j << ";";
			}
		}
		break;
	}
	case 2:
	{
		//添加新的家庭
		string new_fam_name;
		std::cout << "新家庭的名字：";
		std::cin >> new_fam_name;
		fam_map0[new_fam_name];
		std::cout << "现在家庭名字为：" << std::endl;
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
			std::cout << "家庭:" << i.first << ";";
			std::cout << "家庭成员:";
			for (auto& j : i.second)
			{
				std::cout << j << ";";
			}
		}
		vector<string> new_fam_num;
		string new_num;
		std::cout << "输入家庭成员的名字(输入eof结束输入)";
		for (const size_t i=0;;)
		{
			std::cin >> new_num;
			if (new_num == "eof")
				break;
			else
			{
				fam_map0["1号家庭"].push_back(new_num);
			}
		}
		std::cout << "添加后的家庭："<<std::endl;
		for (auto& i : fam_map0)
		{
			std::cout << "家庭:" << i.first << ";";
			std::cout << "家庭成员:";
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
	std::map<string, vector<string>> fam_map0 = { {"1号家庭",{"lily,mark"} } };
	func11_7(fam_map0);


	system("pause");
	return 0;
}
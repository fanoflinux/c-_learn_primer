#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<cctype>

using std::string;

std::map<string,size_t> func11_3(const string &str)
{
	//����map
	std::map<string, size_t> word_conut;
	//����һ�������ڷ��뵥��
	std::istringstream iss(str);
	//����һ���ַ������ڳн����е�����
	string word;
	while (iss>>word)
	{
		//ȥ�������ţ���������ʵ��������е���
		for (size_t i = 0; i < word.size(); ++i)
		{
			if (ispunct(word[i]))
				word.erase(i--, 1);
		}
		//����д����ȫ��ת��ΪСд
		for (auto& i: word)
		{
			i = std::tolower(i);
		}
		++word_conut[word];
	}
	return word_conut;
}

int main()
{
	string str1 = { "This is a simple E xample. This example demonstrates how to count words in a string." };
	std::map<string, size_t> result = func11_3(str1);
	std::cout << "ԭʼ���Ϊ:";
	for (const auto& i : str1)
		std::cout << i;
	std::cout << "����ͳ�Ʋ������Ϊ��" << std::endl;
	for (const auto& pair : result)
		std::cout << pair.first << "���ִ���Ϊ:" << pair.second << std::endl;

	system("pause");
	return 0;
}
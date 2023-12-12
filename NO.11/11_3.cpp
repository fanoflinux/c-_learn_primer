#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<cctype>

using std::string;

std::map<string,size_t> func11_3(const string &str)
{
	//创建map
	std::map<string, size_t> word_conut;
	//创建一个流用于放入单词
	std::istringstream iss(str);
	//创建一个字符串用于承接流中的内容
	string word;
	while (iss>>word)
	{
		//去除标点符号，可以依据实际需求进行调整
		for (size_t i = 0; i < word.size(); ++i)
		{
			if (ispunct(word[i]))
				word.erase(i--, 1);
		}
		//将大写内容全部转换为小写
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
	std::cout << "原始语句为:";
	for (const auto& i : str1)
		std::cout << i;
	std::cout << "进行统计操作结果为：" << std::endl;
	for (const auto& pair : result)
		std::cout << pair.first << "出现次数为:" << pair.second << std::endl;

	system("pause");
	return 0;
}
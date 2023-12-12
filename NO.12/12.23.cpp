#include<iostream>
#include<string>
#include<memory>
#include<vector>

using std::string;
using std::vector;

std::unique_ptr<char[]> connect1(const vector<char>& ch1,const vector<char>& ch2)
{
	size_t ch_len1 = ch1.size();
	size_t ch_len2 = ch2.size();
	size_t ch_len3 = ch_len1+ ch_len2;
	std::unique_ptr<char[]> ch_ptr (new char[ch_len3]);
	for (auto i = 0; i < ch_len1; i++)
	{
		ch_ptr[i] = ch1[i];
	}
	for (auto j = ch_len1; j < ch_len2 + ch_len1; j++)
	{
		ch_ptr[j] = ch2[j - ch_len1];
	}
	return ch_ptr;
}

std::unique_ptr<string[]> connect2(const string& str1, const string& str2)
{
	size_t str_len1 = str1.size();
	size_t str_len2 = str2.size();
	size_t str_len3 = str_len1 + str_len2 + 1;
	std::unique_ptr<string[]> str_ptr(new string[str_len3]);
	for (auto i = 0; i < str_len1; i++)
	{
		str_ptr[i] = str1[i];
	}
	for (auto j = str_len1; j < str_len2+str_len1; j++)
	{
		str_ptr[j] = str2[j-str_len1];
	}
	return str_ptr;
}

int main()
{
	string str1 = { "hi" };
	string str2 = { "world" };
	std::unique_ptr<string[]> str_ptr1 = connect2(str1, str2);
	for (auto i = 0; i < (str1.size() + str2.size()); i++)
	{
		std::cout << str_ptr1[i];
	}

	system("pause");
	return 0;
}
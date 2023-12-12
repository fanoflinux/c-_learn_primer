#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool func9_22(const string str,const string::size_type len)
{
	if (str.size() < len)
	{
		return false;
	}
	else
		return true;
	return true;
}


int main()
{
	vector<string> vec1 = { "1234", "123456", "1234567", "1234567", "1234567", "1234567" };
	size_t len_short = 10;
	size_t len_low_len_short = std::count_if(vec1.begin(), vec1.end(), bind(func9_22, _1, len_short));
	std::cout << "超过指定长度的字符有" << len_low_len_short << "个" << std::endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string::size_type func10_20(vector<string> vec1,const string::size_type len)
{
	auto number_over_length = std::count_if(vec1.begin(), vec1.end(),
		[len](string& str) {return str.size() > len ? true : false; });
	return number_over_length;
}

int main()
{
	vector<string> vec1 = { "1234", "123456", "1234567", "1234567", "1234567", "1234567" };
	string::size_type vec1_over_length = func10_20(vec1,6);
	std::cout << "超过指定长度的字符有" << vec1_over_length << std::endl;

	system("pause");
	return 0;
}
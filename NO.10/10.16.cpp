#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//单词剔除与排序
void elimdups(vector<string>& str1)
{
	std::sort(str1.begin(), str1.end());//进行排序
	auto new_end = std::unique(str1.begin(), str1.end());//筛选重复单词
	str1.erase(new_end, str1.end());//消除重复单词
}

void biggies(vector<string>& str1, vector<string>::size_type sz)
{
	elimdups(str1);//完成排序筛选
	std::stable_sort(str1.begin(), str1.end(),
		[](string const& lhs, string const& rhs) {
			return lhs.size() < rhs.size(); });

	auto iter = find_if(str1.begin(), str1.end(), 
		[sz](const string a) {return a.size() >= sz; });

}
int main()
{
	std::vector<std::string> vec1{ "1234", "1234", "1234", "hi~", "alan", "alan", "cp" };
	biggies(vec1, 3);
	for (const auto& i : vec1)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}
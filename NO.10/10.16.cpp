#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//�����޳�������
void elimdups(vector<string>& str1)
{
	std::sort(str1.begin(), str1.end());//��������
	auto new_end = std::unique(str1.begin(), str1.end());//ɸѡ�ظ�����
	str1.erase(new_end, str1.end());//�����ظ�����
}

void biggies(vector<string>& str1, vector<string>::size_type sz)
{
	elimdups(str1);//�������ɸѡ
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
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class string_vector
{
public:
	void delete_func();
}str_v;

void string_vector::delete_func()
{
	vector<string> vec = { "hi","po","oi","uh" };
	cout << "删除前的string数组为:" << endl;
	for (const auto& str : vec)
	{
		cout << str << " ; ";
	}
	string target;
	target = "oi";
	int j = 0;
	cout << "要进行删除的元素位于字符串的位置：" << j << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] != target)
			j++;
		else
			break;
	}
	cout << "进行删除工作：" << endl;
	auto it = vec.begin() + j;
	vec.erase(it);
	cout << "删除hi之后的字符串为：" << endl;
	for (const auto& str : vec)
	{
		cout << str << " ; ";
	}

}

int main()
{
	str_v.delete_func();
	system("pause");
	return 0;
}
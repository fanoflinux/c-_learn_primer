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
	cout << "ɾ��ǰ��string����Ϊ:" << endl;
	for (const auto& str : vec)
	{
		cout << str << " ; ";
	}
	string target;
	target = "oi";
	int j = 0;
	cout << "Ҫ����ɾ����Ԫ��λ���ַ�����λ�ã�" << j << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] != target)
			j++;
		else
			break;
	}
	cout << "����ɾ��������" << endl;
	auto it = vec.begin() + j;
	vec.erase(it);
	cout << "ɾ��hi֮����ַ���Ϊ��" << endl;
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
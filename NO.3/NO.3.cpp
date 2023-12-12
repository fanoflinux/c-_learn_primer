#include <iostream>
#include<string>
#include<vector>
using namespace std;

//迭代器的使用
void use_vec()
{
	vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vec2(10);
	vec2.clear();
	for (int i=0;i<10;++i)
	{
		vec2.push_back(i);
	}
	cout << "vex2尺寸为" << vec2.size() << endl;
	vector<int>::iterator it1;
	for (it1 = vec1.begin(); it1 != vec1.end(); it1++)
	{
		cout << *it1 << ";";
	}
	cout << endl;
	vector<int>::iterator it2;
	for (it2 = vec2.begin() ; it2 != vec2.end(); it2++)
	{
		cout << *it2 << ";";
	}
	cout << endl;
}


void read(istream& is)
{
	string str;
	while (getline(is,str))
	{
		cout << str << endl;
	}
}

int main()
{/*
	string inputstring;
	istream inputstream(cin.rdbuf());

	read(inputstream);*/
	cout << endl;
	use_vec();

	system("pause");
	return 0;
}


#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


int cla(string& str1, string& str2, char &op)
{
	int result;
	//����ӷ�
	switch (op)
	{
	case '+':
	{
		result = (stoi(str1) + stoi(str2));
		break;
	}
	case '-':
	{
		result = (stoi(str1) - stoi(str2));
		break;
	}
	case '*':
	{
		result = (stoi(str1) * stoi(str2));
		break;
	}
	case '/':
	{
		if (stoi(str2) != 0)
		{
			result = (stoi(str1) / stoi(str2));
			break;
		}
		else
		{
			result = 404;
			cout << "������0���������" << endl;
		}
		break;
	}
	default:
	{
		cout << "���ǺϷ������" << endl;
		break;
	}
	}
	return result;
}

int main()
{
	string s1 = { "(2*(3+4))" };
	stack<string> sat1;
	for (auto iter = s1.begin(); iter != s1.end();)
	{
		if (*iter = '(')
		{

		}
	}

	system("pause");
	return 0;
}
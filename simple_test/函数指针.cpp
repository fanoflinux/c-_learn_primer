#include<iostream>
#include<string>
#include<vector>

using namespace std;

//����������ָ��λһ��ָ��
void out_func()
{
	cout << "����һ������ָ�룺" << endl;
}
void (*ptr_out_func)();

int add(int a, int b)
{
	int c = a + b;
	return c;
}

int mult(int a, int b)
{
	int c = a * b;
	return c;
}
// typedef int(*mult_ptr)(int, int);


int main()
{
	typedef int(*ptr_func)(int, int);
	vector<ptr_func> vec1;
	vec1.push_back(add);
	vec1.push_back(mult);

	for (const auto& c : vec1)
	{
		cout << c(1, 2) << " ; ";
	}
	cout << endl;

	cout << "ʹ�õ����ĺ���ָ��" << endl;
	ptr_out_func = out_func;
	
	ptr_out_func;

	system("pause");
	return 0;
}
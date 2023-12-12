#include<iostream>
#include<string>

using namespace std;

//定义默认实参的函数
typedef string st;//定义类型别名
void print1(const st &s1,const st &s2,const st &s3 = "默认实参3")
{
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
int func(int&); // 第一个函数
int func(const int&); // 第二个函数

int func(int&)
{
	cout << "int &" << endl;
	return 0;
}

int func(const int&)
{
	cout << "const int &" << endl;
	return 0;
}

int func2(int*);
int func2(const int*);
int func2(int*)
{
	cout << "int *" << endl;
	return 0;
}
int func2(const int*)
{
	cout << "const int *" << endl;
	return 0;
}

int main()
{
	st s1 = "非默认实参1";
	st s2 = "非默认实参2";
	print1(s1, s2);
	st s3 = "非默认实参3";
	print1(s1,s2,s3);

	cout << "构成重载：" << endl;
	int a = 1;
	int& b = a;
	const int& c = a;
	int x = func(b);
	int y = func(c);

	const int i = 10;


	system("pause");
	return 0;
}
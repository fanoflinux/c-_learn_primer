#include<iostream>
#include<string>

using namespace std;

//����Ĭ��ʵ�εĺ���
typedef string st;//�������ͱ���
void print1(const st &s1,const st &s2,const st &s3 = "Ĭ��ʵ��3")
{
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}
int func(int&); // ��һ������
int func(const int&); // �ڶ�������

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
	st s1 = "��Ĭ��ʵ��1";
	st s2 = "��Ĭ��ʵ��2";
	print1(s1, s2);
	st s3 = "��Ĭ��ʵ��3";
	print1(s1,s2,s3);

	cout << "�������أ�" << endl;
	int a = 1;
	int& b = a;
	const int& c = a;
	int x = func(b);
	int y = func(c);

	const int i = 10;


	system("pause");
	return 0;
}
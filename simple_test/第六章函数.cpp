#include<iostream>

using namespace std;

int num()
{
	static int i = 0;
	return ++i;
}

//ָ�봫���޸�����������ֵ
void swap_num(int *a,int *b)
{
	cout << "ָ��a��ָ��Ϊ��" <<*a<< endl;
	cout << "ָ��b��ָ��Ϊ��" <<*b<< endl;
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "ָ��a��ָ��Ϊ��" << *a << endl;
	cout << "ָ��b��ָ��Ϊ��" << *b << endl;
}
//���ô����������


int main()
{
	for (int j = 0; j < 10; j++)
	{
		cout << num() << endl;
	}

	int x = 10;
	int y = 20;
	cout << "����ǰ���������ֱ�Ϊ��" <<x<<";"<<y<< endl;
	cout << "x�ĵ�ַλ���ڴ��" << &x << endl;
	cout << "y�ĵ�ַλ���ڴ��" << &y << endl;
	cout << "���н���" << endl;
	swap_num(&x, &y);
	cout << "��������������ֱ�Ϊ��" << x << ";" << y << endl;
	cout << "x�ĵ�ַλ���ڴ��" << &x << endl;
	cout << "y�ĵ�ַλ���ڴ��" << &y << endl;




	system("pause");
	return 0;
}
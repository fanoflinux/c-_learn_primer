#include<iostream>

using namespace std;

//�����������ĳ˻���ͣ������������һ�η���
void num_cl(int a,int b,int &add_result,int &mult_result)
{
	add_result = a + b;
	mult_result = a * b;
}
//ʹ���Զ�����������ͽ��д���
struct result
{
	int sum;
	int mult;
};

result num_cl2(int a,int b)
{
	result res;
	res.sum = a + b;
	res.mult = a * b;
	return res;
}

int main()
{
	//ʹ�����ý���ֵ�Ķ�η���
	int x = 10;
	int y = 5;
	int add_result;
	int	mult;
	num_cl(x, y,add_result, mult);
	cout << "�������ĺ�Ϊ" <<add_result<< endl;
	cout << "�������Ļ�Ϊ" << mult << endl;

	//ʹ���Զ�������ͽ��з���
	result res1 = num_cl2(x, y);
	cout << "�������ĺ�Ϊ:" << res1.sum << endl;
	cout << "�������Ļ�Ϊ:" << res1.mult << endl;


	system("pause");
	return 0;
}
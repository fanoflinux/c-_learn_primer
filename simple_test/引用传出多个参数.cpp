#include<iostream>

using namespace std;

//计算两个数的乘积与和，并将两个结果一次返回
void num_cl(int a,int b,int &add_result,int &mult_result)
{
	add_result = a + b;
	mult_result = a * b;
}
//使用自定义的数据类型进行处理
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
	//使用引用进行值的多次返回
	int x = 10;
	int y = 5;
	int add_result;
	int	mult;
	num_cl(x, y,add_result, mult);
	cout << "两个数的和为" <<add_result<< endl;
	cout << "两个数的积为" << mult << endl;

	//使用自定义的类型进行返回
	result res1 = num_cl2(x, y);
	cout << "两个数的和为:" << res1.sum << endl;
	cout << "两个数的积为:" << res1.mult << endl;


	system("pause");
	return 0;
}
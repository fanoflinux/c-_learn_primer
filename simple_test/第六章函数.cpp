#include<iostream>

using namespace std;

int num()
{
	static int i = 0;
	return ++i;
}

//指针传参修改两个函数的值
void swap_num(int *a,int *b)
{
	cout << "指针a的指向为：" <<*a<< endl;
	cout << "指针b的指向为：" <<*b<< endl;
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "指针a的指向为：" << *a << endl;
	cout << "指针b的指向为：" << *b << endl;
}
//引用传出多个参数


int main()
{
	for (int j = 0; j < 10; j++)
	{
		cout << num() << endl;
	}

	int x = 10;
	int y = 20;
	cout << "交换前的两个数分别为：" <<x<<";"<<y<< endl;
	cout << "x的地址位于内存的" << &x << endl;
	cout << "y的地址位于内存的" << &y << endl;
	cout << "进行交换" << endl;
	swap_num(&x, &y);
	cout << "交换后的两个数分别为：" << x << ";" << y << endl;
	cout << "x的地址位于内存的" << &x << endl;
	cout << "y的地址位于内存的" << &y << endl;




	system("pause");
	return 0;
}
#include<iostream>
#include<algorithm>

//����lambdaʽ��
auto lam_re_func(int a,int b)
{
	return [a, b]()->auto {return a + b; };
}

int main()
{
	auto lam1 = lam_re_func(4, 5);
	std::cout << lam1() << std::endl;
	system("pause");
	return 0;
}
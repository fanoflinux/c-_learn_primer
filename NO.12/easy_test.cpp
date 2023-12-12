#include<iostream>
#include<memory>

//测试一下可以内置指针与智能指针之间的转换关系
std::shared_ptr<int> bulitin_pointer_to_smart_pointer()
{
	int* bul_ptr1 = new int(10);
	std::shared_ptr<int> smt_ptr(bul_ptr1);//构造函数
	return smt_ptr;
}

//make_shared的使用方法
std::shared_ptr<int> use_of_mk_sh()
{
	int *bul_ptr0 = new int(5);
	std::shared_ptr<int> sh_ptr0 = std::make_shared<int>();
	return sh_ptr0;
}

int main()
{
	//测试转换关系的函数
	std::shared_ptr<int> sm_ptr1 = bulitin_pointer_to_smart_pointer();
	std::cout <<"测试转换关系的函数指向的值"<< * sm_ptr1 << std::endl;
	//测试make_shared使用方法
	std::shared_ptr<int> sm_ptr2 = use_of_mk_sh();
	std::cout <<"测试转换关系的函数指向的值"<< * sm_ptr2 << std::endl;
	system("pause");
	return 0;
}
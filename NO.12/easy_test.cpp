#include<iostream>
#include<memory>

//����һ�¿�������ָ��������ָ��֮���ת����ϵ
std::shared_ptr<int> bulitin_pointer_to_smart_pointer()
{
	int* bul_ptr1 = new int(10);
	std::shared_ptr<int> smt_ptr(bul_ptr1);//���캯��
	return smt_ptr;
}

//make_shared��ʹ�÷���
std::shared_ptr<int> use_of_mk_sh()
{
	int *bul_ptr0 = new int(5);
	std::shared_ptr<int> sh_ptr0 = std::make_shared<int>();
	return sh_ptr0;
}

int main()
{
	//����ת����ϵ�ĺ���
	std::shared_ptr<int> sm_ptr1 = bulitin_pointer_to_smart_pointer();
	std::cout <<"����ת����ϵ�ĺ���ָ���ֵ"<< * sm_ptr1 << std::endl;
	//����make_sharedʹ�÷���
	std::shared_ptr<int> sm_ptr2 = use_of_mk_sh();
	std::cout <<"����ת����ϵ�ĺ���ָ���ֵ"<< * sm_ptr2 << std::endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
#include<memory>

using std::vector;

//����vector����
vector<int>* func_new_vec()
{
	vector<int>* vec1 = new vector<int>;
	return vec1;
}
//��������
void func_write_vec(vector<int> *vec1)
{
	std::cout << "����Ҫ���д洢������(����-1ֹͣ���룩" << std::endl;
	int p=0;
	while (p!=-1)
	{
		std::cin >> p;
		vec1->push_back(p);
	}
}
//����������
void func_print_vec(vector<int> *vec1)
{
	std::cout << "����������" << std::endl;
	size_t len = vec1->size();
	for (auto i=vec1->begin();i<vec1->end()-1;i++)
	{
		std::cout << *i << ";";
	}
	std::cout << std::endl;
}

int main()
{
	auto vec1 = func_new_vec();
	func_write_vec(vec1);
	func_print_vec(vec1);
	delete vec1;
	system("pause");
	return 0;
}
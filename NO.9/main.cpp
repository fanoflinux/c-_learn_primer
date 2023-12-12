#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<forward_list>

//9.4
bool func9_4(std::vector<int> vec1, int find_value)
{

	std::vector<int>::iterator it1;
	it1 = vec1.begin();
	while (it1!=vec1.end())
	{
		if (*it1 != find_value)
		{
			it1++;
		}
		else
		{
			std::cout << "�ҵ���" << std::endl;
			return true;
		}
	}
	std::cout << "δ�ҵ�" << std::endl;
	return false;
}

std::vector<int>::iterator func9_5(std::vector<int> vec1, int find_value)
{
	std::vector<int>::iterator it1;
	it1 = vec1.begin();
	while (it1 != vec1.end())
	{
		if (*it1 != find_value)
		{
			it1++;
		}
		else
		{
			std::cout << "�ҵ���" << std::endl;
			return it1;
		}
	}
	std::cout << "δ�ҵ�" << std::endl;
	return it1;

}

//Ԫ�ؿ���
void copy_func01()
{
	std::vector<int> vec1 = { 1,2,3,4,5,6,7 };
	std::vector<int>::iterator vec1_b;
	vec1_b = vec1.begin() + 1;
	std::vector<int>::iterator vec1_e;
	vec1_e = vec1.end() - 1;
	std::vector<double> vec2(vec1_b,vec1_e);
	std::cout << "ԭ����Ϊ��" << std::endl;
	for (const auto& c : vec1)
	{
		std::cout << c << ";";
	}
	std::cout<<std::endl;
	std::cout << "�����������Ϊ��" << std::endl;
	for (const auto& c : vec2)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
}
//9.11
void func9_11()
{
	std::vector<int> vec1(10, 1);
	std::cout << "��1�ֳ�ʼ������" << std::endl;
	for (const auto& c : vec1)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
	std::cout << "��2�ֳ�ʼ������" << std::endl;
	std::vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (const auto& c : vec2)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
	std::cout << "��3�ֳ�ʼ������" << std::endl;
	std::vector<int> vec3 = { 1,2,3,4,5 };
	for (const auto& c : vec3)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
	std::cout << "��4�ֳ�ʼ������" << std::endl;
	std::vector<int> vec4(vec1);
	for (const auto& c : vec4)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
	std::cout << "��5�ֳ�ʼ������" << std::endl;

	std::cout << "��6�ֳ�ʼ������" << std::endl;
}

//9.13
void func9_13()
{
	std::list<int> li1 = { 1,2,3,4,5,6,7,8,9 };
	std::list<int>::iterator li1_b = li1.begin();
	std::list<int>::iterator li1_e = li1.end();
	std::vector<double> vec1(li1_b, li1_e);
	for (const auto& c : vec1)
	{
		std::cout << c << ";";
	}
	std:: cout << std::endl;
	std::vector<int> vec2{1, 2, 3, 4, 5};
	std::vector<int> vec3(vec2);
	for (const auto& c : vec3)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;

}

//9.14
void func9_14()
{
	std::list<const char*> lis1 = { "hi","no" };
	std::vector <std::string> vec1;
	vec1.assign(lis1.begin(),lis1.end());
	for (const auto& c : vec1)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
}

//9.15
bool func9_15()
{
	std::vector<int> vec1 = { 1,2,3,4,5 };
	std::vector<int> vec2 = { 1,2,3 };
	if (vec1 == vec2)
	{
		std::cout << "������������ȵ�" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "���������ǲ���ȵ�" << std::endl;
		return 0;
	}
	return 0;
}
//9.16
void func9_16()
{
	std::list<int> l1 = { 1,2,3,4,5 };
	std::vector<int> vec = { 1,2,3,4 };
	std::list<int> l2;
	l2.assign(vec.begin(), vec.end());
	if (l1 == l2)
	{
		std::cout << "������������ȵ�" << std::endl;
	}
	else
	{
		std::cout << "���������ǲ���ȵ�" << std::endl;
	}
}
//9.18
void func9_18()
{
	std::cout << "9.18_����end�������벢��ӡ" << std::endl;
	std::deque<std::string> input_dq;
	std::string str;
	while (std::cin>>str && str != "end")
	{
		input_dq.push_back(str);
	}
	std::cout << "��ʼ��ӡ" << std::endl;
	for (auto it = input_dq.begin(); it != input_dq.end(); ++it)
	{
		std::cout << *it << ";";
	}
}
//9.19
void func9_19()
{
	std::cout << "9.19_����end�������벢��ӡ" << std::endl;
	std::list<std::string> input_li1;
	std::string str1;
	while (std::cin >> str1 && str1 != "end")
	{
		input_li1.push_front(str1);
	}
	std::cout << "��ʼ��ӡ" << std::endl;
	for (auto itr = input_li1.begin(); itr != input_li1.end(); ++itr)
	{
		std::cout << *itr << ";";
	}
	std::cout << std::endl;
	/*
	std::cout << "9.19_����end��������,����ӡ��ʹ�õ������汾_ͷ��)" << std::endl;
	std::list<std::string> input_li2;
	std::string str2;
	while (std::cin>>str2&&str2!="end")
	{
		input_li2.insert(input_li2.begin(), str2);
	}
	std::cout << "��ʼ��ӡ" << std::endl;
	for (auto itr = input_li2.begin(); itr != input_li2.end(); ++itr)
	{
		std::cout << *itr << ";";
	}
	std::cout << std::endl;

	std::cout << "9.19_����end�������벢��ӡ��ʹ�õ������汾_β��)" << std::endl;
	std::list<std::string> input_li3;
	std::string str3;
	while (std::cin >> str3 && str3 != "end")
	{
		input_li3.insert(input_li3.end(), str3);
	}
	std::cout << "��ʼ��ӡ" << std::endl;
	for (auto itr = input_li3.begin(); itr != input_li3.end(); ++itr)
	{
		std::cout << *itr << ";";
	}
	std::cout << std::endl;
	*/
}

//9.20
void func9_20()
{
	std::list<int> list1 = { 1,2,3,4,5,6,7,8,9 };
	std::deque<int> d1;
	std::deque<int> d2;
	for (auto itr = list1.begin(); itr != list1.end(); ++itr)
	{
		(*itr % 2 == 0 ? d1 : d2).push_back(*itr);
	}
	std::cout << "���ż����" << std::endl;
	for (auto c : d1)
	{
		std::cout << c << ";";
	}
	std::cout << std::endl;
	std::cout << "���������" << std::endl;
	for (auto c : d2)
	{
		std::cout << c << ";";
	}

}
//emplace_test
void emplace_test()
{
	//����һ���Լ�����
	class A
	{
	public:
		A() = default;
		A(const int x, const int y) :a(x), b(y)
		{
			std::cout << "A�е�XԪ��Ϊ��" << x << std::endl;
			std::cout << "A�е�YԪ��Ϊ��" << y << std::endl;
		}
	private:
		int a;
		int b;
	};
	//�������з�����ص�ֵ
	std::vector<A> vec1;
	vec1.emplace_back(1, 3);
	vec1.emplace_back(2, 4);
	std::cout <<  std::endl;
}
//��ϰ9.24
void func9_24()
{
	std::vector<int> vec1{1,2,3,4};
	std::cout << "ʹ��at�����" << std::endl;
	if (vec1.size() != 0)
	{
		std::cout <<"��Ԫ�أ�" << vec1.at(0);
		std::cout << std::endl;
	}
	std::cout << "ʹ���±������" << std::endl;
	if (vec1.size() != 0)
	{
		std::cout << "��Ԫ�أ�" << vec1[0];
		std::cout << std::endl;
	}
	std::cout << "ʹ��front�����" << std::endl;
	if (vec1.size() != 0)
	{
		std::cout << "��Ԫ�أ�" << vec1.front();
		std::cout << std::endl;
	}
	std::cout << "ʹ��begin�����" << std::endl;
	if (vec1.size() != 0)
	{
		std::cout << "��Ԫ�أ�" << (*vec1.begin());
		std::cout << std::endl;
	}

}

//��ϰ9.26
void func9_26()
{
	int ia[] = { 0,1,2,3,4,5,8,13,21,55,89 };
	std::vector<int> vec1(std::begin(ia),std::end(ia));
	std::list<int> lis1(std::begin(ia), std::end(ia));
	/*for (const auto c : ia)
	{
		vec1.push_back(c);
		lis1.push_back(c);
	}*/
	//ɾ������Ԫ��
	std::cout << "ɾ������Ԫ��" << std::endl;
	std::list<int>::iterator iter_list;
	iter_list = lis1.begin();
	while(iter_list!=lis1.end())
	{
		if ((*iter_list) % 2 != 0)
		{
			iter_list = lis1.erase(iter_list);
		}
		else
			++iter_list;
	}
	for (const auto &i : lis1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;
	//ɾ������Ԫ�أ�
	std::cout << "ɾ��ż��Ԫ��" << std:: endl;
	std::vector<int>::iterator iter_vec;
	iter_vec = vec1.begin();
	while (iter_vec != vec1.end())
	{
		if ((*iter_vec) % 2 == 0)
		{
			iter_vec = vec1.erase(iter_vec);
		}
		else
			++iter_vec;
	}
	for (const auto &i : vec1)
	{
		std::cout << i << ";";
	}
	std::cout << std::endl;

}
//9.27
void func9_27()
{
	std::forward_list<int> for1 = { 1,2,3,4,5,6,7,8,9 };
	auto iter_befor = for1.before_begin();
	std::forward_list<int>::iterator iter_curr = for1.begin();
	while (iter_curr!=for1.end())
	{
		if ((*iter_curr) % 2 != 0) 
		{
			iter_curr = for1.erase_after(iter_befor);
		}
		else
		{
			iter_befor = iter_curr;
			iter_curr++;
		}
	}
	std::cout << "ʣ�µ�ż��Ԫ��Ϊ:" << std::endl;
	for (const auto& i : for1)
	{
		std::cout << i << ";";
	}
}


int main()
{
	/*
	std::vector<int> vec01{1, 2, 3, 4, 5};
	int find = 4;
	bool result = func9_4(vec01, find);
	std::cout << std::endl;
	std::vector<int>::iterator it01 = func9_5(vec01, find);

	copy_func01();

	std::cout << "��ϰ9.13" << std::endl;
	func9_13();
	std::cout << "��ϰ9.15" << std::endl;
	func9_14();
	std::cout << std::endl;
	std::cout << "��ϰ9.16" << std::endl;
	func9_16();
	std::cout << std::endl;
	
	std::cout << "��ϰ9.18" << std::endl;
	func9_18();
	std::cout << std::endl;
	std::cout << "��ϰ9.19" << std::endl;
	func9_19();
	std::cout << std::endl;
	
	std::cout << "��ϰ9.20" << std::endl;
	func9_20();
	std::cout << std::endl;

	std::cout << "emplace��ʹ�ã�" << std::endl;
	emplace_test();
	std::cout << std::endl;

	std::cout << "��ϰ9.24" << std::endl;
	func9_24();
	std::cout << std::endl;
	*/
	std::cout << "��ϰ9.26" << std::endl;
	func9_26();
	std::cout << std::endl;

	std::cout << "��ϰ9.27" << std::endl;
	func9_27();
	std::cout << std::endl;
	system("pause");
	return 0;
}
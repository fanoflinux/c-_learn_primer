#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<initializer_list>//�ɱ��β�
using namespace std;



//�ж��Ƿ���ڴ�д��ĸ
bool hasUpperCase(const string& str)
{
	for (const auto c : str)
	{
		if (isupper(c))
		{
			return 1;
		}
	}
	return 0;
}
//����д��ĸ��дΪСд��ĸ
void toLowCase(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}
//�ܷ�const int[]ֱ�Ӹ�ֵ��int����
void print(const int[10])
{
	cout << "���Ը�ֵ" << endl;
}
//��intָ���int���͵�ֵ��С
int int_copm(const int*ptr, int p)
{
	int tmp;
	if (*ptr > p)
	{
		tmp = *ptr;
		return tmp;
	}
	else
	{
		tmp = p;
		return tmp;
	}
}
//��������ָ��
void ex_ptr(int* ptr1, int* ptr2)
{
	cout << "����ǰ��һ��ָ��Ϊ" << *ptr1 << endl;
	cout << "����ǰ�ڶ���ָ��Ϊ" << *ptr2 << endl;
	cout << "����ǰ��һ��ָ��ָ���ַΪ" << ptr1 << endl;
	cout << "����ǰ�ڶ���ָ��ָ���ַΪ" << ptr2 << endl;
	int* ptr_temp = ptr1;
	ptr1 = ptr2;
	ptr2 = ptr_temp;
	cout << "�������һ��ָ��Ϊ" << *ptr1 << endl;
	cout << "������ڶ���ָ��Ϊ" << *ptr2 << endl;
	cout << "�������һ��ָ��ָ���ַΪ" << ptr1 << endl;
	cout << "������ڶ���ָ��ָ���ַΪ" << ptr2 << endl;

}
//���пɱ��βεĺ���
void init_list(initializer_list<string> str)
{
	for (const auto& c : str)
	{
		cout << c << ";";
	}
}
//����������ֵ�ĺ�
int sum_init(initializer_list<int> list)
{
	int sum = 0;
	for (int val :list)
	{
		sum += val;
	}
	return sum;
}
//��дһ���ݹ麯�����vector������
void out_vector(const vector<int> &vec, size_t index)
{
	
	if (index >= vec.size())
	{
		return;
	}
	cout << vec[index] << " ; ";
	out_vector(vec, index + 1);
}
//ʹ��β�����ͷ�������
auto tail_func() -> int(*)[5]
{
	static int arr1[5] = { 1,2,3,4,5 };
	return &arr1;
}
//&�����ã�
int test01()
{
	int a = 10;
	return a;
}
//����5��string�������������
string(&(str_retu_func()))[5]
{
	static string arr[5] = { "a","s","d","f","g" };
	return arr;
}

int main()
{
	int funtion_choice;
	cout << "����ѡ��" << endl;
	cout << "1-�ַ�����Сд" << endl;
	cout << "2-ָ���Сд�Ƚ�" << endl;
	cout << "3-����ָ��" << endl;
	cout << "4-���пɱ��βεĺ���" << endl;
	cout << "5-���������int���͵�ֵ" << endl;
	cout << "6-��ӡvector���ֵ" << endl;
	cout << "7-β�����ͷ�������" << endl;
	cout << "8-&������" << endl;
	cout << "9-����string����" << endl;

	cin >> funtion_choice;
	switch (funtion_choice)
	{case 1:
	{
		string str1;
		cout << "�������ַ��������ж�" << endl;
		cin >> str1;
		if (bool judge = hasUpperCase(str1) == 1)
		{
			cout << "�ַ����д��ڴ�д��ĸ���������еĴ�д��ĸ����ת��" << endl;
			toLowCase(str1);
			cout << "ת������ַ���Ϊ��" << endl;
			cout << str1 << endl;
		}
		else
		{
			cout << "�ַ����в����ڴ�д��ĸ" << endl;
		}
		break;
	}
	case 2:
	{
		int x, y;
		cout << "�����һ��ֵ";
		cin >> x;
		cout << "����ڶ���ֵ";
		cin >> y;
		int* ptr_y = &y;
		int temp = int_copm(ptr_y, x);
		cout << "�ϴ��ֵΪ" << temp << endl;
		break;
	}
	case 3:
	{
		int a = 1;
		int b = 2;
		int temp = 0;
		int* ptr1 = &a;
		int *ptr2 = &b;
		ex_ptr(ptr1, ptr2);
		break;
	}
	case 4:
	{
		cout << "��һ��ʹ��init" << endl;
		init_list({ "uiiuy", "sssaf" });
		cout << endl;
		cout << "�ڶ���ʹ��init";
		init_list({ "uaiywiur","auiyhoredy" ,"quwyeruwbxmcnb"});
		break;
	}
	case 5:
	{
		initializer_list<int> list1 = { 1,2,3,4,5,6,7,8 };
		int sum = sum_init(list1);
		cout << "����Ľ��Ϊ��" << sum << endl;
		break;
	}
	case 6:
	{
		vector<int> vec = {1,2,3,4,5,6};
		out_vector(vec,0);
		break;
	}
	case 7:
	{
		int (*arr)[5] = tail_func();
		break;
	}
	case 9:
	{
		string(&arr)[5] = str_retu_func();
		for (const auto& str : arr)
		{
			cout << str << " ; ";
		}
		break;

	}
	default:
		break;
	}
	
	
	int j = 10;
	print(&j);

	system("pause");
	return 0;
}

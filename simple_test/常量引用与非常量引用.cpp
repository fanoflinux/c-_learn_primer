#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<initializer_list>//可变形参
using namespace std;



//判断是否存在大写字母
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
//将大写字母改写为小写字母
void toLowCase(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}
//能否将const int[]直接赋值是int类型
void print(const int[10])
{
	cout << "可以赋值" << endl;
}
//比int指针和int类型的值大小
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
//交换两个指针
void ex_ptr(int* ptr1, int* ptr2)
{
	cout << "交换前第一个指针为" << *ptr1 << endl;
	cout << "交换前第二个指针为" << *ptr2 << endl;
	cout << "交换前第一个指针指向地址为" << ptr1 << endl;
	cout << "交换前第二个指针指向地址为" << ptr2 << endl;
	int* ptr_temp = ptr1;
	ptr1 = ptr2;
	ptr2 = ptr_temp;
	cout << "交换后第一个指针为" << *ptr1 << endl;
	cout << "交换后第二个指针为" << *ptr2 << endl;
	cout << "交换后第一个指针指向地址为" << ptr1 << endl;
	cout << "交换后第二个指针指向地址为" << ptr2 << endl;

}
//含有可变形参的函数
void init_list(initializer_list<string> str)
{
	for (const auto& c : str)
	{
		cout << c << ";";
	}
}
//计算任意多个值的和
int sum_init(initializer_list<int> list)
{
	int sum = 0;
	for (int val :list)
	{
		sum += val;
	}
	return sum;
}
//编写一个递归函数输出vector的内容
void out_vector(const vector<int> &vec, size_t index)
{
	
	if (index >= vec.size())
	{
		return;
	}
	cout << vec[index] << " ; ";
	out_vector(vec, index + 1);
}
//使用尾置类型返回数组
auto tail_func() -> int(*)[5]
{
	static int arr1[5] = { 1,2,3,4,5 };
	return &arr1;
}
//&的作用：
int test01()
{
	int a = 10;
	return a;
}
//返回5个string对象的引用数组
string(&(str_retu_func()))[5]
{
	static string arr[5] = { "a","s","d","f","g" };
	return arr;
}

int main()
{
	int funtion_choice;
	cout << "功能选择" << endl;
	cout << "1-字符串大小写" << endl;
	cout << "2-指针大小写比较" << endl;
	cout << "3-交换指针" << endl;
	cout << "4-含有可变形参的函数" << endl;
	cout << "5-计算任意多int类型的值" << endl;
	cout << "6-打印vector相关值" << endl;
	cout << "7-尾置类型返回数组" << endl;
	cout << "8-&的作用" << endl;
	cout << "9-返回string数组" << endl;

	cin >> funtion_choice;
	switch (funtion_choice)
	{case 1:
	{
		string str1;
		cout << "请输入字符串进行判断" << endl;
		cin >> str1;
		if (bool judge = hasUpperCase(str1) == 1)
		{
			cout << "字符串中存在大写字母，将对其中的大写字母进行转换" << endl;
			toLowCase(str1);
			cout << "转换后的字符串为：" << endl;
			cout << str1 << endl;
		}
		else
		{
			cout << "字符串中不存在大写字母" << endl;
		}
		break;
	}
	case 2:
	{
		int x, y;
		cout << "输入第一个值";
		cin >> x;
		cout << "输入第二个值";
		cin >> y;
		int* ptr_y = &y;
		int temp = int_copm(ptr_y, x);
		cout << "较大的值为" << temp << endl;
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
		cout << "第一次使用init" << endl;
		init_list({ "uiiuy", "sssaf" });
		cout << endl;
		cout << "第二次使用init";
		init_list({ "uaiywiur","auiyhoredy" ,"quwyeruwbxmcnb"});
		break;
	}
	case 5:
	{
		initializer_list<int> list1 = { 1,2,3,4,5,6,7,8 };
		int sum = sum_init(list1);
		cout << "计算的结果为：" << sum << endl;
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

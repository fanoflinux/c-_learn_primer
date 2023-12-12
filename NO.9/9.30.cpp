#include<list>
#include<iostream>
#include<forward_list>


void func9_30()
{
	std::list<int> lis1 = { 1,2,3,4,5,6,7,8,9,10 };
	auto iter = lis1.begin();
	while (iter != lis1.end())
	{
		if ((*iter) % 2 != 0)
		{
			
			iter = lis1.insert(iter, *iter);
			iter++; 
			iter++;
		}
		else
		{
			iter = lis1.erase(iter);
		}
	}
	std::cout << "对奇数元素进行复制操作：" << std::endl;
	for (const auto& i : lis1)
	{
		std::cout << i << ";";
	}
}

void func9_30_for()
{
	std::forward_list<int> f1 = { 1,17,3,4,5,6,7,8,9,10 };
	auto curr = f1.begin();
	auto pre = f1.before_begin();
	while (curr != f1.end())
	{
		if ((*curr) % 2 != 0)
		{
			curr = f1.insert_after(curr, *curr++);
			pre = curr;
			curr++;
		}
		else
		{
			curr = f1.erase_after(pre);
		}
	}
	std::cout << "对奇数元素进行复制操作：" << std::endl;
	for (const auto& i : f1)
	{
		std::cout << i << ";";
	}
}

int main()
{
	std::cout << "练习9.30-list.version" << std::endl;
	func9_30();
	std::cout << std::endl;
	std::cout << "练习9.30-forward_list.version" << std::endl;
	func9_30_for();

	system("pause");
	return 0;
}
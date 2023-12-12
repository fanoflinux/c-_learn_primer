/*
* 通过一个简单的共享指针的实现
* 完成一个对于类作为指针的理解
*/
#include<iostream>
#include<string>

using std::string;

class SHARED
{
public:
	//写一个构造函数
	SHARED(const string res)
		:resourece (new string(res))
	{
		std::cout << "using this memory is " << *(this->resourece) << std::endl;
		this->count = new size_t(1);
	}
	//写一个复制构造函数
	SHARED(const SHARED& copy)
	{
		this->resourece = copy.resourece;
		this->count = copy.count;
		*(this->count) += 1;//进行这块内存的加一操作
		std::cout << *(copy.resourece) << "construct memory is " << copy.resourece << std::endl;
		std::cout << *(this->resourece) << "copy construct memory is " << this->resourece << std::endl;
		std::cout << "using this memory count is" << *(this->count) << std::endl;
	}
	SHARED& operator=(const SHARED& copy)
	{
		this->resourece = copy.resourece;
		this->count = copy.count;
		*(this->count) += 1;//进行这块内存的加一操作
		std::cout << "using this memory count is" << *(this->count) << std::endl;
	}
	//析构函数
	~SHARED()
	{
		*(this->count) -= 1;
		//判断共享计数是否为0
		if (*(this->count ) == 0)
		{
			std::cout << "using this memory count is 0" << std:: endl;
			delete this->count;
			delete this->resourece;
		}
	}
public:
	string* resourece;
	size_t* count;
};

class UNIQUE
{
public:
	UNIQUE(const string& unique_res)
		:resourece(new string(unique_res))
	{
		this->count = new size_t(1);
		std::cout << "using this memory is " << *(this->resourece) << std::endl;
		std::cout << "using this memory count is " << *(this->count) << std::endl;
	}
	//拷贝构造函数
	UNIQUE(const UNIQUE& unique_copy)
	{
		//赋值再释放
		this->resourece = new string(*(unique_copy.resourece));
		std::cout<<*(unique_copy.resourece) << "construct memory is " << unique_copy.resourece << std::endl;
		std::cout<<*(this->resourece)<< "copy construct memory is " << this->resourece << std::endl;
		//delete unique_copy.resourece;
		this->count = new size_t(*(unique_copy.count));
		//delete unique_copy.count;
		std::cout << "using this memory is " << *(this->resourece) << std::endl;
		std::cout << "using this memory count is " << *(this->count) << std::endl;
	}
	UNIQUE& operator=(const UNIQUE& unique_copy)
	{
		this->resourece = new string(*(unique_copy.resourece));
		//delete unique_copy.resourece;
		this->count = new size_t(*(unique_copy.count));
		//delete unique_copy.count;
		std::cout << "using this memory is " << *(this->resourece) << std::endl;
		std::cout << "using this memory count is " << *(this->count) << std::endl;
	}
	~UNIQUE()
	{
		delete this->count;
		delete this->resourece;
	}
	string* resourece;
	size_t* count;
};

int main()
{
	std::cout << "the shared_ptr block" << std::endl;
	SHARED sh01("use1");
	SHARED sh02(sh01);
	SHARED sh03(sh02);
	SHARED sh04(sh03);
	std::cout << "how many people point this memory (sh02)" << *(sh02.count) << std::endl;

	std::cout << "the unique_ptr block" << std::endl;
	UNIQUE un01("unique_use1");
	UNIQUE un02(un01);
	
	std::cout << "how many people point this memory (sh02):" << *(un02.resourece) << std::endl;
	std::cout << "how many people point this memory (sh02):" << *(un02.count) << std::endl;

	system("pause");
	return 0;
}
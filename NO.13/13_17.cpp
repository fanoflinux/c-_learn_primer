#include<iostream>

class numbered
{
	friend void func13_17(const numbered& obj);
public:
	//���캯��
	numbered(const int& data_num)
	{
		num = new int(data_num);
		std::cout << "���" << *num << std::endl;
	}
	//���ƿ���
	numbered(const numbered& copy_num)
	{
		//this->num = copy_num.num + 1;
		this->num = new int (*(copy_num.num)+1) ;
	}
	numbered& operator=(const numbered& copy_num)
	{
		if (this != &copy_num)
		{
			delete num;
			//num = nullptr;
			this->num = new int(*(copy_num.num) + 10);
		}
		return *this;
	}
	~numbered()
	{
		delete num;
	}

private:
	int *num;
};

void func13_17(const numbered& obj)
{
	std::cout << "obj1�ı��" << *(obj.num) << std::endl;
}

int main()
{
	numbered obj1(10);
	func13_17(obj1);
	numbered obj3 = obj1;
	func13_17(obj3);

	system("pause");
	return 0;
}
#include<iostream>
#include<string>

using std::string;

class Empolyee
{
public:
	Empolyee()
	{
		emp_true_id = emp_id++;
	}
	Empolyee(const string name)
	{
		this->emp_name = name;
		this->emp_true_id = emp_id++;
		std::cout << "��Ա����Ϊ:" << name << std::endl;
		std::cout << "��ԱԱ�����Ϊ:" << emp_true_id << std::endl;
	}
	Empolyee(const Empolyee&) = delete;
	Empolyee& operator=(const Empolyee&) = delete;
	const int id() const
	{
		return emp_true_id;
	}

private:
	static int emp_id;
	string emp_name;
	int emp_true_id;
};
//Ա�����
int Empolyee::emp_id = 101011;

int main()
{
	//��ʼ��һ��Ա��
	Empolyee em01("lingo");

	system("pause");
	return 0;
}
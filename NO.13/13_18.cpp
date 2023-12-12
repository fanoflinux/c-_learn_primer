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
		std::cout << "雇员名字为:" << name << std::endl;
		std::cout << "雇员员工编号为:" << emp_true_id << std::endl;
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
//员工编号
int Empolyee::emp_id = 101011;

int main()
{
	//初始化一个员工
	Empolyee em01("lingo");

	system("pause");
	return 0;
}
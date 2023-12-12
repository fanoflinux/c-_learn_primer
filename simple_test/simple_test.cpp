#include<iostream>
using namespace std;

class Person 
{
public:
	virtual void out_fun();
	int person_age = 27;
private:
	int age;
};

class Child:virtual public Person
{
public:
	virtual void out_fun();
	int child_age = 10;
private:
	int age;
};

void Person::out_fun()
{
	cout << "成人票价" << endl;
	age = 25;
	cout << "成人年纪为" <<age<< endl;
}

void Child::out_fun()
{
	cout << "儿童票价" << endl;
	age = 8;
	cout << "儿童年纪为" << age << endl;
}

int main()
{
	/*Person p;
	Child c;

	cout << "继承状态以及是否完成切片活动" << endl;
	cout <<"是否可以继承父类中的person_age:" << c.person_age << endl;
	cout << endl;


	cout << "使用实例化进行调用虚函数的内容" << endl;
	p.out_fun();
	c.out_fun();
	cout << endl;

	cout << "使用指针的方式进行虚函数内容的调用" << endl;
	Person* p2 = new Person;
	Child* c2 = new Child;
	c2->out_fun();
	p2->out_fun();
	delete p2;
	delete c2;
	cout << endl;

	cout << "使用引用的方式进行虚函数内容的调用" << endl;
	Child c3;
	Child& c4 = c3;
	c4.out_fun();
	cout << endl;*/

	/*Person Mike;
	Child Mike_son;
	Mike_son.person_age=14;
	Person* Mike_ptr = &Mike;
	Person* Mike_son_ptr = &Mike_son;
	Child* Child_Mike_ptr = &Mike_son;
	cout << "对child类继承的person_age进行修改，修改后为：" <<Mike_son_ptr->person_age << endl;
	Mike_ptr->out_fun();
	Mike_son_ptr->out_fun();
	Child_Mike_ptr->out_fun();
	cout << "可以使用Person类型的指针区访问非切片部分的内容吗" << endl;
	cout << Child_Mike_ptr->child_age;
	cout << endl;*/

	Child Jake;
	Person p = Jake;
	p.out_fun();

	system("pause");
	return 0;

}
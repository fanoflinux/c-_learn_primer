#ifndef MSG

#include<iostream>
#include<set>

class Floder;

class Message
{
	friend void swap(Message&, Message&);
	friend void swap(Floder&, Floder&);
	friend class Floder;

	//定义成员函数
public:
	explicit Message(std::string& s)
		:contents(s) {}//默认构造
	Message(const Message&);//复制构造
	Message& operator=(const Message&);//赋值构造
	~Message();//析构
	void save(Floder&);
	void remove(Floder&);
	void print_debug();

private:
	std::string contents;//信息内容
	std::set<Floder*> folders;//文件成员

	void add_to_floders(const Message&);//向文件中添加成员
	void remove_from_folders();//从文件中移除对象

	void addFldr(Floder* f)//向目标文件夹中添加message
	{
		folders.insert(f);
	}
	void remFldr(Floder* f)//从message中移除目标文件夹
	{
		folders.erase(f);
	}

};

class Floder
{
	friend void swap(Message&, Message&);
	friend void swap(Floder&, Floder&);
	friend class Message;
public:
	Floder() = default;
	Floder(const Floder&);
	Floder& operator=(const Floder&);
	~Floder();
	void print_debug();

private:
	std::set<Message*> msgs;

	void add_to_Message(const Floder&);
	void remove_to_Message();

	void addMsg(Message* m)
	{
		msgs.insert(m);
	}
	void remMsg(Message* m)
	{
		msgs.erase(m);
	}

};


#endif // !MSG&FLO
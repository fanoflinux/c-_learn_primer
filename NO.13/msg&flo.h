#ifndef MSG

#include<iostream>
#include<set>

class Floder;

class Message
{
	friend void swap(Message&, Message&);
	friend void swap(Floder&, Floder&);
	friend class Floder;

	//�����Ա����
public:
	explicit Message(std::string& s)
		:contents(s) {}//Ĭ�Ϲ���
	Message(const Message&);//���ƹ���
	Message& operator=(const Message&);//��ֵ����
	~Message();//����
	void save(Floder&);
	void remove(Floder&);
	void print_debug();

private:
	std::string contents;//��Ϣ����
	std::set<Floder*> folders;//�ļ���Ա

	void add_to_floders(const Message&);//���ļ�����ӳ�Ա
	void remove_from_folders();//���ļ����Ƴ�����

	void addFldr(Floder* f)//��Ŀ���ļ��������message
	{
		folders.insert(f);
	}
	void remFldr(Floder* f)//��message���Ƴ�Ŀ���ļ���
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
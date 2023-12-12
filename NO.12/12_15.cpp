#include<iostream>
#include<memory>
#include<string>

//����������
struct connection
{
public:
	std::string user_ip;//�����û���IP��ַ
	int port;//�����û�����ض˿�
	connection(std::string i, int p) :user_ip(i), port(p) {}
};
//����Ŀ��������
struct destination
{
public:
	destination(std::string i, int p) :user_ip(i), port(p) {}
	std::string user_ip;
	int port;
};
//����������ص�����,����Ŀ��˿�
connection connect(destination* ptr_dest)
{
	//std::shared_ptr<connection> pConn = std::make_shared<connection>(new connection(ptr_dest->user_ip, ptr_dest->port));
	std::shared_ptr<connection> pConn = std::make_shared<connection>(ptr_dest->user_ip, ptr_dest->port);
	//std::shared_ptr<connection> pConn(new connection(ptr_dest->user_ip, ptr_dest->port));
	std::cout << "����������(" << pConn.use_count() << ")" << std::endl;
	return *pConn;
}
//�Ͽ��������
void disconnect(connection pConn)
{
	std::cout << "�ر�������ӣ�(" << pConn.user_ip << ":" << pConn.port << ")" << std::endl;
}
//�Ͽ����ӣ����Լ������delete�ͷ�������ݵĺ���

//������ص�����
void func12_14(destination& d)
{
	//��Ŀ��˿ڽ������Ӵ���
	connection conn = connect(&d);
	std::shared_ptr<connection> conn_ptr(&conn, [](connection* pConn) {disconnect(*pConn); });
	std::cout << "������������˿ڵ��û���" << conn_ptr.use_count() << "��" << std::endl;
}
int main()
{
	//����Ŀ��˿�
	destination dest("220.181.111.111", 10086);
	func12_14(dest);

	system("pause");
	return 0;
}
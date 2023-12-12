#include<iostream>
#include<memory>
#include<string>

//定义连接类
struct connection
{
public:
	std::string user_ip;//定义用户的IP地址
	int port;//定义用户的相关端口
	connection(std::string i, int p) :user_ip(i), port(p) {}
};
//定义目标连接类
struct destination
{
public:
	destination(std::string i, int p) :user_ip(i), port(p) {}
	std::string user_ip;
	int port;
};
//定义连接相关的内容,传入目标端口
connection connect(destination* ptr_dest)
{
	//std::shared_ptr<connection> pConn = std::make_shared<connection>(new connection(ptr_dest->user_ip, ptr_dest->port));
	std::shared_ptr<connection> pConn = std::make_shared<connection>(ptr_dest->user_ip, ptr_dest->port);
	//std::shared_ptr<connection> pConn(new connection(ptr_dest->user_ip, ptr_dest->port));
	std::cout << "创建的连接(" << pConn.use_count() << ")" << std::endl;
	return *pConn;
}
//断开相关连接
void disconnect(connection pConn)
{
	std::cout << "关闭相关连接：(" << pConn.user_ip << ":" << pConn.port << ")" << std::endl;
}
//断开连接，即自己定义的delete释放相关内容的函数

//启动相关的连接
void func12_14(destination& d)
{
	//对目标端口进行连接处理
	connection conn = connect(&d);
	std::shared_ptr<connection> conn_ptr(&conn, [](connection* pConn) {disconnect(*pConn); });
	std::cout << "现在连接这个端口的用户有" << conn_ptr.use_count() << "个" << std::endl;
}
int main()
{
	//创建目标端口
	destination dest("220.181.111.111", 10086);
	func12_14(dest);

	system("pause");
	return 0;
}
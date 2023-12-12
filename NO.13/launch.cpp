#include"msg&flo.h"

/*--------block of swap--------*/
//信息交换
void swap(Message& lmsg, Message& rmsg)
{
	using std::swap;
	//移除
	for (auto f : lmsg.folders)
		f->remMsg(&lmsg);
	for (auto f : rmsg.folders)
		f->remMsg(&rmsg);
	//交换
	swap(lmsg.folders, rmsg.folders);
	swap(lmsg.contents, rmsg.contents);
	//添加
	for (auto f : lmsg.folders)
		f->addMsg(&lmsg);
	for (auto f : rmsg.folders)
		f->addMsg(&rmsg);
}
//文件交换
void swap(Floder& lfo, Floder& rfo)
{
	using std::swap;
	//移除
	for (auto m : lfo.msgs)
		m->remFldr(&lfo);
	for (auto m : rfo.msgs)
		m->remFldr(&rfo);
	//交换
	swap(lfo.msgs, rfo.msgs);
	//添加
	for (auto m : lfo.msgs)
		m->addFldr(&lfo);
	for (auto m : rfo.msgs)
		m->addFldr(&rfo);
}
/*--------block of message--------*/
//复制构造
Message::Message(const Message& original_msg)
	:contents(original_msg.contents), folders(original_msg.folders)
{
	add_to_floders(original_msg);
}
Message& Message::operator=(const Message& original_msg)
{
	remove_from_folders();
	this->contents = original_msg.contents;
	this->folders = original_msg.folders;
	add_to_floders(original_msg);
	return *this;
}
Message::~Message()
{
	remove_from_folders();
}
void Message::save(Floder& f)
{
	/*添加关系是相互的，既要在文件夹中指明添加这个message
	又要在message成员的folders这个集合中表明这个message成员中有这个文件夹的记录关系*/
	this->folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Floder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}
void Message::add_to_floders(const Message& msg)
{
	for (auto f : folders)
		f->addMsg(this);
}
void Message::remove_from_folders()
{
	//从文件成员中将Message移除
	for (auto f : folders)
		f->remMsg(this);
	folders.clear();
}
void Message::print_debug()
{
	std::cout << contents << std::endl;
}
/*--------block of folder--------*/
Floder::Floder(const Floder& original_fol)
	:msgs(original_fol.msgs)
{
	add_to_Message(original_fol);
}
Floder& Floder::operator=(const Floder& original_fol)
{
	remove_to_Message();
	this->msgs = original_fol.msgs;
	add_to_Message(original_fol);
	return *this;
}
Floder::~Floder()
{
	remove_to_Message();
}
void Floder::add_to_Message(const Floder& flo)
{
	for (auto m : flo.msgs)
		m->addFldr(this);
}

void Floder::remove_to_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
	msgs.clear();
}
void Floder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

int main() {
	// 创建消息和文件夹
	std::string str1 = { "消息1" };
	std::string str2 = { "消息2" };
	Message msg1(str1);
	Message msg2(str2);
	Floder folder1;
	Floder folder2;

	// 将消息保存到文件夹
	msg1.save(folder1);
	msg2.save(folder2);

	// 打印交换前的调试信息
	std::cout << "交换前：\n";
	std::cout << "文件夹1: ";
	folder1.print_debug();
	std::cout << "文件夹2: ";
	folder2.print_debug();

	// 执行交换操作
	swap(folder1, folder2);

	// 打印交换后的调试信息
	std::cout << "\n交换后：\n";
	std::cout << "文件夹1: ";
	folder1.print_debug();
	std::cout << "文件夹2: ";
	folder2.print_debug();

	system("pause");
	return 0;
}

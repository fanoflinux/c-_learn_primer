#include"msg&flo.h"

/*--------block of swap--------*/
//��Ϣ����
void swap(Message& lmsg, Message& rmsg)
{
	using std::swap;
	//�Ƴ�
	for (auto f : lmsg.folders)
		f->remMsg(&lmsg);
	for (auto f : rmsg.folders)
		f->remMsg(&rmsg);
	//����
	swap(lmsg.folders, rmsg.folders);
	swap(lmsg.contents, rmsg.contents);
	//���
	for (auto f : lmsg.folders)
		f->addMsg(&lmsg);
	for (auto f : rmsg.folders)
		f->addMsg(&rmsg);
}
//�ļ�����
void swap(Floder& lfo, Floder& rfo)
{
	using std::swap;
	//�Ƴ�
	for (auto m : lfo.msgs)
		m->remFldr(&lfo);
	for (auto m : rfo.msgs)
		m->remFldr(&rfo);
	//����
	swap(lfo.msgs, rfo.msgs);
	//���
	for (auto m : lfo.msgs)
		m->addFldr(&lfo);
	for (auto m : rfo.msgs)
		m->addFldr(&rfo);
}
/*--------block of message--------*/
//���ƹ���
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
	/*��ӹ�ϵ���໥�ģ���Ҫ���ļ�����ָ��������message
	��Ҫ��message��Ա��folders��������б������message��Ա��������ļ��еļ�¼��ϵ*/
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
	//���ļ���Ա�н�Message�Ƴ�
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
	// ������Ϣ���ļ���
	std::string str1 = { "��Ϣ1" };
	std::string str2 = { "��Ϣ2" };
	Message msg1(str1);
	Message msg2(str2);
	Floder folder1;
	Floder folder2;

	// ����Ϣ���浽�ļ���
	msg1.save(folder1);
	msg2.save(folder2);

	// ��ӡ����ǰ�ĵ�����Ϣ
	std::cout << "����ǰ��\n";
	std::cout << "�ļ���1: ";
	folder1.print_debug();
	std::cout << "�ļ���2: ";
	folder2.print_debug();

	// ִ�н�������
	swap(folder1, folder2);

	// ��ӡ������ĵ�����Ϣ
	std::cout << "\n������\n";
	std::cout << "�ļ���1: ";
	folder1.print_debug();
	std::cout << "�ļ���2: ";
	folder2.print_debug();

	system("pause");
	return 0;
}

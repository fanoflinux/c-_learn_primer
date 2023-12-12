#pragma once
#ifndef SCREEN
#define SCREEN
#include<iostream>
#include<string>
#include<vector>

class Screen;
//���ڹ�����
class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

//������
class Screen
{
	//������Ԫ
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;

	//���幹�캯��
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd) ,contents(ht*wd,' ') {};
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {};

	//��ȡ������������
	//��ȡ�������Ŀ�͸�
	char get() const { return contents[cursor]; };
	char get(pos r, pos c)const { return contents[r * width + c]; };

	//��ʾ���ڵĺ���
	//������display����
	const Screen& display(std::ostream& os)const
	{
		do_display(os);
		return *this;
	}
	//�ǳ�����display����
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	//�ƶ�����
	inline Screen& move(pos r, pos c);
	//����ҳ��ĺ���
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

private:
	//����do_display����
	void do_display(std::ostream& os)const { os << contents; };
private:
	//������ر����������һ��ʼ���߽�����λ��
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	std::string contents;
};


inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline  Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}
//���ڹ������е�������
inline void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif // !SCREEN

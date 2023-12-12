#pragma once
#ifndef SCREEN
#define SCREEN
#include<iostream>
#include<string>
#include<vector>

class Screen;
//窗口管理类
class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

//窗口类
class Screen
{
	//声明友元
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;

	//定义构造函数
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd) ,contents(ht*wd,' ') {};
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {};

	//获取光标输入的内容
	//获取光标输入的宽和高
	char get() const { return contents[cursor]; };
	char get(pos r, pos c)const { return contents[r * width + c]; };

	//显示窗口的函数
	//常量的display函数
	const Screen& display(std::ostream& os)const
	{
		do_display(os);
		return *this;
	}
	//非常量的display函数
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	//移动函数
	inline Screen& move(pos r, pos c);
	//设置页面的函数
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

private:
	//定义do_display函数
	void do_display(std::ostream& os)const { os << contents; };
private:
	//声明相关变量最好在类一开始或者结束的位置
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
//窗口管理类中的清理函数
inline void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

#endif // !SCREEN

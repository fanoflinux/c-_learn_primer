#include<iostream>
#include<string>

//定义月份全称
//const std::string month_name = { "JanuaryFebruaryMarchAprilMayJuneJulyAugustSeptemberOctoberNovemberDecember" };
//定义月份简写
//const std::string month_abbr = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
//定义每个月的天数

//定义月份全称
const std::string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
//定义月份简写
const std::string month_abbr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
//定义每个月的天数
const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//定义数字组
const std::string number = { "1234567890" };
//定义符号组
const std::string symbol= {"/"};
bool judge_ds(std::string& ds);

//类的定义
class Date
{
	//判断传入的字符串是否是合法的
	friend bool judge_ds(std::string& ds);
public:
	Date() = default;
	Date(std::string& ds)
	{
		if (judge_ds(ds))
		{
			month = get_month(ds);
			day = get_day(ds,month);
			year = get_year(ds);
			std::cout << year << "年" << month << "月" << day << "日" << std::endl;
		}
		else
			std::cout << "好像出错了" << std::endl;
	}
	//获取月份的函数获取字符串返回月份结束的位置
	int get_month(std::string& ds);
	//获取日期
	int get_day(std::string& ds, const int& month);
	//获取年份
	int get_year(std::string& ds);

private:
	unsigned day;
	unsigned month;
	unsigned year;
};
//分割出非数字的内容
inline std::string cut_wrod(std::string& ds)
{
	size_t pos_num = 0;
	pos_num = ds.find_first_of(symbol);
	//构造字母字符串
	std::string word_str = ds.substr(0, pos_num );
	return word_str;
}
//分割出第一串数字
inline std::string cut_num(std::string& ds)
{
	size_t pos_num = 0;
	pos_num = ds.find_first_not_of("1234567890");
	std::string num_str = ds.substr(0, pos_num);
	return num_str;
}
//区分处理简写以及全称
inline int return_wrod_mon(std::string& ds)
{
	if (ds.find_first_of(symbol)==3)
	{
		std::string short_mon = ds.substr(0, 3);
		for (int i = 0; i < 12; i++)
		{
			if (short_mon == month_abbr[i])
				return i+1;
		}
	}
	else
	{
		size_t pos_long = ds.find_first_of(symbol);
		std::string long_mon = ds.substr(0, pos_long);
		for (int i = 0; i < 12; i++)
		{
			if (long_mon == month_name[i])
				return i+1;
		}
	}
	return 0;
}


//判断字符串是否合法
bool judge_ds(std::string& ds)
{
	//判断前两个数字是否是合法数字
	//if (ds.find(number,0) != std::string::npos)//第一个是不是数字
	if(std::isdigit(ds[0]))
	{
		std::string num_str= cut_num(ds);
		int num_str_int = std::stoi(num_str);
		if (num_str_int < 1 || num_str_int>12)
		{
			std::cout << "月份非法" << std::endl;
			return false;
		}
			
	}
	else
	{
		std::string word_str = cut_wrod(ds);
		bool valid_month = false;
		for (int i = 0; i < 12; i++)
		{
			if (word_str == month_name[i] || word_str == month_abbr[i])//相同则返回true不同则返回false
			{
				valid_month = true;
				break;
			}
		}
		if (valid_month == false)
		{
			std::cout << "月份非法" << std::endl;
			return false;
		}
	}
	if (ds.find(symbol) == std::string::npos)
	{
		std::cout << "非法字符串" << std::endl;
		return false;
	}
	return true;
}

int Date::get_month(std::string& ds)
{
	int month_number;
	if (std::isdigit(ds[0]))
	{
		//pos_mon = ds.find_first_of(symbol);//返回第一个分割符号的位置
		std::string mon_num = cut_num(ds);//分割出月份的数字
		month_number = std::stoi(mon_num);
		return month_number;
	}
	else
	{
		//pos_mon= ds.find_first_of(symbol);//返回第一个分割符号的位置
		month_number = return_wrod_mon(ds);
		return month_number;
	}
	return 0;
}
int Date::get_day(std::string& ds,const int &month)
{
	int day_number;
	size_t pos_mon = ds.find_first_of(symbol);
	size_t pos_day = ds.find_last_of(symbol,pos_mon+1);
	//size_t pos_day = ds.find_first_of(symbol,pos_mon+1);
	std::string day_num = ds.substr(pos_mon+1, pos_day-pos_mon-1);
	day_number = std::stoi(day_num);
	if (day_number <= days[month])
	{
		return day_number;
	}
	else
	{
		std::cout << "超过了该月份的天数" << std::endl;
		return -1;
	}
	return 0;
}

int Date::get_year(std::string& ds)
{
	size_t pos_day = ds.find_last_of(symbol )+1;
	std::string year_num = ds.substr(pos_day);
	if (year_num.size() >= 5)
		return -1;
	else
	{
		int year_number = std::stoi(year_num);
		return year_number;
	}
	return 0;
}

int main()
{
	//std::string test2 = "January/1";
	//bool jds1=judge_ds(test2);

	//std::string test1 = "January/12/1999";
	//Date d1(test1);

	std::string test2 = "Mar/22/1999";
	Date d2(test2);

	std::string test3 = "08/03/2023";
	Date d3(test3);
	system("pause");
	return 0;
}
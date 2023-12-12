
#include<iostream>
#include<string>
#include<stdexcept>

//定义月份全称
const std::string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
//定义月份简写
const std::string month_abbr[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//定义每个月的天数
const int days[] = { 31,28,31,30,31,31,30,31,30,31 };

//判断月份的内联函数
inline int get_month(std::string& ds, int& end_of_month)
{
	int i, j;
	//检查月份简称
	for (i = 0; i < 12; i++)
	{
		//检查每个字符是否与月份简写相同
		for (j = 0; j < month_abbr[i].size(); j++)
		{
			if (ds[j] != month_abbr[i][j])//遍历到中段发现不是此月份的简写
				break;
			if (j == month_abbr[i].size()-1)//遍历完月份发现不匹配
				break;
		}
	}
	if (i == 12)//与所有月份名都不相同
		throw std::invalid_argument("月份不合法");
	if (ds[j] == ' ')//空白符，仅是月份简写
	{
		end_of_month = j + 1;//查找月份结束
		return i + 1;//第几个月，找到索引
	}

	//检查月份全称
	for (; j < month_name[i].size(); j++)
	{
		if (ds[j] != month_name[i][j])
			break;
		if (j == month_name[i].size() && ds[j] == ' ')//遍历完而且以空格字符结束
		{
			//月份全称
			end_of_month = j + 1;
			return i + 1;//第几个月，找到索引
		}
	}
	throw std::invalid_argument("非法月份");
}
//判断日期的内联函数
inline int get_day(std::string &ds, int month, int& p)
{
	size_t q;
	int day = std::stoi(ds.substr(p), &q);//从p开始的部分转换为日期值
	if (day<1 || day>days[month])
	{
		throw std::invalid_argument("不是合法日期");
	}
	p += q;//把位置移动到日期值之后
	return day;
}

inline int get_year(std::string& ds, int& p)
{
	size_t q;
	int year = std::stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("非法结尾内容");
	return  year;
}


class Date
{
public:
	friend std::ostream& operator<<(std::ostream&, const Date&);
	/*构造函数*/
	//读取数据类型的日期
	Date() = default;
	Date(std::string &ds);

	unsigned y()const { return year; };
	unsigned m()const { return month; };
	unsigned d()const { return day; };

private:
	unsigned day, month, year;
};
Date::Date(std::string& ds)
{
	int  p;
	size_t q;
	if ((p = ds.find_first_of("0123456789")) == std::string::npos)
	{
		throw std::invalid_argument("没有数字，非法日期");
	}
	if (p > 0)//月份名格式
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("非法间隔符");
		p++;
		year = get_year(ds, p);
	}
	else//数字格式月份
	{
		month = std::stoi(ds, &q);
		p = q;
		if (month < 1 || month>12)
			throw std::invalid_argument("不是合法月份值");
		if(ds[p++]!='/')
			throw std::invalid_argument("非法间隔符");
		year = get_year(ds, p);
	}
}
std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d.y() << "年" << d.m() << "月" << d.d() << "日" << std::endl;
	return out;
}

int main()
{
	std::string dates[] = { "Jan 1,2023","3/1/2023" };
	try
	{
		for (auto ds : dates)
		{
			Date d1(ds);
			std::cout << d1;
		}
	}
	catch (std::invalid_argument e)
	{
		std::cout<<e.what() << std::endl;
	}

	system("pause");
	return 0;
}
#include<iostream>
#include<string>

//�����·�ȫ��
//const std::string month_name = { "JanuaryFebruaryMarchAprilMayJuneJulyAugustSeptemberOctoberNovemberDecember" };
//�����·ݼ�д
//const std::string month_abbr = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
//����ÿ���µ�����

//�����·�ȫ��
const std::string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
//�����·ݼ�д
const std::string month_abbr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
//����ÿ���µ�����
const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//����������
const std::string number = { "1234567890" };
//���������
const std::string symbol= {"/"};
bool judge_ds(std::string& ds);

//��Ķ���
class Date
{
	//�жϴ�����ַ����Ƿ��ǺϷ���
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
			std::cout << year << "��" << month << "��" << day << "��" << std::endl;
		}
		else
			std::cout << "���������" << std::endl;
	}
	//��ȡ�·ݵĺ�����ȡ�ַ��������·ݽ�����λ��
	int get_month(std::string& ds);
	//��ȡ����
	int get_day(std::string& ds, const int& month);
	//��ȡ���
	int get_year(std::string& ds);

private:
	unsigned day;
	unsigned month;
	unsigned year;
};
//�ָ�������ֵ�����
inline std::string cut_wrod(std::string& ds)
{
	size_t pos_num = 0;
	pos_num = ds.find_first_of(symbol);
	//������ĸ�ַ���
	std::string word_str = ds.substr(0, pos_num );
	return word_str;
}
//�ָ����һ������
inline std::string cut_num(std::string& ds)
{
	size_t pos_num = 0;
	pos_num = ds.find_first_not_of("1234567890");
	std::string num_str = ds.substr(0, pos_num);
	return num_str;
}
//���ִ����д�Լ�ȫ��
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


//�ж��ַ����Ƿ�Ϸ�
bool judge_ds(std::string& ds)
{
	//�ж�ǰ���������Ƿ��ǺϷ�����
	//if (ds.find(number,0) != std::string::npos)//��һ���ǲ�������
	if(std::isdigit(ds[0]))
	{
		std::string num_str= cut_num(ds);
		int num_str_int = std::stoi(num_str);
		if (num_str_int < 1 || num_str_int>12)
		{
			std::cout << "�·ݷǷ�" << std::endl;
			return false;
		}
			
	}
	else
	{
		std::string word_str = cut_wrod(ds);
		bool valid_month = false;
		for (int i = 0; i < 12; i++)
		{
			if (word_str == month_name[i] || word_str == month_abbr[i])//��ͬ�򷵻�true��ͬ�򷵻�false
			{
				valid_month = true;
				break;
			}
		}
		if (valid_month == false)
		{
			std::cout << "�·ݷǷ�" << std::endl;
			return false;
		}
	}
	if (ds.find(symbol) == std::string::npos)
	{
		std::cout << "�Ƿ��ַ���" << std::endl;
		return false;
	}
	return true;
}

int Date::get_month(std::string& ds)
{
	int month_number;
	if (std::isdigit(ds[0]))
	{
		//pos_mon = ds.find_first_of(symbol);//���ص�һ���ָ���ŵ�λ��
		std::string mon_num = cut_num(ds);//�ָ���·ݵ�����
		month_number = std::stoi(mon_num);
		return month_number;
	}
	else
	{
		//pos_mon= ds.find_first_of(symbol);//���ص�һ���ָ���ŵ�λ��
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
		std::cout << "�����˸��·ݵ�����" << std::endl;
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
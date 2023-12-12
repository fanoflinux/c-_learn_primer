
#include<iostream>
#include<string>
#include<stdexcept>

//�����·�ȫ��
const std::string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
//�����·ݼ�д
const std::string month_abbr[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//����ÿ���µ�����
const int days[] = { 31,28,31,30,31,31,30,31,30,31 };

//�ж��·ݵ���������
inline int get_month(std::string& ds, int& end_of_month)
{
	int i, j;
	//����·ݼ��
	for (i = 0; i < 12; i++)
	{
		//���ÿ���ַ��Ƿ����·ݼ�д��ͬ
		for (j = 0; j < month_abbr[i].size(); j++)
		{
			if (ds[j] != month_abbr[i][j])//�������жη��ֲ��Ǵ��·ݵļ�д
				break;
			if (j == month_abbr[i].size()-1)//�������·ݷ��ֲ�ƥ��
				break;
		}
	}
	if (i == 12)//�������·���������ͬ
		throw std::invalid_argument("�·ݲ��Ϸ�");
	if (ds[j] == ' ')//�հ׷��������·ݼ�д
	{
		end_of_month = j + 1;//�����·ݽ���
		return i + 1;//�ڼ����£��ҵ�����
	}

	//����·�ȫ��
	for (; j < month_name[i].size(); j++)
	{
		if (ds[j] != month_name[i][j])
			break;
		if (j == month_name[i].size() && ds[j] == ' ')//����������Կո��ַ�����
		{
			//�·�ȫ��
			end_of_month = j + 1;
			return i + 1;//�ڼ����£��ҵ�����
		}
	}
	throw std::invalid_argument("�Ƿ��·�");
}
//�ж����ڵ���������
inline int get_day(std::string &ds, int month, int& p)
{
	size_t q;
	int day = std::stoi(ds.substr(p), &q);//��p��ʼ�Ĳ���ת��Ϊ����ֵ
	if (day<1 || day>days[month])
	{
		throw std::invalid_argument("���ǺϷ�����");
	}
	p += q;//��λ���ƶ�������ֵ֮��
	return day;
}

inline int get_year(std::string& ds, int& p)
{
	size_t q;
	int year = std::stoi(ds.substr(p), &q);
	if (p + q < ds.size())
		throw std::invalid_argument("�Ƿ���β����");
	return  year;
}


class Date
{
public:
	friend std::ostream& operator<<(std::ostream&, const Date&);
	/*���캯��*/
	//��ȡ�������͵�����
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
		throw std::invalid_argument("û�����֣��Ƿ�����");
	}
	if (p > 0)//�·�����ʽ
	{
		month = get_month(ds, p);
		day = get_day(ds, month, p);
		if (ds[p] != ' ' && ds[p] != ',')
			throw std::invalid_argument("�Ƿ������");
		p++;
		year = get_year(ds, p);
	}
	else//���ָ�ʽ�·�
	{
		month = std::stoi(ds, &q);
		p = q;
		if (month < 1 || month>12)
			throw std::invalid_argument("���ǺϷ��·�ֵ");
		if(ds[p++]!='/')
			throw std::invalid_argument("�Ƿ������");
		year = get_year(ds, p);
	}
}
std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d.y() << "��" << d.m() << "��" << d.d() << "��" << std::endl;
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
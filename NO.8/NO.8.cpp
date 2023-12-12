#include <iostream>
#include<string>

//创建一个函数接受istream&参数
std::istream& func1(std::istream& is)
{
    std::string buf;
    while (is>>buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    std::istream& is = func1(std::cin);
    std::cout << is.rdstate() << std::endl;
    system("pause");
    std::cout << "Hello World!\n";
    return 0;
}


#include <iostream>
#include <string>
#include <functional>

using std::string;
// ����ǩ����������������̬�����ַ��������������
void readInput(std::istream& input, std::string& output) {
    std::getline(input, output);
}

std::unique_ptr<string[]> get_input(std::istream& input,std::string& str1)
{
    std::cout << "ԭ�ַ�������" << std::endl;
    for (auto& i : str1)
        std::cout << i;

}

int main() {
    std::string userInput;

    // ��������
    std::istream& inputStream = std::cin;

    std::cout << "Enter a string: ";

    // ���ú�������̬�����ַ���
    readInput(inputStream, userInput);

    // ����û�������ַ���
    std::cout << "You entered: " << userInput << std::endl;

    // ���������
    inputStream.clear();  // ������ܵĴ����־
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ������뻺����

    return 0;
}

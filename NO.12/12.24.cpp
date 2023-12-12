#include <iostream>
#include <string>
#include <functional>

using std::string;
// 函数签名：绑定输入流、动态调整字符串、解绑输入流
void readInput(std::istream& input, std::string& output) {
    std::getline(input, output);
}

std::unique_ptr<string[]> get_input(std::istream& input,std::string& str1)
{
    std::cout << "原字符串内容" << std::endl;
    for (auto& i : str1)
        std::cout << i;

}

int main() {
    std::string userInput;

    // 绑定输入流
    std::istream& inputStream = std::cin;

    std::cout << "Enter a string: ";

    // 调用函数，动态调整字符串
    readInput(inputStream, userInput);

    // 输出用户输入的字符串
    std::cout << "You entered: " << userInput << std::endl;

    // 解绑输入流
    inputStream.clear();  // 清除可能的错误标志
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 清除输入缓冲区

    return 0;
}

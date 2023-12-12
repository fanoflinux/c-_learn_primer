#include <iostream>
#include<string>
#include"Screen.h"


int main()
{
    Screen myscreen1(5, 5, 'x');
    myscreen1.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myscreen1.display(std::cout);
    std::cout << "\n";
    
    

    system("pause");
    std::cout << "Hello World!\n";
}

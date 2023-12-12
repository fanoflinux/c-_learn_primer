#include <iostream>
#include <vector>
#include <list>

int main() {
    int ia[] = { 1, 2, 3, 4, 5 };

    // ������ ia ������һ�� vector ��
    std::vector<int> vec(std::begin(ia), std::end(ia));

    // ������ ia ������һ�� list ��
    std::list<int> lst(std::begin(ia), std::end(ia));

    // �� list ��ɾ������Ԫ��
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2 != 0) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }

    // �� vector ��ɾ��ż��Ԫ��
    auto iter1 = vec.begin();
    while (iter1 != vec.end()) {
        if (*iter1 % 2 == 0) {
            iter1 = vec.erase(iter1);
        }
        else {
            ++iter1;
        }
    }

    // ��ӡ vector �е�Ԫ��
    std::cout << "Vector elements: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // ��ӡ list �е�Ԫ��
    std::cout << "List elements: ";
    for (const auto& element : lst) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

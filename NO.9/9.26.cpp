#include <iostream>
#include <vector>
#include <list>

int main() {
    int ia[] = { 1, 2, 3, 4, 5 };

    // 将数组 ia 拷贝到一个 vector 中
    std::vector<int> vec(std::begin(ia), std::end(ia));

    // 将数组 ia 拷贝到一个 list 中
    std::list<int> lst(std::begin(ia), std::end(ia));

    // 从 list 中删除奇数元素
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2 != 0) {
            it = lst.erase(it);
        }
        else {
            ++it;
        }
    }

    // 从 vector 中删除偶数元素
    auto iter1 = vec.begin();
    while (iter1 != vec.end()) {
        if (*iter1 % 2 == 0) {
            iter1 = vec.erase(iter1);
        }
        else {
            ++iter1;
        }
    }

    // 打印 vector 中的元素
    std::cout << "Vector elements: ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 打印 list 中的元素
    std::cout << "List elements: ";
    for (const auto& element : lst) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

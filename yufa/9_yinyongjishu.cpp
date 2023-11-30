//
// Created by 11751 on 2023/11/29.
//
#include<bits/stdc++.h>
using namespace std;
class MyClass {
public:
    MyClass() {
        std::cout << "Object created." << std::endl;
    }

    ~MyClass() {
        std::cout << "Object destroyed." << std::endl;
    }
};

/*
int main() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> ptr2 = ptr1;

    std::cout << "Use count: " << ptr1.use_count() << std::endl;

    // ptr2 被销毁后，计数器减1
    ptr2.reset();

    std::cout << "Use count: " << ptr1.use_count() << std::endl;

    // ptr1 被销毁后，计数器减1，为零时，MyClass 对象被销毁
    ptr1.reset();

    return 0;
}
 */
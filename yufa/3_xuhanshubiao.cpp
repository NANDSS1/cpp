//
// Created by 11751 on 2023/11/28.
//
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal is making a sound" << endl;
    }
};
/*
int main() {
    Animal animal;
    Animal* ptr = &animal;

    // 获取虚函数表指针
    uintptr_t* vptr = (uintptr_t*)(&animal);

    // 获取第一个虚函数地址
    uintptr_t vfunc1 = vptr[0];

    // 输出虚函数地址
    cout << "The address of the first virtual function is: " << vfunc1 << endl;

    return 0;
}
 */
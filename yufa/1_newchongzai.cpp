//
// Created by 11751 on 2023/11/28.
//
#include <iostream>
using namespace std;

class MyClass {
public:
    void* operator new(size_t size) {
        cout << "Overloaded new operator with size: " << size << endl;
        void* ptr = ::operator new(size);  // 调用标准的内存分配函数
        return ptr;
    }

    void operator delete(void* ptr) {
        cout << "Overloaded delete operator" << endl;
        ::operator delete(ptr);  // 调用标准的内存释放函数
    }
};
/*在 C++ 中，new 运算符的形式为 operator new(size_t size)，其中的 size 参数表示需要分配的内存大小。这个参数是编译器根据你使用 new 运算符时所创建的对象的类型推断出来的。*/
/*
int main() {
    MyClass* obj = new MyClass();
    delete obj;
    return 0;
}
 */

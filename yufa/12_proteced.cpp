#include <iostream>

class Base {
protected:
    int protectedVar;

public:
    void setProtectedVar(int value) {
        protectedVar = value;
    }
};

class Derived : public Base {
public:
    void printProtectedVar() {
        std::cout << "The value of protectedVar is: " << protectedVar << std::endl;
    }
};

/*
int main() {
    Base base;
    //base.protectedVar;  // 无法从类的外部访问受保护成员

    Derived derived;
    derived.setProtectedVar(10);
    derived.printProtectedVar();  // 在派生类的成员函数中可以访问受保护成员

    return 0;
}
 */
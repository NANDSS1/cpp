//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:
    Animal(string name) : _name(name) { }
    virtual void bark() = 0; //纯虚函数
protected:
    string _name;
};
//以下是动物实体类
class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) { }
    void bark() { cout << _name << "bark: miao miao!" << endl; }
};
class Dog :public Animal
{
public:
    Dog(string name):Animal(name) { }
    void bark() { cout << _name << "bark: wang wang!" << endl; }
};
class Pig : public Animal
{
public: // 将构造函数改为 public
    Pig(string name) : Animal(name) {}
    void bark() { cout << _name << "bark: heng heng! " << endl; }
};

void bark(Animal* p)
{
    p->bark(); //Animal::bark虚函数，动态绑定了
}
/*
int main()
{
    Cat cat("cat");
    Dog dog("dog");
    Pig pig("pig");

    bark(&cat);
    bark(&dog);
    bark(&pig);

    return 0;
}
 */
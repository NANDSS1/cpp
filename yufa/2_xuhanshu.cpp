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

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Woof!" << endl;
    }
};

/*
int main() {
    Animal* animal = new Animal();
    Animal* cat = new Cat();
    Animal* dog = new Dog();

    animal->makeSound();  // 编译时绑定，输出 "Animal is making a sound"
    cat->makeSound();     // 运行时绑定，输出 "Meow!"
    dog->makeSound();     // 运行时绑定，输出 "Woof!"

    delete animal;
    delete cat;
    delete dog;

    return 0;
}
 */
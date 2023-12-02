//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    //先进后出
    queue<int> que1;
    queue<int> que2;//当que1需要pop的时候，que2暂存que1的元素
    MyStack() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int size = que1.size();
        size--;
        while(size--){
            que2.push(que1.front());
            que1.pop();
        }
        int temp = que1.front();
        que1.pop();
        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return temp;
    }

    int top() {
        //代码复用
        int temp = this->pop();
        this->push(temp);
        return temp;

    }

    bool empty() {
        return que1.empty();
    }
};
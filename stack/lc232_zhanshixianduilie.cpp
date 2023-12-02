//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> st1;//int
    stack<int> st2;//out
    MyQueue() {

    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                int temp = st1.top();
                st2.push(temp);
                st1.pop();
            }
        }

        int res = st2.top();
        st2.pop();
        return res;
    }

    int peek() {
        //代码复用
        int res = this->pop();
        this->push(res);
        return res;

    }

    bool empty() {
        return st1.empty()&&st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
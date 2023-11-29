//
// Created by 11751 on 2023/11/29.
//
#include<bits/stdc++.h>
using namespace std;

void threadFun(){
    for(int i = 0;i < 5;i++) cout<<"threading"<<endl;
}

/*
int main(){
    thread t(threadFun);//创建线程然后启动

    for(int i = 0;i < 5;i++) cout<<"main"<<endl;
    t.join();//等待子线程执行完成，原地打转

}
 */

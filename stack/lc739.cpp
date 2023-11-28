//
// Created by 11751 on 2023/11/17.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈
        //保持栈单调递减
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n,0);
        for(int i = 0;i < temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                auto t = st.top();
                st.pop();
                res[t] = i - t;//找到第一个大于t的元素，已知循环t，往前面推天数，直到以前的温度大于以后的温度
            }
            //执行完上面这个循环之后，tempearetures[i]<=temperatures[st.top()]
            //可以保持单调栈

            //栈里面的元素是以前的温度，temperatures[i]的温度是以后的温度
            //以后的温度大于以前的温度的第一个
            st.push(i);
        }
        return res;
    }
};

/*
int main(){
    int a[] = {73,74,75,71,69,72,76,73};
    cout<<a;

    return 0;

};
*/
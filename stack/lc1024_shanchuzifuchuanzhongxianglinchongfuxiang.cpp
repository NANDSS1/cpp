//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = 0;i < s.size();i++){
            if(st.empty()) st.push(s[i]);
            else{
                if(st.top() == s[i]) st.pop();//需要弹出栈顶元素
                else st.push(s[i]);
            }
        }
        string str ="";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
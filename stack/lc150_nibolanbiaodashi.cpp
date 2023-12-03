//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isDigit(const char& c){
        if(c >= '0' && c <= '9') return true;
        else return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0;i < tokens.size();i++){
            if(isDigit(tokens[i][0])) st.push(stoi(tokens[i]));
            else{
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(temp1+temp2);
                else if(tokens[i] == "*") st.push(temp1*temp2);
                else if(tokens[i] == "/") st.push(temp2/temp1);
                else if(tokens[i] == "-") st.push(temp2-temp1);
            }
        }

        return st.top();

    }
};
//
// Created by 11751 on 2023/12/1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //移除多余空格
        reverse(s.begin(),s.end());
        int slow = 0;

        return s;
    }
};
/*
int main(){
    string str;
    char c;
    while(true){
        cin.get(c);
        if(c == '\n') break;
        str.push_back(c);
    }
    //cout<<str<<endl;
    Solution s;
    str = s.reverseWords(str);
    cout<<str;
}*/
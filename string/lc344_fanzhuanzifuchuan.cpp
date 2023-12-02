//
// Created by 11751 on 2023/12/1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left <= right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
/*
int main(){
    vector<char> s;
    char c;
    while(true){
        cin.get(c);
        if(c == '\n') break;
        s.push_back(c);
    }
    Solution S;
    S.reverseString(s);
    for(const auto& c:s){
        cout<<c;
    }
}
 */
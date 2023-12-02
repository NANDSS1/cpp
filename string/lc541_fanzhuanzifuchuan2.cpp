//
// Created by 11751 on 2023/12/1.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i< s.size(); i+=(2*k)){
            if(s.size()-i < k){
                reverse(s.begin()+i,s.end());
            }else{
                reverse(s.begin()+i,s.begin()+i+k);
            }
        }
        return s;
    }
};
/*
int main(){
    string s;
    char c;
    while(true){
        cin.get(c);
        if(c == '\n') break;
        s += c;
    }
    int k;
    cin>>k;
    Solution S;
    string ans = S.reverseStr(s,k);
    cout<<ans;

}
 */
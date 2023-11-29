//
// Created by 11751 on 2023/11/29.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int word[26]={0};

        for(int i = 0;i < s.length();i++){
            word[s[i]-'a']++;
        }
        for(int i = 0;i < t.length();i++){
            word[t[i]-'a']--;
        }
        for(int i = 0;i < 26;i++) {
            if(word[i] != 0) return false;
        }
        return true;


    }
};

//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int word[26] = {0};
        for(const char& c:ransomNote){
            word[c-'a']++;
        }
        for(const char& c:magazine){
            word[c-'a']--;
        }

        for(int i = 0;i < 26;i++){
            if(word[i] > 0) return false;
        }
        
        return true;

    }
};
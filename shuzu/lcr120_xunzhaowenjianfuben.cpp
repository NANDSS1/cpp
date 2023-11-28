//
// Created by 11751 on 2023/11/23.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_set<int> hashset;
        for(const auto& n:documents){
            if(!hashset.count(n)) hashset.insert(n);
            else return n;
        }

        return 0;
    }
};
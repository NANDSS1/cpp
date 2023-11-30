//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //分组加hashmap,o(n2)
        unordered_map<int,vector<int>> hashmap;
        for(const auto& num1:nums1){
            for(const auto& num2:nums2){
                hashmap[num1+num2]++;
            }
        }

        int ans = 0;
        for(auto num3:nums3){
            for(auto num4:nums4){
                if(hashmap.count(-(num3+num4))) ans += hashmap[-(num3+num4)];
            }
        }
    }
};

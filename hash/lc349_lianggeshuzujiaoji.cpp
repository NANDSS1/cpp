//
// Created by 11751 on 2023/11/29.
//

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set1(nums1.begin(),nums1.end());
        //nums1先加入

        //以nums2为主体遍历
        for(const auto& num:nums2){
            if(set1.count(num)){
                res.insert(num);
            }
        }
        vector<int> ans(res.begin(),res.end());//赋值
        return ans;
    }
};

/*
int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution s = Solution();
    vector<int> ans = s.intersection(nums1,nums2);

    for(const auto& num:ans){
        cout<<num<<" ";
    }
}
 */
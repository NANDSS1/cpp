//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> hashmap;
         for(int i = 0;i < nums.size();i++){
             if(!hashmap.count(target - nums[i])) hashmap[nums[i]] = i;
             else return {i,hashmap[target-nums[i]]};
         }

         return {};
    }
};
/*
int main(){
    vector<int> nums;
    int num;
    while (true)
    {
        cin >> num;
        nums.push_back(num);
        if (cin.get() == '\n')
            break;
    }


    int target;
    cin>>target;
    Solution s = Solution();
    vector<int> ans = s.twoSum(nums,target);
    cout<<ans[1]<<ans[0];
}
 */
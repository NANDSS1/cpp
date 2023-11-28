//
// Created by 11751 on 2023/11/21.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0;i < n-3;i++){//防止索引越界
            if(nums[i] > target) return res;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i+1;j < n-2;j++){//防止索引越界
                if (j > i+1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j+1;
                int right = n-1;
                while(left < right){
                    if((nums[i]+nums[j]+nums[left]+nums[right]) < target) left++;
                    else if((nums[i]+nums[j]+nums[left]+nums[right]) > target) right--;
                    else {
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right && nums[left++]==nums[left]);
                        while(left<right && nums[right--]==nums[right]);//去重
                    }
                }
            }
        }


        return res;
    }
};

/*
int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution s = Solution();
    vector<vector<int>> ans = s.fourSum(nums,target);

    int m = ans.size();
    int n = ans[0].size();

    for(int i = 0;i < m;i++){
        cout<<'[';
        for(int j = 0;j < n;j++){
            cout<<ans[i][j]<<',';
        }
        cout<<']'<<endl;
    }

    return 0;
}
 */

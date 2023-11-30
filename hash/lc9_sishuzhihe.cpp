//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4) return{};
        //o(n3)
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i < nums.size()-3;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j < nums.size()-2;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                //cout<<i<<j<<endl;
                long long num = target-nums[i]-nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left < right){
                    if(nums[left]+nums[right] < num) left++;
                    else if(nums[left]+nums[right] > num) right--;
                    else{
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }


        return ans;

    }
};

int main(){
    vector<int> nums = {2,2,2,2,2};
    Solution s;
    vector<vector<int>>ans = s.fourSum(nums,8);
    for(const auto& vec:ans){
        for(const auto& v:vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

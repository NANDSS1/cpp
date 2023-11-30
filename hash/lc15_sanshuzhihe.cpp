//
// Created by 11751 on 2023/11/30.
//

/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //一个循环加一个双指针
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i < nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;//找到和前面元素都不相同的i索引的元素，i=0显然不相同
            int left = i+1;
            int right = nums.size()-1;
            int target = -nums[i];
            while(left < right){
                if(nums[left]+nums[right] < target) left++;
                else if(nums[left]+nums[right] > target) right--;
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;//left+1 不等于 left的时候退出循环
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>>ans = s.threeSum(nums);
    for(const auto& vec:ans){
        for(const auto& v:vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
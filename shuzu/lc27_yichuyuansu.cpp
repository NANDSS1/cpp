//
// Created by 11751 on 2023/11/28.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int last = nums.size()-1;
        int num = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == val) num++;
        }
        for(int i = 0;i < nums.size();i++){
            if(num == 0) break;
            if(nums[i] == val){
                //cout<<nums[i]<<nums[last]<<endl;
                 swap(nums[i],nums[last]);
                 last --;
                 num--;
             }
         }
        //cout<<last;

    }
};

/*
int main(){
    vector<int> nums = {1,2,4,3,2,2};
    int val = 2;
    Solution s = Solution();
    int len = s.removeElement(nums,val);
    for(const auto& num:nums){
        cout<<num<<" ";
    }
}
 */

//
// Created by 11751 on 2023/11/28.
//
#include<bits/stdc++.h>
using namespace std;
/*时间复杂度 o(n)*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& num:nums){
            num = num*num;
        }
        int minIndex = 0;
        int min = nums[0];

        for(int i = 1;i < nums.size();i++){
            if(nums[i] < min){
                minIndex = i;
                min = nums[i];
            }
        }
        vector<int> vec;
        int left = minIndex-1;
        int right = minIndex+1;
        vec.push_back(min);
        while(left >= 0 && right <= nums.size()-1){
            if(nums[right]<= nums[left]){
                vec.push_back(nums[right]);
                right++;
            }
            else if(nums[right] > nums[left]){
                vec.push_back(nums[left]);
                left--;
            }
        }
        //cout<<right;
        //cout<<left;
        if(right <= nums.size()-1){//left加完了
            for(int i = right;i <= nums.size()-1;i++) vec.push_back(nums[i]);
        }

        if(left >= 0){//right加完了
            for(int i = left;i >= 0;i--) vec.push_back(nums[i]);
        }
        /*
        for(const auto& num:nums){
            cout<<num<<endl;
        }
         */

        return vec;

    }
};



/*
int main(){
    vector<int> nums = {-5,-3,-2,-1};
    Solution s = Solution();
    vector<int> vec = s.sortedSquares(nums);

    for(const auto& num:vec){
        cout<<num<<" ";
    }
}

*/
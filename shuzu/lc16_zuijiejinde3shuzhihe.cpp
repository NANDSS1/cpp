//
// Created by 11751 on 2023/11/20.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //双指针加一个for
        //o(n2)的时间复杂度
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i = 0;i < n;i++){

            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = nums[left]+nums[right]+nums[i];
                if(abs(target-sum) < abs(target-ans)) ans = sum;//收集结果
                if(sum > target) right--;
                else if(sum < target) left++;
                else return sum;
            }
        }

        return ans;
    }
};

/*
int main(){
    vector<int> nums = {-1,2,1,-4};
    Solution s = Solution();
    int ans = s.threeSumClosest(nums,1);
    cout<<ans<<endl;

}
 */



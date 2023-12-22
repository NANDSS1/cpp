/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //依次相加，如果前面的和出现了负数直接丢,每次循环都要记录一个max
        int maxNum = INT_MIN;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            maxNum = max(maxNum,sum);
            if(sum < 0) sum = 0;
        }

        return maxNum;

    }
};
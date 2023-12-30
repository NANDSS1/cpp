/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(const auto& num:nums){
            sum += num;
        }
        if(sum%2 != 0) return false;
        
        //就看容量为sum/2的背包能不能被装满
        vector<int> dp(sum/2+1,0);

        //先遍历物品，然后倒着遍历背包
        //先遍历物品的意思是，选中一个物品，然后背包一次转移。

        for(int i = 0;i < nums.size();i++){
            for(int j = sum/2;j-nums[i]>=0;j--){//j就是背包具体的容量，nums[i]就是物品的重量
                dp[j] = max(dp[j-nums[i]]+nums[i],dp[j]);//从容量j-nums[i]的背包转移，然后加上nums[i]的物品。 但是如果dp[j]本身的价值就够了，就不需要转移
            }
        }

        if(dp.back() == sum/2) return true;

        return false;


    }
};
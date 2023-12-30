#include<bits/stdc++.h>
using namespace std;

/*给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //记录所有数的总和为sum
        int sum = 0;
        for(const auto& num:nums){
            sum += num;
        }
        //判断无解的情况
        if(sum > abs(target)) return 0;
        //第二种无解的的情况 正数为x，x - (sum-x) == target -> x = target+sum/2 要有解(能被整除)
        if((target+sum)%2 == 0) return 0;

        //有解，设置包的大小
        int bagSize = (target+sum)/2;
        vector<int>dp(bagSize+1,0);//包的容量为1
        dp[0] = 1;
        //先遍历物品再遍历背包,填满j（包括j）这么大容积的包，有dp[j]种方法
        for(int i = 0;i < nums.size();i++){
            for(int j = bagSize;j-nums[i]>=0;j--){
                dp[j] += dp[j-nums[i]];//nums[i]已经放到容量为j的背包里了，就只需要加上容量为dp[j-nums[i]]的背包里面的最大装法,东西应该是复制一份
                //第一轮 dp[j] += dp[0];
                //第二轮 只有j=nums[1]的时候才能
            }
        }

        return dp.back();


    }
};
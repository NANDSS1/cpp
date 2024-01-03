
/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //物品能不能取多次->可以->完全背包->正序遍历背包
        //排列还是组合 1 2 5 和 5 2 1有区别没有->没有->组合->先遍历物品 卡尔说这个题排列和组合的界限没有那么清楚
        vector<int> dp(amount+1,INT_MAX);
        //初始化
        dp[0] = 1;
        for(int i = 0;i < coins.size();i++){
            for(int j = coins[i];j <= amount;j++){
            if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }

        if(dp.back() == INT_MAX) return -1;

        return dp.back();
    }
};
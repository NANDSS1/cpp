/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

 

示例 1：

输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2：

输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：

输入：amount = 10, coins = [10] 
输出：1
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //背包最大容量为amount
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        //先遍历物品再遍历背包，组合问题
        for(int i = 0;i < coins.size();i++){
            for(int j = coins[i]; j <= amount;j++ ){//在遍历重量为coins[i]的物品的时候，背包的重量必须大于等于coins[i]
                dp[j] += dp[j-coins[i]];//递推公式
            }//完全背包，每个物品可以取很多次，正序遍历
        }

        return dp.back();
    }
};
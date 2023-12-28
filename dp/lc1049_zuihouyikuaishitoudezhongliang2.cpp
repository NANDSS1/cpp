/*有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

 

示例 1：

输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：

输入：stones = [31,26,33,21,40]
输出：5
 

提示：

1 <= stones.length <= 30
1 <= stones[i] <= 100*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //尽量让其中一堆靠近sum/2
        /*而我们要求的target其实只是最大重量的一半，所以dp数组开到15000大小就可以了*/
        vector<int> dp(15001,0);
        //先遍历物品再遍历背包
        int sum = 0;
        for(const auto& s:stones){
            sum += s;
        }
        int target = sum/2;
        //从背包为target的开始倒着遍历，看背包容量为target的最多能装多少价值的物品
        //先遍历物品
        for(int i = 0;i < stones.size();i++){
            for(int j = target;j-stones[i] >= 0;j--){
                dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }

        int ans = abs(dp[target]-(sum-dp[target]));

        return ans;
    }
};
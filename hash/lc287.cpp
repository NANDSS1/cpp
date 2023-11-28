//
// Created by 11751 on 2023/11/17.
//

/*
 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

 示例 1：

输入：nums = [1,3,4,2,2]
输出：2
示例 2：

输入：nums = [3,1,3,4,2]
输出：3
 * */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(const auto& num:nums){
            if(set.count(num)){
                return num;
            }else{
                set.insert(num);
            }
        }

        return 0;
    }
};
//时间复杂度o(n)
//count这个api的时间复杂度是o(1)
/*
int main(){
    vector<int>nums = {1,3,4,2,2};
    Solution s = Solution();
    int a = s.findDuplicate(nums);
    cout<<a;
    return 0;
}
 */
/*给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/


//层数就是排列的索引
//第一层的排列在第一个
//used[i-1]==false表示第i-1个没有被选，它有可能被选，如果，nums[i]==nums[i-1]，i选了的话就会产生重复，所以i不能被选
//但是第一个元素一定可以被选
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums,vector<bool>& used,int n){
        if(path.size() == n) {
            res.push_back(path);
            return;
        }
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if(used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,used,n);
            used[i] = false;
            path.pop_back();
        }

    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,used,nums.size());

        return res;
    }
};
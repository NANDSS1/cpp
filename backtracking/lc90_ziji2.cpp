/*给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

 

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(int index,int n,vector<bool>& used,vector<int>& nums){
        res.push_back(path); //收集方式和全排列有些不一样
        for(int i = index;i < n;i++){
            //这里没有index
            if(i > index && nums[i] == nums[i-1] && used[i-1] == false) continue;//used[i-1] == false表示,nums[i-1]没有被使用，有可能被使用，所以要跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(i+1,n,used,nums);//有index
            path.pop_back();
            used[i] = false;
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(0,nums.size(),n,used,nums);
        return res;
    }
};



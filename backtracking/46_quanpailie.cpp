
/*给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<bool>& used,int index,int n,vector<int>& nums){
        if(path.size() == n) ans.push_back(path);
        for(int i = 0;i < n;i++){
            if(used[i] == true) continue;
            //如果没有用过
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(used,i+1,n,nums);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(used,0,nums.size();nums);
        return ans;

    }
};
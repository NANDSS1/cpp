#include<bits/stdc++.h>

using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(int n,int index,vector<int>& nums){
        ans.push_back(path);
        for(int i = index;i < n;i++){
            path.push_back(nums[i]);
            backtracking(n,i+1,nums);
            path.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //每一层都收集结果
        backtracking(nums.size(),0,nums);
        return ans;
    }
};
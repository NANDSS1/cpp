//
// Created by 11751 on 2023/12/8.
//
/*给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
public:
    void backtracking(int n,int k,int index){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = index;i <= n;i++){
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }
};

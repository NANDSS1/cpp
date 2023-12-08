//
// Created by 11751 on 2023/12/8.
//
/*找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 * */
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backtracking(int k,int n,int index,int sum){
        if(path.size()==k){
            if(sum == n) res.push_back(path);
            return;
        }
        for(int i = index; i <= 9;i++){
            sum += i;
            path.push_back(i);
            backtracking(k,n,i+1,sum);
            sum -= i;
            path.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1,0);
        return res;
    }
};

//
// Created by 11751 on 2023/11/23.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;//left
        int r = n-1;//right
        int t = 0;//top
        int b = n-1;//buttom

        vector<vector<int>> ans(n,vector<int>(n,0));
        int k = 1;
        while(k <= n*n){
            for(int i = l;i <= r;i++,k++) ans[t][i] = k;
            t++;//top可以收缩了
            for(int i = t;i <= b;i++,k++) ans[i][r] = k;
            r--;//right可以收缩了
            for(int i = r;i >= l;i--,k++) ans[b][i] = k;
            b--;//buttom可以收缩了
            for(int i = b;i >= t;i--,k++) ans[i][l] = k;
            l++;//l可以收缩了
        }

        return ans;

    }
};
/*
int main(){

    Solution s = Solution();
    int n = 3;
    vector<vector<int>> res = s.generateMatrix(n);
    for(const auto& r:res){
        cout<<r[0];
    }
}
*/
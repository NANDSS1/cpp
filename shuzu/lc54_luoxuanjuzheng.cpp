//
// Created by 11751 on 2023/11/23.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int k = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int t = 0;
        int b = m-1;
        int l = 0;
        int r = n-1;

        while(k < m*n){
            for(int i = l;i <= r&& k < m*n;i++,k++) ans.push_back(matrix[t][i]);
            t++;
            for(int i = t;i <= b&& k < m*n;i++,k++) ans.push_back(matrix[i][r]);
            r--;
            for(int i = r;i >= l&& k < m*n;i--,k++) ans.push_back(matrix[b][i]);
            b--;
            for(int i = b;i >= t&& k < m*n;i--,k++) ans.push_back(matrix[i][l]);
            l++;
        }
        //增加一个判断条件 &&k < m*n

        return ans;
    }
};

/*
int main(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s = Solution();
    vector<int> ans = s.spiralOrder(vec);
    for(const auto& c:ans){
        cout<<c;
    }
}
 */
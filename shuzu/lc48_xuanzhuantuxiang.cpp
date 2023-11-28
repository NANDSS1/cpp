//
// Created by 11751 on 2023/11/23.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> newMatrix(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                newMatrix[i][j] = matrix[j][i];
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n/2;j++){
                swap(newMatrix[i][j],newMatrix[i][n-1-j]);
            }
        }


        matrix = newMatrix;
//能过就行
    }
};
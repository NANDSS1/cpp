//
// Created by 11751 on 2023/11/23.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];//行 第一个9是9行，第二个9是9个元素的hash映射
        int column[9][9];//列
        int subBox[3][3][9];//3x3子块
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));
        memset(subBox,0,sizeof(subBox));
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.') {
                    int index = board[i][j] - '1';
                    row[i][index]++;
                    column[j][index]++;
                    subBox[i / 3][j / 3][index]++;//第几个子块
                    if (row[i][index] > 1 || column[j][index] > 1 || subBox[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }

        }

        return true;
    }
};



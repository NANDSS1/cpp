//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;

class Solution {
//回溯
private:
    bool flag = false;//定义一个全局变量操作很方便其实
    int sum = 0;
public:
    void backtracking(TreeNode* node,int sum,int targetSum){
        //终止条件
        if(node->left == nullptr && node->right == nullptr){
            //搜到叶子结点了
            if(sum > targetSum) return;
            else if(sum == targetSum) flag = true;
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return flag;
        backtracking(root,root->val,targetSum);

        return flag;
    }
};
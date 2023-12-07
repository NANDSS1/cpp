//
// Created by 11751 on 2023/12/4.
//
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //层序遍历，直接秒
        TreeNode* ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = que.front();
                if(i == 0) ans = node;
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
                que.pop();
            }
        }

        return ans->val;
    }
};
//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //层序遍历
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node->left != nullptr) {
                // 检查节点是否是叶子节点
                if(node->left->left == nullptr && node->left->right == nullptr) {
                    ans += node->left->val;
                } else {
                    que.push(node->left);
                }
            }
            if(node->right != nullptr) {
                que.push(node->right);
            }
        }

        return ans;
    }
};


/*
 //首先要注意是判断左叶子，不是二叉树左侧节点，所以不要上来想着层序遍历。
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //层序遍历
        if(root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty()){
            if(que.front()->left != nullptr) ans += que.front()->left->val;//保证加的左节点的值，而不是左视图的值
            int size = que.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = que.front();
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
                que.pop();
            }
        }
        //ans -= root->val;

        return ans;
    }
};
 */
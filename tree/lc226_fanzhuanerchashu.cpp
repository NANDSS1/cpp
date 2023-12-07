//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    void traversal(TreeNode* node){
        if(node == nullptr) return;
        //处理中间节点
        swap(node->left,node->right);
        traversal(node->left);
        traversal(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        //中左右 前序遍历
        if(root == nullptr) return nullptr;
        traversal(root);
        return root;
    }
};
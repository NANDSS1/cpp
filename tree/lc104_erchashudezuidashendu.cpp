//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int traversal(TreeNode* node){
        if(node == nullptr) return 0;
        //后序遍历
        int left = traversal(node->left);
        int right = traversal(node->right);
        //后序遍历会先遍历到nullptr

        int len = max(left,right)+1;

        return len;
    }
    int maxDepth(TreeNode* root) {
        /*给定一个二叉树 root ，返回其最大深度。
        二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。*/
        //后序遍历？？？,左右两个子节点收集信息往父节点传
        return traversal(root);

    }
};
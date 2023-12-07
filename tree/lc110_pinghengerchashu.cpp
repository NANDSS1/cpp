//
// Created by 11751 on 2023/12/4.
//
#include "TreeNode.h"
using namespace std;

/*给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。*/
class Solution {
public:
    int traversal(TreeNode* node){
        //traversal返回的是当前结点的最高高度，所以采取后序遍历
        //需要判断左子节点和右子节点，然后返回给当前结点做判断
        if(node == nullptr) return 0;
        int left = traversal(node->left);
        int right = traversal(node->right);

        if(left == -1 || right == -1) return -1;
        if(abs(right-left) > 1) return -1;

        //现在平衡，直接返回当前结点高度
        int height = max(right,left)+1;

        return height;
    }
    bool isBalanced(TreeNode* root) {
        //后序遍历！！！
        //先遍历到最底部，然后在返回信息给父节点
        int flag = traversal(root);
        if(flag == -1) return false;
        else return true;

    }
};
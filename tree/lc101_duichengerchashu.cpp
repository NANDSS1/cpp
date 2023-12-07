//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    bool traversal(TreeNode* left,TreeNode* right){//这里的left是指左边父节点的一个子节点，right是指右边父节点的一个子节点
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val) return false;

        //还要判断这个两个子节点下面的节点是否对称，耦合关系
        //函数能走到这里，证明两个节点都是非空而且值不相等的
        bool inside = (left->right,right->left);
        bool outside = (left->left,right->right);

        return inside&&outside;//向父节点报告
    }
    bool isSymmetric(TreeNode* root) {
        //后序遍历？把结果传给上一层结点
        if(root == nullptr) return true;
        return traversal(root->left,root->right);
    }
};
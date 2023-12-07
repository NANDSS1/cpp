//
// Created by 11751 on 2023/12/4.
//
#include"TreeNode.h"
using namespace std;
/*给你一个二叉树的根节点 root ，按任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。*/
class Solution {
private:
    vector<string> res;
public:
    void backtracking(string path,TreeNode* node){
        path += to_string(node->val);
        if(node->left == nullptr && node->right == nullptr)
        {
            res.push_back(path);
            return;
        }

        if(node->left) backtracking(path+"->",node->left);//在这里加->
        if(node->right) backtracking(path+"->",node->right);//在这里加->
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        backtracking(path,root);

        return res;
    }
};
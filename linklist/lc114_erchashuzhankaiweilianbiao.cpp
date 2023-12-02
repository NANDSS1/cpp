//
// Created by 11751 on 2023/11/30.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include"TreeNode.h"
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //先序号遍历，中左右
    vector<TreeNode*> vec;
    void reversal(TreeNode* node){
        if(node == nullptr) return;
        if(node != nullptr) vec.push_back(node);
        reversal(node->left);
        reversal(node->right);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        reversal(root);
        for(int i = 0;i < vec.size()-1;i++){
            vec[i]->right = vec[i+1];
            vec[i]->left = nullptr;
        }
        vec.back()->left = nullptr;
        vec.back()->right = nullptr;
    }
};

/*
int main(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    Solution s;
    s.flatten(node1);
    TreeNode* node = node1;
    while(node != nullptr){
        cout<<node->val<<endl;
        node = node->right;
    }


}

*/
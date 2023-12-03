//
// Created by 11751 on 2023/12/3.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //用栈模拟递归
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr) return res;
        //先把根结点压入栈
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            //收集栈顶结果
            res.push_back(node->val);
            if(node->right != nullptr) st.push(node->right);
            if(node->left != nullptr) st.push(node->left);
        }
        return res;

    }
};
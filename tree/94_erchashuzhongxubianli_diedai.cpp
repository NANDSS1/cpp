//
// Created by 11751 on 2023/12/3.
//
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur != nullptr){
            if(cur != nullptr){
                //一直访问到最底部
                st.push(cur);
                cur = cur->right;
            }else{
                //访问到底了，开始返回
                cur = st.top();
                st.pop();
                res.push_back(cur->val);//中
                cur = cur->left;//左
            }
        }

        return res;
    }
};
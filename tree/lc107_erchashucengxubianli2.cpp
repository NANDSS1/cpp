//
// Created by 11751 on 2023/12/3.
//
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root ==nullptr) return{};

        queue<TreeNode*> que;
        TreeNode* cur = root;
        que.push(root);
        vector<vector<int>> ans;
        while(!que.empty()){
            int size = que.size();
            vector<int> path;
            for(int i = 0;i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                path.push_back(temp->val);
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }
            ans.push_back(path);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
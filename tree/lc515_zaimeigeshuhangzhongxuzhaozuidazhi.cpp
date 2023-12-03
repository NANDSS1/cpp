//
// Created by 11751 on 2023/12/3.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        vector<int> ans;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            int maxNum = INT_MIN;
            for(int i = 0;i < size;i++){
                TreeNode* temp = que.front();
                que.pop();
                maxNum = max(temp->val,maxNum);
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }
            ans.push_back(maxNum);
        }

        return ans;
    }
};
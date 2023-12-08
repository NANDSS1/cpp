//
// Created by 11751 on 2023/12/7.
//
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    vector<TreeNode*> vec;
public:
    void traversal(TreeNode* root){
        if(root == nullptr);
        //中序遍历
        traversal(root->left);
        vec.push_back(root);
        traversal(root->right);

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        traversal(root);
        TreeNode* node = new TreeNode(val);
        for(int i = 0;i < vec.size();i++) {
            if (val >= vec[i]->val) {
                vec.insert(vec.begin() + i + 1, node);
                break;
            }
        }

    }

};
//
// Created by 11751 on 2023/12/8.
//
#include "TreeNode.h"
using namespace std;

class Solution {
private:
    vector<TreeNode*> vec;
    void traversal(TreeNode* node){
        //中序遍历
        if(node == nullptr) return;
        traversal(node->left);
        vec.push_back(node);
        traversal(node->right);

        return;
    }
    TreeNode* createBST(int left,int right){
        //终止条件
        if(left > right) return nullptr;

        //前序遍历构建BST
        int mid = (left+right)/2;
        vec[mid]->left = createBST(left,mid-1);
        vec[mid]->right = createBST(mid+1,right);

        return vec[mid];
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        traversal(root);//建立好升序vector

        auto it = vec.begin();
        while (it != vec.end()) {
            if ((*it)->val < low || (*it)->val > high) {
                it = vec.erase(it);
            } else {
                ++it;
            }
        }
        /*
        for(int i = 0;i < vec.size();i++){
            if(vec[i]->val > high || vec[i]->val < low) vec.erase(vec.begin()+i);//i会变的，不能这样删除,如果两个要删除的元素是连续的就会漏掉，第一个元素在2索引，删掉后，第二个元素来了2索引，但是现在循环进入3索引了
        }*/


        TreeNode* node = createBST(0,vec.size()-1);

        return node;


    }
};

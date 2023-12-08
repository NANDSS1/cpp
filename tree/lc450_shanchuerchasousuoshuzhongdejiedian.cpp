//
// Created by 11751 on 2023/12/8.
//
#include"TreeNode.h"
using namespace std;
class Solution {
private:
    vector<TreeNode*> vec;
public:
    void traversal(TreeNode* node){
        if(node == nullptr) return;
        //中序遍历
        traversal(node->left);
        vec.push_back(node);
        traversal(node->right);
        return;
    }

    TreeNode* createBST(int left,int right){
        if(left > right) return nullptr;
        //前序遍历
        //找到中节点
        int mid = (left+right)/2;

        vec[mid]->left = createBST(left, mid - 1);
        vec[mid]->right = createBST(mid + 1, right);

        /*
        vec[mid]->left = createBST(mid+1,vec.size()-1);
        vec[mid]->right = createBST(0,mid-1);
*/

        return vec[mid];

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        traversal(root);
        for(int i = 0;i < vec.size();i++){
            if(key == vec[i]->val) vec.erase(vec.begin()+i);
        }
        //擦除完成，然后需要重新建立一个BST

        TreeNode* node = createBST(0,vec.size());

        return node;

    }
};
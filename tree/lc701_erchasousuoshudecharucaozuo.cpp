//
// Created by 11751 on 2023/12/8.
//
//不管大小，插入到尾结点就行
#include"TreeNode.h"
using namespace std;

//搜到底插入就行了！！！！ 不论大小，只需要插入的时候判断和父节点的位置，这样都符合BST的规则
class Solution {
public:
    void traversal(TreeNode* cur,TreeNode* parent,int val){
        //后序遍历，先搜到底
        if(cur == nullptr){
            //创建一个新的结点
            TreeNode* node = new TreeNode(val);
            if(val > parent->val){
                //放右边
                parent->right = node;
                return;
            }
            if(val <= parent->val){
                //放左边
                parent->left = node;
                return;
            }
        }
        parent = cur;
        if(val > cur->val) traversal(cur->left,parent,val);
        else traversal(cur->right,parent,val);

        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);

        traversal(root, nullptr,val);

        return root;

    }
};

//
// Created by 11751 on 2023/12/6.
//
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    //用返回值带着结点的信息往上面传
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == q || root == p || root == NULL) return root;//如果p被返回，q是p的子节点(这种情况答案就是p)，这种情况搜不到q，但是会一直返回p，相当于把答案找到了
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;

        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else  { //  (left == NULL && right == NULL)
            return NULL;
        }

    }
};

/*
class Solution {
private:
    TreeNode* ans;
    TreeNode* node1;
    TreeNode* node2;
public:
    bool traversal(TreeNode* node) {
        if (node == nullptr) return false;

        bool leftFlag = traversal(node->left);
        bool rightFlag = traversal(node->right);

        if ((leftFlag && rightFlag) || (node == node1 || node == node2)) {
            ans = node;//有一个节点找到ans就会被更新，但是最终会被找到两个节点的ans覆盖 ans更新四种情况 1、下面都没找到 ans有一个 2、下面找到了一个 ans有一个 3、下面都找到了。1会被2覆盖的，所以这个逻辑没事
            return true;
        }

        return leftFlag || rightFlag;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        node1 = p;
        node2 = q;

        traversal(root);

        return ans;
    }
};
 */
/*
class Solution {
private:
    TreeNode* ans;
    TreeNode* node1;
    TreeNode* node2;
public:
    bool traversal(TreeNode* node){
        //后序遍历
        if(node == node1 && node == node2) return true;//这个没必要，是要搜索到底的，万一node1 node2全在一条路径上呢，node1在上面，node2在下面
        if(node == nullptr) return false;
        bool leftFlag = traversal(node->left);
        bool rightFlag = traversal(node->right);

        //处理中结点逻辑
        if(leftFlag&&rightFlag == true) ans = node;//左子树右子树分别找到一个
        else if((leftFlag||rightFlag == true) && (node == node1 || node == node2)) ans = node;//左子树或者右子树找到一个 自己也是一个
        else return leftFlag||rightFlag;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        node1 = p;
        node2 = q;

        return ans;
    }
};
 */
//
// Created by 11751 on 2023/12/4.
//
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int traversal(TreeNode* node) {
        //后序遍历，先遍历到底
        if (node == nullptr) return 0;
        int left = traversal(node->left);
        int right = traversal(node->right);

        int len = 0;
        //需要规避子节点是空节点的情况，如果是空节点，不能比较大小！！
        if (left == 0) len = right + 1;
        else if (right == 0) len = left + 1;
        else if (left != 0 && right != 0) len = min(left, right)+1;

        return len;

    }

    int minDepth(TreeNode* root) {
        return traversal(root);

    }
};
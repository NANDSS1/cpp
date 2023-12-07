#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //终止条件
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        //如果都是空节点，那么返回的就是一个空结点

        //前序遍历，以node1为主干
        root1->val += root2->val;
        mergeTrees(root1->left,root2->left);
        mergeTrees(root1->right,root2->right);

        return root1;
    }
};
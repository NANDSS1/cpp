//
// Created by 11751 on 2023/12/3.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //用栈模拟递归
        stack<TreeNode*> st;
        vector<int> res;
        if(root == nullptr) return res;
        //先把根结点压入栈
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            //收集栈顶结果
            res.push_back(node->val);
            if(node->right != nullptr) st.push(node->left);
            if(node->left != nullptr) st.push(node->right);
        }

        reverse(res.begin(),res.end());
        return res;

    }
};

/*再来看后序遍历，先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，
 就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了，如下图：*/
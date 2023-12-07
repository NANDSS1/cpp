//
// Created by 11751 on 2023/12/6.
//
#include"TreeNode.h"
using namespace std;
/*
 * 这是对普通二叉树的做法
class Solution {
private:
    vector<int> vec;
public:
    void traversal(TreeNode* node){
        //前序遍历
        if(node == nullptr) return;
        vec.push_back(node->val);
        traversal(node->left);
        traversal(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int ans = INT_MAX;
        for(int i = 0;i < vec.size()-1;i++){
            for(int j = i+1; j < vec.size();j++){
                ans = min(ans, abs(vec[j]-vec[i]));
            }
        }

        return ans;

    }
};
 */

/*
 *本题是二叉搜索树，直接中序遍历就会变成升序的
 * */
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* node){
        if(node == nullptr) return;
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        //vec升序的
        int ans = INT_MAX;
        for(int i = 0;i < vec.size()-1;i++){
            ans = min(ans,abs(vec[i+1]-vec[i]));
        }
        //时间复杂度降低到o(n)
        return ans;

    }
};
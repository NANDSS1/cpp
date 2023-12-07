//
// Created by 11751 on 2023/12/5.
//
#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //前序遍历，递归方式构造
        int maxIndex = 0;
        int maxNum = nums[0];

        for(int i = 0;i < nums.size();i++){
            if(maxNum < nums[i]){
                maxIndex = i;
                maxNum = nums[i];
            }
        }
        TreeNode* node = new TreeNode(maxNum);
        if(maxIndex > 0){//左边还有元素
            vector<int> tempVec(nums.begin(),nums.begin()+maxIndex);//右边那个是一个哨兵指针
            node->left = constructMaximumBinaryTree(tempVec);
        }
        if(maxIndex < nums.size()-1){//右边还有元素
            vector<int> tempVec(nums.begin()+maxIndex+1,nums.end());
            node->right = constructMaximumBinaryTree(tempVec);
        }

        return node;
    }
};
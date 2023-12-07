//
// Created by 11751 on 2023/12/6.
//
#include "TreeNode.h"
using namespace std;
class Solution {
private:
    unordered_map<int,int> hashmap;
public:
    void traversal(TreeNode* node){
        //遍历方式无所谓的，那就中序吧
        if(node == nullptr) return;
        traversal(node->left);
        hashmap[node->val]++;
        traversal(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        int ans = 0;
        for(const auto& p:hashmap){
            ans = max(p.second,ans);//ans记录最大出现次数
        }
        vector<int> res;
        for(const auto& p:hashmap){
            if(ans == p.second) res.push_back(p.first);//first记录元素
        }
        return res;
    }
};
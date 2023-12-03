//
// Created by 11751 on 2023/12/3.
//
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        queue<Node*> que;
        que.push(root);
        vector<vector<int>> ans;
        while(!que.empty()){
            vector<int> path;
            int size = que.size();//path一次只收集一层的结果
            for(int i = 0;i < size;i++){
                Node* node = que.front();
                que.pop();
                path.push_back(node->val);
                for(int j = 0;j < node->children.size();j++){
                    if(node->children[j] != nullptr) que.push(node->children[j]);
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};
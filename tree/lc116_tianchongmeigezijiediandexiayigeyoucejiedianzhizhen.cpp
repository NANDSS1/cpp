//
// Created by 11751 on 2023/12/3.
//

#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();//记录每层的个数
            for(int i = 0;i < size;i++){
                Node* temp = que.front();
                que.pop();
                if(i < size-1){
                    temp->next = que.front();
                }
                if(temp->left != nullptr) que.push(temp->left);
                if(temp->right != nullptr) que.push(temp->right);
            }
        }

        return root;

    }
};
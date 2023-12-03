//
// Created by 11751 on 2023/11/30.
//

#ifndef CPP_TREENODE_H
#define CPP_TREENODE_H
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    //列表赋值
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){};
};
#endif //CPP_TREENODE_H

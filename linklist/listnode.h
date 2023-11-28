//
// Created by 11751 on 2023/11/25.
//

#ifndef CPP_LISTNODE_H
#define CPP_LISTNODE_H
struct ListNode{
    int val;
    ListNode* next;

    ListNode():val(0),next(nullptr){};
    ListNode(int v):val(v),next(nullptr){};
};

#endif //CPP_LISTNODE_H

//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
#include"listnode.h"
using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        while(curA != nullptr){
            curA = curA->next;
            lenA++;
        }
        while(curB != nullptr){
            curB = curB->next;
            lenB++;
        }
        int len = abs(lenA-lenB);
        curA = headA;
        curB = headB;
        if(lenA < lenB) swap(curA,curB);//保证A是长的
        while(len--){
            curA = curA->next;
        }
        while(curA!= nullptr&&curB!= nullptr){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
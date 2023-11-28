//
// Created by 11751 on 2023/11/25.
//
#include<bits/stdc++.h>
#include"listnode.h"
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;

    }
};


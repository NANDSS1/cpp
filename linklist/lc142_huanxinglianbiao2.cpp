//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
#include"listnode.h"
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //hash表是最快的
        unordered_set<ListNode*> hashset;
        ListNode* cur = head;
        while(true){
            if(cur == nullptr) break;
            if(!hashset.count(cur)) {
                hashset.insert(cur);
                cur = cur->next;
            }
            else return cur;
        }
        return nullptr;
    }
};
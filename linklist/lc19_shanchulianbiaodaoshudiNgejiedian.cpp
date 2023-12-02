//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
#include"listnode.h"
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while(n--){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummyHead->next;
    }
};
/*
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    //node1->next = node2;
    //node2->next = node3;

    Solution s;
    s.removeNthFromEnd(node1,1);
    ListNode* cur = node1;
    while(cur != nullptr){
        cout<<cur->val<<endl;
        cur = cur->next;
    }
}
*/
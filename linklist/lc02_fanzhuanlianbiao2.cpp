//
// Created by 11751 on 2023/11/28.
//
#include"listnode.h"
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* node1 = head;
        ListNode* node2 = head;
        while(node1->val != left){
            prev = prev->next;
            node1 = node1->next;
        }
        while(node2->val != right){
            node2 = node2->next;
        }
        vector<ListNode*> vec;
        while(node1->val != right){
            //cout<<node1->val;
            vec.push_back(node1);
            node1 = node1->next;
        }
        vec.push_back(node1);
        //cout<<node1->val;
        reverse(vec.begin(),vec.end());

        for(int i = 0;i < vec.size();i++){
            prev->next = vec[i];
            cout<<vec[i]->val;
            prev = prev->next;
        }
        prev = node2->next;
        return head;
    }
};

/*
int main(){
    ListNode* dummyHead = new ListNode();
    ListNode* cur = dummyHead;
    vector<int> vec = {1,2,3,4,5};
    for(int i = 0;i < vec.size();i++){
        ListNode* node = new ListNode(vec[i]);
        cur->next = node;
        cur = cur->next;
    }

    cur = dummyHead->next;
    while(cur){
        cout<<cur->val<<endl;
        cur = cur->next;
    }

    int left = 2;
    int right = 4;
    Solution s = Solution();
    s.reverseBetween(dummyHead->next,left,right);
    cur = dummyHead->next;
    while(cur!= nullptr){
        cout<<cur->val<<endl;
        cur = cur->next;
    }
    cout<<"hello";
}

*/
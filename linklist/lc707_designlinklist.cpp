//
// Created by 11751 on 2023/11/24.
//
#include<bits/stdc++.h>
#include<listnode.h>
using namespace std;

class MyLinkedList {
public:
    ListNode* dummyHead;
    MyLinkedList() {
        ListNode* node = new ListNode();
        dummyHead = node;
    }

    int get(int index) {
        ListNode* temp = dummyHead->next;
        while(index > 0 && temp != nullptr){
            temp = temp->next;
            index--;
        }
        if(temp == nullptr) return -1; // 返回-1表示索引超出范围
        return temp->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
    }

    void addAtTail(int val) {
        ListNode* temp = dummyHead;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        ListNode* node = new ListNode(val);
        temp->next = node;
    }

    void addAtIndex(int index, int val) {
        ListNode* temp = dummyHead;
        while(index > 0 && temp != nullptr){
            temp = temp->next;
            index--;
        }
        if(temp == nullptr) return; // 如果索引超出范围，不进行任何操作
        ListNode* node = new ListNode(val);
        node->next = temp->next;
        temp->next = node;
    }

    void deleteAtIndex(int index) {
        ListNode* temp = dummyHead;
        while(index > 0 && temp != nullptr){
            temp = temp->next;
            index--;
        }
        if(temp == nullptr || temp->next == nullptr) return; // 如果索引超出范围，不进行任何操作
        temp->next = temp->next->next;
    }
};


int main(){
    string[] str = {"MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"};
    [[], [1], [3], [1, 2], [1], [1], [1]]
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


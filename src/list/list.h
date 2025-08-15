#ifndef LIST_H
#define LIST_H

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};


#endif
#include "list/list.h"

/*
! 328. 奇偶链表
中等
相关标签
premium lock icon
相关企业
给定单链表的头节点 head
，将所有索引为奇数的节点和索引为偶数的节点分别分组，保持它们原有的相对顺序，然后把偶数索引节点分组连接到奇数索引节点分组之后，返回重新排序的链表。

第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。

请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。

你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。


*/
class Solution328 {
    ListNode* event_head = nullptr;
    ListNode* event_tail = nullptr;
    ListNode* odd_tail = nullptr;

   public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* opt = head;
        while (opt) {
            ListNode* delete_node = deleteNode(opt);
            if (!event_head) {
                event_head = delete_node;
                event_tail = event_head;
            } else {
                event_tail->next = delete_node;
                event_tail = delete_node;
            }
            if (!opt->next) {
                odd_tail = opt;
            }
            opt = opt->next;
        }

        if (!odd_tail) {
            odd_tail->next = event_head;
        }

        return head;
    }
    // 删除opt后的Node
    ListNode* deleteNode(ListNode* opt) {
        if (opt->next) {
            ListNode* node = opt->next;
            opt->next = node->next;
            node->next = nullptr;
            return node;
        }

        return nullptr;
    }
};
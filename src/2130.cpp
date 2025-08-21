// #include <list/list.h>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 方案:
// 将2n个节点的链表,分成两个n节点的链表,即从中间位置将链表截断,命名两个链表为
// first 和 second; 将second链表节点翻转变为链表third, 将 first 中第idx个元素与
// third 中第idx个元素相加求和,返回和中最大的,即题目返回值.
// 再将third链表翻转变为 second,最后将first和second链接起来将链表恢复

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution2130 {
   public:
    int pairSum(ListNode* head) {
        // 1. 找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 反转后半部分
        ListNode* second = reverse(slow);

        // 3. 遍历两段，计算最大 twin sum
        int max_sum = 0;
        ListNode* opt1 = head;
        ListNode* opt2 = second;
        while (opt2) {  // 后半段长度 <= 前半段
            max_sum = max(max_sum, opt1->val + opt2->val);
            opt1 = opt1->next;
            opt2 = opt2->next;
        }

        // （可选）还原链表
        // reverse(second);

        return max_sum;
    }

   private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};
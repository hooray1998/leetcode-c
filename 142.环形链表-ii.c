/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    // NOTE: 第一圈一定能追上
    struct ListNode *fast, *slow;
    slow = head->next;
    fast = slow->next;

    while(fast != slow && fast && slow && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL || fast->next == NULL){
        return NULL;
    }

    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
// @lc code=end


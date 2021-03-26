/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
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
        return false;
    }
    return true;
    
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL){
        return head;
    }
    struct ListNode *p1, *p2;
    p1 = p2 = head;
    while(n--){
        p2 = p2->next;
    }
    if(p2 == NULL){
        return head->next;
    }

    while(p2->next){
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;
    return head;
}
// @lc code=end


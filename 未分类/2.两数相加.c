/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1 = l1, *p2 = l2, *temp, *ret=NULL, *head;
    int sum = 0;
    int upgrade = 0;

    head = ret = malloc(sizeof(struct ListNode)); // 至少一个节点

    while (l1 && l2)
    {
        ret->next = malloc(sizeof(struct ListNode));
        ret = ret->next;
        ret->next = NULL;

        sum = l1->val + l2->val + upgrade;
        ret->val = sum%10;
        upgrade = sum/10;
        l1 = l1->next;
        l2 = l2->next;

    }
    if(l1){
        ret->next = l1;
    }
    while(ret->next){
        ret = ret->next;

        sum = ret->val + upgrade;
        ret->val = sum%10;
        upgrade = sum/10;
    }
    
    if(l2){
        ret->next = l2;
    }
    while(ret->next){
        ret = ret->next;

        sum = ret->val + upgrade;
        ret->val = sum%10;
        upgrade = sum/10;
    }
    if(upgrade){
        ret->next = malloc(sizeof(struct ListNode));
        ret = ret->next;
        ret->next = NULL;
        ret->val = upgrade;

    }

    return head->next;

}
// @lc code=end


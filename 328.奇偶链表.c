/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *p1, *p2, *p3;
    p1 = head;
    p2 = head;
    p3 = head->next;

    while(p2 && p2->next){
        p2 = p2->next;
        p1->next = p2->next;
        if(p1->next == NULL) break;
        p1 = p1->next;
        p2->next = p1->next;
    }
    p1->next = p3;
    return head;
}
// @lc code=end


int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Node *head = NULL, *tmp;
    head = malloc(sizeof(Node));
    head->next = NULL;
    tmp = head;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        tmp->next = malloc(sizeof(Node));
        tmp->next->val = a[i];
        tmp->next->next = NULL;
        tmp = tmp->next;
    }

    tmp = oddEvenList(head->next);
    // tmp = head->next;
    while(tmp){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }

    return 0;
}
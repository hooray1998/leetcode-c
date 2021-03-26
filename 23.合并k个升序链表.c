/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// TODO: 全部讲列表插入优先级队列中, 然后逐个读取即可, 比较的方式是比较火车头
//3.堆排序
void HeapBuild(struct ListNode** A, int len){ //建堆
    for(int i=len/2-1; i>=0; i--){
        HeapAdjust(A, i, len);
    }
}
void HeapAdjust(struct ListNode** A, int k, int len){//堆调整
    struct ListNode *swap = NULL;
    for(int i=2*k+1; i<len; i=2*i+1){
        if(i+1<len && A[i+1]->val<A[i]->val){
            i++;
        }
        if(A[k]->val<=A[i]->val){
            break;
        }
        else{
            swap = A[k];
            A[k] = A[i];
            A[i] = swap;
            k = i;
        }
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode **heap = malloc(listsSize*sizeof(struct ListNode));
    struct ListNode *head = malloc(sizeof(struct ListNode)), *tail = head;
    head->next = NULL;
    int i, j=0, k = listsSize;
    for(i=0; i<k; i++){               //去除空指针，建堆
        if(!lists[i]){
            listsSize--;
        }
        else{
            heap[j++] = lists[i];
        }
    }
    while(listsSize){
        HeapBuild(heap, listsSize);     //反复调整为小顶堆
        tail->next = heap[0];
        tail = tail->next;
        if(heap[0]->next){
            heap[0] = heap[0]->next;
        }
        else{             //heap[0]->next空，将堆最后一个链表放到堆顶
            listsSize--;
            heap[0] = heap[listsSize];
        }
    }
    return head->next;
}

// @lc code=end


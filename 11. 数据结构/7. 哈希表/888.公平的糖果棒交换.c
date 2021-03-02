/*
 * @lc app=leetcode.cn id=888 lang=c
 *
 * [888] 公平的糖果棒交换
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct  HashTable{
    int x;
    UT_hash_handle hh;
};

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
    int sumA = 0, sumB = 0;
    for(int i=0;i<ASize;i++){
        sumA += A[i];
    }
    for(int i=0;i<BSize;i++){
        sumB += B[i];
    }

    int delta = (sumA - sumB) / 2;
    struct HashTable* hashTable = NULL;
    for(int i=0;i<ASize;i++){
        struct HashTable* tmp;
        HASH_FIND_INT(hashTable, &A[i], tmp);
        if(tmp == NULL){
            tmp = malloc(sizeof(struct HashTable));
            tmp->x = A[i];
            HASH_ADD_INT(hashTable, x, tmp);
        }
    }
    int *ans = malloc(sizeof(int ) * 2);
    *returnSize = 2;
    for(int i=0;i<BSize;i++){
        int x = B[i] + delta;
        struct HashTable *tmp;
        HASH_FIND_INT(hashTable, &x, tmp);
        if(tmp != NULL){
            ans[0] = x, ans[1] = B[i];
            break;
        }
    }
    return ans;
}


// @lc code=end


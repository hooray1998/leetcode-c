/*
 * @lc app=leetcode.cn id=128 lang=c
 *
 * [128] 最长连续序列
 * 
 * NOTE: 所有数据插入hash表, 任选数字删除前后连续数据, 不断的更新最大值即可
 * 
 * NOTE: 
 * 1. hash表类似链表, 第一个节点就是hashTable指针所指向的内容, 
 * 2. 理解handle的作用
 * 3. 熟练使用hash操作
 */

// @lc code=start

struct HashTable
{
    int number;
    UT_hash_handle hh;
};


int longestConsecutive(int* nums, int numsSize){
    int max = 0;
    struct HashTable *hashTable = NULL, *tmp, *s, *tmp2;
    for(int i=0;i<numsSize;i++){
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp == NULL){
            tmp = malloc(sizeof(struct HashTable));
            tmp->number = nums[i];
            HASH_ADD_INT(hashTable, number, tmp);
        }
    }
    printf("count:%d\n", HASH_COUNT(hashTable));
    for(struct HashTable* h = hashTable; h != NULL; h=h->hh.next){
        printf("for: %d \n", h->number);
    }

    int cur, curLen, i;
    while(hashTable){
        s = hashTable;
        cur = s->number;
        printf("cur:%d\n", cur);
        HASH_DEL(hashTable, s);
        curLen = 1;

            i = cur-1;
            HASH_FIND_INT(hashTable, &i, tmp2);
            while(tmp2 !=NULL){
                HASH_DEL(hashTable, tmp2);
                ++ curLen;
                printf("i:%d\n", i);
                --i;
                HASH_FIND_INT(hashTable, &i, tmp2);
            }

            i = cur+1;
            HASH_FIND_INT(hashTable, &i, tmp2);
            while(tmp2 !=NULL){
                HASH_DEL(hashTable, tmp2);
                ++ curLen;
                printf("i:%d\n", i);
                ++i;
                HASH_FIND_INT(hashTable, &i, tmp2);
            }

        if(curLen > max){
            max = curLen;
        }
    };

    return max;

}
// @lc code=end


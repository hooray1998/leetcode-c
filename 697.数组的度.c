/*
 * @lc app=leetcode.cn id=697 lang=c
 *
 * [697] 数组的度
 */

// @lc code=start

typedef struct{
    int id;
    int count;
    int start;
    int range;
    UT_hash_handle hh;
}HashTable;

HashTable* Add(HashTable **table, int id, int i)
{
    HashTable *tmp;
    HASH_FIND_INT(*table, &id, tmp);
    if(tmp == NULL){
        tmp = malloc(sizeof(HashTable));
        tmp->id = id;
        tmp->count = 0;
        tmp->start = i;
        HASH_ADD_INT(*table, id, tmp);
    }
    tmp->count += 1;
    tmp->range = i - tmp->start + 1;
    return tmp;
}
int cmp(HashTable *a, HashTable *b)
{
    if(a->count == b->count){
        return a->range - b->range;
    }else{
        return b->count - a->count;
    }

}


int findShortestSubArray(int* nums, int numsSize){
    int maxCount = INT_MIN, maxNumber = 0;
    HashTable *tmp, *cur, *table = NULL;
    int start = -1, end;

    for (int i = 0; i < numsSize; i++) {
        tmp = Add(&table, nums[i], i);
    }

    HASH_SORT(table, cmp);
    // for(tmp = table; tmp != NULL; tmp = tmp->hh.next){
    //     printf("%d = %d %d\n", tmp->id, tmp->count, tmp->range);

    // }
    return table->range;
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=560 lang=c
 *
 * [560] 和为K的子数组 @hash @前缀和
 */

// @lc code=start

typedef struct {
    int sum;
    int count;
    UT_hash_handle hh;         /* makes this structure hashable */
} HashTable;

HashTable* Get(HashTable **hashTable, int sum)
{
    // printf("Get:%d", sum);
    HashTable *tmp;
    HASH_FIND_INT(*hashTable, &sum, tmp);
    if (tmp == NULL){
        tmp = malloc(sizeof(HashTable));
        tmp->sum = sum;
        tmp->count = 0;
        HASH_ADD_INT(*hashTable, sum, tmp);
        // printf("hash add%d\n", tmp->count);
    }
    // printf("return:%d\n", tmp->count);
    // printf("len:%d\n", HASH_COUNT(*hashTable));
    return tmp;
}


int subarraySum(int* nums, int numsSize, int k)
{
    HashTable *table = NULL;
    HashTable *tmp;
    int sum = 0, need;
    int ans = 0;

    tmp = Get(&table, 0);
    tmp->count = 1;

    for (int i = 0; i < numsSize; i++){
        sum += nums[i];

        need = sum - k;
        tmp = Get(&table, need);
        ans += tmp->count;

        tmp = Get(&table, sum);
        tmp->count += 1;
    }

    return ans;
}
// @lc code=end


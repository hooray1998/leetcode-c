/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 */

// @lc code=start

typedef struct {
    int id;
    UT_hash_handle hh;         /* makes this structure hashable */
}HashTable;

HashTable* Insert(HashTable **table, int id)
{
    HashTable *tmp;
    HASH_FIND_INT(*table, &id, tmp);
    if(tmp){
        return NULL;
    }
    tmp = malloc(sizeof(HashTable));
    tmp->id = id;
    HASH_ADD_INT(*table, id, tmp);
    return tmp;
}

bool containsDuplicate(int* nums, int numsSize){
    HashTable *table = NULL;
    for (int i = 0; i < numsSize; i++) {
        if(Insert(&table, nums[i]) == NULL){
            return true;
        }
    }
    return false;
}
// @lc code=end


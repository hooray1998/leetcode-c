/*
 * @lc app=leetcode.cn id=594 lang=c
 *
 * [594] 最长和谐子序列
 */

// @lc code=start

typedef struct {
    int id;
    int count;
    UT_hash_handle hh;
}HashTable;

void Add(HashTable **table, int id)
{
    HashTable *tmp;
    HASH_FIND_INT(*table, &id, tmp);
    if(tmp == NULL){
        tmp = malloc(sizeof(HashTable));
        tmp->id = id;
        tmp->count = 0;
        HASH_ADD_INT(*table, id, tmp);
    }
    tmp->count += 1;
}


int Get(HashTable **table, int id)
{
    HashTable *tmp;
    HASH_FIND_INT(*table, &id, tmp);
    if(tmp == NULL){
        return 0;
    }else{
        return tmp->count;
    }
}

int findLHS(int* nums, int numsSize){

    if(nums == NULL || numsSize <= 1){
        return 0;
    }
    HashTable *table = NULL, *tmp, *cur = NULL;
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        Add(&table, nums[i]);
    }
    int front, back;

    for(cur = table; cur != NULL; cur = cur->hh.next){
        front = Get(&table, cur->id - 1);
        back = Get(&table, cur->id + 1);
        if( front != 0 && (front + cur->count) > max){
            max = front + cur->count;
        }else if(back != 0 &&  (back + cur->count) > max){
            max = back + cur->count;
        }
    }
    return (max == INT_MIN)? 0: max;
    

}
// @lc code=end


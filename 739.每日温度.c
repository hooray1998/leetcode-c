/*
 * @lc app=leetcode.cn id=739 lang=c
 *
 * [739] 每日温度
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* nums, int numsSize, int* returnSize){
    // 维护一个单调递减的栈即可
    // 如果当前的比栈顶大, 则更新栈顶对应的位置为当前的日期,

    if(nums == NULL || numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    int index;
    int *ret = malloc(sizeof(int) * numsSize);
    int *stack = malloc(sizeof(int) * numsSize);
    int size = 0;

    memset(ret, 0, sizeof(int) * numsSize);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        while(size !=0 && nums[stack[size-1]] < nums[i]){
            -- size;
            ret[stack[size]] = i - stack[size];
        }
        stack[size ++ ] = i;
    }
    return ret;

}


// @lc code=end


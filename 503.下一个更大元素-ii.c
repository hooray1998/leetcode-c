/*
 * @lc app=leetcode.cn id=503 lang=c
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    int index;
    int *ret = malloc(sizeof(int) * numsSize);
    int *stack = malloc(sizeof(int) * numsSize);
    int size = 0;

    *returnSize = numsSize;
    // NOTE: 第一遍先把能更新的更新一下
    for (int i = 0; i < numsSize; i++)
    {
        ret[i] = -1;
        while(size !=0 && nums[stack[size-1]] < nums[i]){
            -- size;
            ret[stack[size]] = nums[i];
        }
        stack[size ++ ] = i;
    }

    // NOTE: 第二遍只出栈, 不入栈了
    for (int i = 0; i < numsSize && size > 0; i++)
    {
        while(size !=0 && nums[stack[size-1]] < nums[i]){
            -- size;
            ret[stack[size]] = nums[i];
        }
    }
    
    return ret;
    




}


// @lc code=end


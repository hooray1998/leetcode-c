/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *arg1, const void *arg2){
    int a = *(int *)arg1;
    int b = *(int *)arg2;
    return a > b;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *ret = malloc(sizeof(int) * 2);
    int *copy = malloc(sizeof(int) * numsSize);
    memcpy(copy, nums, sizeof(int) * numsSize);
    int i=0, j=numsSize-1;

    *returnSize = 2;
    qsort(nums, numsSize, sizeof(int), cmp);

    while(i<j){
        if(nums[i]+nums[j] < target){
            ++i;
        }else if(nums[i]+nums[j] > target){
            --j;
        }else{
            break;
        }
    }
    ret[0] = ret[1] = -1;
    for(int k=0;k<numsSize;k++){
        if(copy[k] == nums[i] && ret[0] == -1){
            ret[0] = k;
        }
        else if(copy[k] == nums[j] && ret[1] == -1){
            ret[1] = k;
        }
    }
    return ret;
}
// @lc code=end


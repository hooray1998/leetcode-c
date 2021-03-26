/*
 * @lc app=leetcode.cn id=260 lang=c
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    // 1. 根据a^b的结果, 找到一个不为0的位, 根据这个位置, 将数组分为两组,
    // 2. 每组的异或的结果就是答案
    // 3. 注意取值范围, 如果sum为int类型则不通过

    long sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum ^= nums[i];
    }

    int diff = sum - (sum & sum - 1);
    long sum1 = 0, sum2 = 0;
    int *ret = malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++)
    {
        if((nums[i] & diff) == diff){
            sum1 ^= nums[i];
        }else{
            sum2 ^= nums[i];
        }
    }
    ret[0] = sum1;
    ret[1] = sum2;
    return ret;
}
// @lc code=end


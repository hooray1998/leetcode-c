/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start


int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for (size_t i = 0; i < numsSize; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}
// @lc code=end


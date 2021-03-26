/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 */

// @lc code=start


int missingNumber(int* nums, int numsSize){
    // 先异或 1-n
    // 然后异或这个数组, 剩余的就是答案
    int ans=0;
    for (size_t i = 0; i < numsSize; i++)
    {
        ans ^= i;
        ans ^= nums[i];
    }
    return ans ^ numsSize;
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=338 lang=c
 *
 * [338] 比特位计数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    // 动态规划
    // 如果第i个数最后一个数字是1, 则dp[i] = dp[i-1] + 1
    // 反之 dp[i] = dp[i>>1]
    int *dp = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    dp[0] = 0;
    for (size_t i = 1; i <= num; i++)
    {
        dp[i] = i & 1 ? dp[i-1] + 1 : dp[i>>1];
    }
    return dp;
}


// @lc code=end


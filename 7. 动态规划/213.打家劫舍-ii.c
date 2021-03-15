/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 * 分类讨论, 每户人家都有两种结果, 被打劫与不被打劫, 分类讨论第一家
 * 1. 打劫第一家, 忽略最后一家
 * 2. 不打劫第一家, 算上最后一家
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)

int rob(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }else if(numsSize == 1){
        return nums[0];
    }
    int *dp = malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);
    // 打劫第一家, 第二家直接跳过
    for(int i=2;i<numsSize-1;i++){
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }
    int max = dp[numsSize - 2] + nums[0];


    // 不打劫第一家, 从第二家开始
    memset(dp, 0, sizeof(int) * numsSize);
    dp[1] = nums[1];
    for(int i=2;i<numsSize;i++){
        dp[i] = MAX(dp[i-1], dp[i-2] + nums[i]);
    }

    return MAX(max, dp[numsSize-1]);
}
// @lc code=end


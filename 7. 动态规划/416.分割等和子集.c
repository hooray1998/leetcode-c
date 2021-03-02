/*
 * @lc app=leetcode.cn id=416 lang=c
 *
 * [416] 分割等和子集
 * 
 * 思路:
 * 1. 等价于0-1背包问题, 只是没有价值
 * 2. dp为0 / 1
 * 3. 注意初始化方法, dp[i][0] 均为true
 * 4. 可以进行空间压缩
 */

// @lc code=start


bool canPartition(int* nums, int numsSize){
    int sum=0;
    if(numsSize==0){
        return true;
    }

    for(int i=0;i<numsSize;i++){
        sum += nums[i];
    }
    if (sum%2==1){
        return false;
    }
    sum = sum/2;

    bool **dp = malloc(sizeof(bool*) * (numsSize + 1));
    for(int i=0;i<=numsSize;i++){
        dp[i] = malloc(sizeof(bool) * (sum + 1));
        memset(dp[i], 0, sizeof(bool) * (sum + 1));
        dp[i][0] = true; // 多少的物品都能把0填满
    }

    for(int i=1;i<=numsSize;i++){
        for(int j=1;j<=sum;j++){
            if(j>=nums[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[numsSize][sum];
}
// @lc code=end


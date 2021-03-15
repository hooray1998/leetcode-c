/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)

int maxSubArray(int* nums, int numsSize){
    // int *dp = malloc(sizeof(int) * (numsSize+1));
    int pre, dp;
    int max = INT_MIN;
    // memset(dp, 0, sizeof(int) * (numsSize+1));
    if(numsSize == 0){
        return 0;
    }

    pre = 0;
    for(int i=1;i<=numsSize;i++){
        dp = MAX(nums[i-1], nums[i-1] + pre);
        if(dp > max){
            max = dp;
        }
        pre = dp;
    }

    return max;

}
// @lc code=end


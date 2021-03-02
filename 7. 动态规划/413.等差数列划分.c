/*
 * @lc app=leetcode.cn id=413 lang=c
 *
 * [413] 等差数列划分
 * 
 */
// TODO: 理解为什么要最后求和

// @lc code=start


int numberOfArithmeticSlices(int* nums, int numsSize){
    if(numsSize<3){
        return 0;
    }
    int *dp = malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);


    int sum=0;
    for(int i=2;i<numsSize;i++){
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
            dp[i] = dp[i-1] + 1;
        }
        sum += dp[i];
    }
    return sum;

}
// @lc code=end


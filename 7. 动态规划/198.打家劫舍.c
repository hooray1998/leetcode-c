/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 * 
 * 思路:
 * 1. 数组记录房子数为i时能打劫的最多的金币数
 * 2. 打劫第i个: a[i] = a[i-2] + nums[i]; 
 * 3. 跳过第i个: a[i] = a[i-1];
 */

// @lc code=start

int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int rob(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    if(numsSize==1){
        return nums[0];
    }
    if(numsSize==2){
        return max(nums[0], nums[1]);
    }
    int *sum = malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    sum[1] = max(nums[0], nums[1]);
    for(int i=2;i<numsSize;i++){
        sum[i] = max(sum[i-1], sum[i-2] + nums[i]);
    }

    return sum[numsSize-1];

}
// @lc code=end


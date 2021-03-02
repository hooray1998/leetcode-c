/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start


int climbStairs(int n){
    int pre1=1, pre2=1, sum=0;
    if (n < 2){
        return 1;
    }
    for(int i=2;i<=n;i++){
        sum = pre1 + pre2;
        pre2 = pre1;
        pre1 = sum;
    }
    return sum;

}
// @lc code=end


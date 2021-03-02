/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 * 
 * memset(第二个参数是char类型, 只能填0, 否则就要一一赋值)
 */

// @lc code=start

int min(int a, int b)
{
    return (a<b)? a:b;
}

int numSquares(int n){
    int *dp = malloc(sizeof(int) * (n + 1));
    memset(dp, 0, 4 *n+4);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = n;
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i], dp[i-j*j]);
        }
        ++ dp[i];
        printf("i=%3d %3d\n", i, dp[i]);
    }
    return dp[n];
}
// @lc code=end


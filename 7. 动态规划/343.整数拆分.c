/*
 * @lc app=leetcode.cn id=343 lang=c
 *
 * [343] 整数拆分
 * // TODO: 考虑更简单的做法
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)

int integerBreak(int n){
    int *dp = malloc(sizeof(int) * (n+1));
    memset(dp, 0, sizeof(int) * (n+1));

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // 例如2 不拆的时候比拆开更大, 所以子数字拆不拆都要考虑
            dp[i] = MAX(dp[i], j * (i-j));
            dp[i] = MAX(dp[i], j * dp[i-j]);
        }
    }
    return dp[n];
}


// @lc code=end


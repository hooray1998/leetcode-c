/*
 * @lc app=leetcode.cn id=650 lang=c
 *
 * [650] 只有两个键的键盘
 * 
 * dp[i] = dp[j] + dp[i/j]
 * 写个例子就出来公式了, 很简单
 */

// @lc code=start
int min(int a, int b)
{
    return (a<b)? a:b;
}

int minSteps(int n){
    int *dp = malloc(4 * (n+1));
    for(int i=0;i<=n;i++){
        dp[i] = n + 1;
    }

    dp[1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=i, count=1;j<=n;j+=i, count++){
            dp[j] = min(dp[j], dp[i] + count);
        }
        // for(int j=1;j<=n;j++){
        //     printf("%d ", dp[j]);
        // }
        // printf("\n");
    }

    return dp[n];
}


// @lc code=end


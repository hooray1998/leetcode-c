/*
 * @lc app=leetcode.cn id=322 lang=c
 *
 * [322] 零钱兑换
 * 
 * 完全背包问题
 * 
 * 
 * 每次取最小值, 
 * amout+2就是最大情况
 */

// @lc code=start

int min(int a, int b)
{
    return (a<b)? a:b;
}

int coinChange(int* coins, int coinsSize, int amount){
    // int *dp = malloc(sizeof(int) * (amount+1));
    // memset(dp, 0, sizeof(int) * (amount+1));
    int **dp = malloc(sizeof(int*) * (coinsSize + 1));
    for(int i=0;i<=coinsSize;i++){
        dp[i] = malloc(sizeof(int) * (amount + 1));
        memset(dp[i], 0, sizeof(int) * (amount + 1));
        for(int j=0;j<=amount;j++){
            dp[i][j] = amount + 2;
        }
        dp[i][0] = 0;
    }


    for(int i=1;i<=coinsSize;i++){
        for(int j=1;j<=amount;j++){
            if(j>=coins[i-1]){
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ret = dp[coinsSize][amount];
    return (ret == amount + 2)? -1 : ret;

}
// @lc code=end


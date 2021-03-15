/*
 * @lc app=leetcode.cn id=188 lang=c
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)

int maxProfit(int k, int* prices, int pricesSize){
    if(pricesSize<=1||k==0){
        return 0;
    }
    if(k>=pricesSize){
        int sum = 0;
        for(int i=1;i<pricesSize;i++){
            if(prices[i] > prices[i-1]){
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }

    int *buy, *sell;
    buy = malloc(sizeof(int) * k);
    sell = malloc(sizeof(int) * k);
    for(int i=0;i<k;i++){
        buy[i] = -prices[0];
        sell[i] = 0;
    }

    for(int i=0;i<pricesSize;i++){
        buy[0] = MAX(buy[0], -prices[i]);
        sell[0] = MAX(sell[0], buy[0] +prices[i]);
        for (int j = 1; j < k; j++)
        {
            buy[j] = MAX(buy[j], sell[j-1]-prices[i]);
            sell[j] = MAX(sell[j], buy[j] +prices[i]);
        }
    }

    // TODO: 实际上此时输出sell[k-1]即可, 如何证明它一定是最大的
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        max = MAX(max, sell[i]);
    }
    return max;
    

}
// @lc code=end


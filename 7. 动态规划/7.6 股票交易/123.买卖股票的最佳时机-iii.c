/*
 * @lc app=leetcode.cn id=123 lang=c
 *
 * [123] 买卖股票的最佳时机 III
 * 1. 两种做法:
 *  1. 贪心算法
 *          正向遍历: 记录第i天卖出所挣的最大值
 *          反向遍历: 记录第i天卖出所挣的最大值
 *          然后看dp1[i] + dp2[i+1]的最大值, 或者只买一次的最大值dp1[size-1], 返回最大的
 *  2. 动态规划:状态机
 *      理解这里面的状态变化
 *      还有1. 同一天买入并卖出收益为0
 *          2. buy1为什么取最大值, buy代表欠的钱, sell的时候挣钱, 所以buy越大,代表着欠的钱(绝对值)越小
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)
int maxProfit(int* prices, int pricesSize)
{
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for(int i=0;i<pricesSize;i++){
        buy1 = MAX(buy1, -prices[i]);
        sell1 = MAX(sell1, buy1+prices[i]);
        buy2 = MAX(buy2, sell1-prices[i]);
        sell2 = MAX(sell2, buy2+prices[i]);
    }

    return sell2;
}

int maxProfit2(int* prices, int pricesSize){
    if(pricesSize<=1){
        return 0;
    }

    // 计算到第i天卖出获取的最大利润
    int min = INT_MAX, max = INT_MIN;
    int *dp1 = malloc(sizeof(int) * pricesSize);
    memset(dp1, 0, sizeof(int) * pricesSize);
    int *dp2 = malloc(sizeof(int) * pricesSize);
    memset(dp2, 0, sizeof(int) * pricesSize);
    dp1[0] = 0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<min){
            min = prices[i];
        }
        if(i>0){
            dp1[i] = MAX(prices[i] - min, dp1[i-1]);
        }
    }


    dp2[pricesSize-1] = 0;
    for(int i=pricesSize-1;i>=0;i--){
        if(prices[i]>max){
            max = prices[i];
        }
        if(i<pricesSize-1){
            dp2[i] = MAX(max - prices[i], dp2[i+1]);
        }
    }
    max = 0;
    for(int i=0;i<pricesSize-1;i++){
        if(dp1[i] + dp2[i+1] > max){
            max = dp1[i] + dp2[i+1];
        }

    }
    return MAX(max, dp2[0]);
}
// @lc code=end


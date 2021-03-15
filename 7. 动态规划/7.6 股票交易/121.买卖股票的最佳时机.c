/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int min= INT_MAX;
    int max = INT_MIN;
    for(int i=0;i<pricesSize;i++){
        if(prices[i] < min){
            min = prices[i];
        }
        if(prices[i] - min > max){
            max = prices[i] - min;
        }
    }
    return max;

}
// @lc code=end


/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 */

// @lc code=start

#define MIN(a, b) ((a)<(b))? (a): (b)
#define MIN3(a, b, c) MIN(MIN(a, b), c)

int nthUglyNumber(int n){

    // NOTE: 动态规划, 用i2, i3, i5表示 还没被2 3 5乘过的数字的位置
    // 例如, 刚开始i2=i3=i5=0 表示第0个数字还没成过2,3,5
    // 然后分别乘以对应的数字, 找到其中最小的, 作为下一个丑数, 例如这个位置*3是最小的, 然后i3加一, 代表0这个位置乘以3已经计算过了
    // 下次再次计算的时候用下一个位置*3与其他的数字比较, 如果下一次i5的位置*5最小, 则i5++ 代表i5对应的位置已经乘过5了, 需要换成下一个

    int *dp = malloc(sizeof(int) * n);
    memset(dp, 0, sizeof(int) * n);

    int i2, i3, i5;
    i2 = i3 = i5 = 0;
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = MIN3(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
        // NOTE: 由于最小值可能重复, 所以不能写成else if
        if(dp[i] == dp[i2] * 2){
            ++ i2;
        }
        if(dp[i] == dp[i3] * 3){
            ++ i3;
        }
        if(dp[i] == dp[i5] * 5) {
            ++ i5;
        }
    }
    
    return dp[n-1];
}
// @lc code=end


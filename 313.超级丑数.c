/*
 * @lc app=leetcode.cn id=313 lang=c
 *
 * [313] 超级丑数
 */

// @lc code=start

#define MIN(a, b) ((a)<(b))? (a): (b)

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    if(primes == NULL || primesSize == 0 || n <= 1){
        return 1;
    }
    int *dp = malloc(sizeof(int) * n);
    int *loc = malloc(sizeof(int) * primesSize);
    memset(dp, 0, sizeof(int) * n);
    memset(loc, 0, sizeof(int) * primesSize);

    int min;
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        min = INT_MAX;
        for (int j = 0; j < primesSize; j++) {
            min = MIN(min, dp[loc[j]] * primes[j]);
        }
        dp[i] = min;

        for (int j = 0; j < primesSize; j++) {
            if(min == dp[loc[j]] * primes[j]) {
                ++ loc[j];
            }
        }
    }

    return dp[n - 1];
}
// @lc code=end


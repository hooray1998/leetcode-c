/*
 * @lc app=leetcode.cn id=583 lang=c
 *
 * [583] 两个字符串的删除操作
 * // TODO: 空间待优化
 */

// @lc code=start

#define MIN(a, b) ((a)<(b))? (a): (b)

int minDistance(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int **dp = malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        dp[i] = malloc(sizeof(int) * (len2 + 1));
        memset(dp[i], 0, sizeof(int) * (len2 + 1));
    }

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0){
                dp[i][j] = j;
            }else if(j==0){
                dp[i][j] = i;
            }else if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = MIN(dp[i][j-1] + 1, dp[i-1][j] + 1);
            }
        }
    }

    return dp[len1][len2];
}
// @lc code=end


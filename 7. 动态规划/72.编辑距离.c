/*
 * @lc app=leetcode.cn id=72 lang=c
 *
 * [72] 编辑距离
 * dp[i][j] 表示str[0:i] str2[0:j] 的距离
 * 
 * 1. i == j dp[i][j] = dp[i-1][j-1]
 * 2. i != j  => 修改的消耗: dp[i-1][j-1] + 1
 *               删除/插入的消耗: dp[i][j-1] + 1  与dp[i-1][j] + 1  
 */

// @lc code=start
int min(int a, int b)
{
    return (a<b)? a:b;
}

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    int **dp = malloc(sizeof(int *) * (len1 + 1));
    for(int i=0;i<=len1;i++){
        dp[i] = malloc(sizeof(int) * (len2 + 1));
    }

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0){
                dp[i][j] = j;
            }else if(j==0){
                dp[i][j] = i;
            }else{
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(
                        min(dp[i][j-1] + 1, dp[i-1][j] + 1),
                        dp[i-1][j-1] + 1
                    );
                }
            }
        }
    }
    return dp[len1][len2];

}
// @lc code=end


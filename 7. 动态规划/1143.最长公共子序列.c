/*
 * @lc app=leetcode.cn id=1143 lang=c
 *
 * [1143] 最长公共子序列
 * 
 * 
 * 备注: 
 * 1. for循环从1开始遍历, 1代表数组的第一个元素, 所以获取该元素的时候使用text[i-1]
 */

// @lc code=start
int max(int a, int b)
{
    return (a>b)? a:b;
}

int longestCommonSubsequence(char * text1, char * text2){
    int len1, len2;
    len1 = strlen(text1);
    len2 = strlen(text2);

    int **dp;
    dp = malloc(sizeof(int *) * (len1 + 1));
    for(int i=0;i<=len1;i++){
        dp[i] = malloc(sizeof(int) * (len2 + 1));
        memset(dp[i], 0, sizeof(int) * (len2 + 1));
    }

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}
// @lc code=end


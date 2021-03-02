/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 * // TODO: 学会分类讨论
 * 1. 能力不足
 */

// @lc code=start


bool isMatch(char * s, char * p){
    int lens = strlen(s), lenp = strlen(p);
    bool **dp = malloc(sizeof(bool *) * (lens + 1));
    for(int i=0;i<=lens;i++){
        dp[i] = malloc(sizeof(bool) * (lenp + 1));
        memset(dp[i], 0, sizeof(bool) * (lenp + 1));
    }
    dp[0][0] = true;

    for(int j=1;j<=lenp;j++){
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-2]; // 此时j必然大于2, 有限制
        }else{
            dp[0][j] = false;
        }
    }

    for(int i=1;i<=lens;i++){
        for(int j=1;j<=lenp;j++){
            if(p[j-1] == '*'){
                if(p[j-2] != s[i-1] && p[j-2] != '.'){
                    dp[i][j] = dp[i][j-2]; 
                }else{
                    dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];
                }
            }else if(p[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            }else if(p[j-1] == s[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = false;
            }

        }
    }

    return dp[lens][lenp];

}
// @lc code=end


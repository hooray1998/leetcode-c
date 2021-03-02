/*
 * @lc app=leetcode.cn id=474 lang=c
 *
 * [474] 一和零
 */

// @lc code=start

int Count0(char *str){
    int count = 0;
    for(int i=0;i<strlen(str);i++){
        if(str[i] == '0'){
            ++ count;
        }
    }
    return count;
}

int Count1(char *str){
    int count = 0;
    for(int i=0;i<strlen(str);i++){
        if(str[i] == '1'){
            ++ count;
        }
    }
    return count;
}

int max(int a, int b){
    return (a>b)? a:b;
}
int findMaxForm(char ** strs, int strsSize, int m, int n){
    int **dp = malloc(sizeof(int *) * (m+1));
    for(int i=0;i<=m;i++){
        dp[i] = malloc(sizeof(int) * (n+1));
        memset(dp[i], 0, sizeof(int) * (n+1));
    }

    int count0, count1;
    for(int s=0;s<strsSize;s++){
        count0 = Count0(strs[s]);
        count1 = Count1(strs[s]);

        printf("%s =>:\n", strs[s]);
        for(int i=m;i>=count0;i--){
            for(int j=n;j>=count1;j--){
                // 每次刷新最大值
                dp[i][j] = max(dp[i][j], dp[i-count0][j-count1] + 1);
                // printf("%d ", dp[i][j]); // 加上此行会报错  ???????????FIXME
            }
            printf("\n");
        }


    }
    return dp[m][n];
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 * 
 * 思路:
 * 1. 二维数组dp[i][j]代表以i,j为右下角的正方形的边长
 * 2. 如果为0 则dp[i][j] = 0
 * 3. 如果为1 假设dp[i][j]为k, 则dp[i-1][j-1] dp[i-1][j] dp[i][j-1]的最小值不能小于k-1
 *    故(i,j) = min( (i-1, j-1) (i-1, j) (i, j-1) ) + 1
 */

// @lc code=start

int min(int a, int b, int c){
    a = (a<b)? a:b;
    return (a<c)?a:c;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0){
        return 0;
    }
    int **dp = malloc(sizeof(int*) * matrixSize);
    int max = 0;
    for(int i=0;i<matrixSize;i++){
        dp[i] = malloc(sizeof(int) * matrixColSize[i]);
        memset(dp[i], 0, sizeof(int) * matrixColSize[i]);
    }

    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize[i];j++){
            if(matrix[i][j]=='0'){
                dp[i][j] = 0;
            }else{
                if(i==0||j==0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1;
                }
                if(dp[i][j] > max){
                    max = dp[i][j];
                }
            }
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    return max * max;
}
// @lc code=end


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void debug(bool **mat, int n, char ***ret, int *retSize)
{
    ret[*retSize] = malloc(sizeof(char *) * n);
    // printf("debug:\n");
    for(int i=0;i<n;i++){
        ret[*retSize][i] = malloc(sizeof(char) * (n+1));
        for(int j=0;j<n;j++){
            if(mat[i][j]){
                ret[*retSize][i][j] = 'Q';
            }else{
                ret[*retSize][i][j] = '.';
            }
            ret[*retSize][i][n] = 0;
        }
    }
    ++ *retSize;
}

/*
只对新增的皇后进行检查, 不需要每次全量检查
*/
bool isValidQ(bool **arr, int n, int row, int col) {
    for (int i = 0; i <= row; ++i) {        // 只检查前面的行
        for (int j = 0; j < n; ++j) {
            if (i == row && j == col) {     // 这个点不检查
                continue;
            }
            if (i == row || j == col) {
                // 纵列检查
                if (arr[i][j] == 1) {
                    return 0;
                }
            } else if (abs(col - j) == abs(row - i)) {      // 在同一条斜线上的两个点，斜率为1
                // 斜线检查
                if (arr[i][j] == 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/*
不需要每次全量检查, 废除
bool permit(bool **mat, int level, int n)
{
    bool exist, exist2;
    // 判断每一列是否只有一个
    for(int i=0;i<n;i++){
        exist = false;
        for(int j=0;j<level;j++){
            if(mat[j][i]){
                if(!exist){
                    exist = true;
                }else{
                    return false;
                }
            }
        }
    }
    for(int i=0;i<level;i++){
        for(int j=0;j<n;j++){
            exist = false;
            exist2 = false;
            for(int d=0;d<level;d++){
                if(i-d>=0&&j+d<n&&mat[i-d][j+d]){
                    if(!exist){
                        exist=true;
                    }else{
                        return false;
                    }
                }
                if(i+d<level&&j+d<n&&mat[i+d][j+d]){
                    if(!exist2){
                        exist2=true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }

    return true;
}
*/

void backtracking(bool **mat, int level, int n, char ***ret, int *retSize)
{
    if(level == n){
        debug(mat, n, ret, retSize);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isValidQ(mat, n, level, i)){
            mat[level][i] = 1;
            backtracking(mat, level+1, n, ret, retSize);
            mat[level][i] = 0;
        }
    }

}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    if(n==0){
        return NULL;
    }
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1001);
    bool **mat = malloc(sizeof(bool *) * n);
    char ***ret = malloc(sizeof(char **) * 1001);
    for(int i=0;i<n;i++){
        mat[i] = malloc(sizeof(bool) * n);
        memset(mat[i], 0, sizeof(bool)*n);
    }

    backtracking(mat, 0, n, ret, returnSize);
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = n;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int size;
    int *retCol;
    char ***ret = solveNQueens(4, &size, &retCol);
    printf("%x %d %d", ret, size, retCol[0]);
    for(int i=0;i<size;i++){
        printf("[%d]:\n", i);
        for(int j=0;j<retCol[i];j++){
            printf("col: %d", retCol[i]);
            for(int jj=0;jj<retCol[i];jj++){
                printf("%c", ret[i][j][jj]);
            }
            printf("\n");
        }
    }
    return 0;
}

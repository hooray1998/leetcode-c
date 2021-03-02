#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 
示例：

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/**
 * 思路:
 * 
 * 1. 从各个边往中间进行遍历
 * 2. 使用两个数组分别记录, 减少不必要的麻烦(浪费了巨多的时间)
 * 
 * 注意:
 * 1. 为了防止递归死循环, 需要在dfs前对visit进行判断
 * 2. 审题严谨, 海拔相同也可以通过
 */ 

int direction[] = {-1, 0, 1, 0, -1};

void debug(char **visit, int row, int col)
{
    printf("visit:\n");
    for(int i=0;i<row; ++i){
        for(int j=0;j<col; ++j){
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
}

void dfs(int **mat, int row, int col, int x, int y, char **visit)
{
    if(visit[x][y]){
        return;
    }
    visit[x][y] = 1;
    int xx, yy;
    for(int i=0;i<4;i++){
        xx = x + direction[i];
        yy = y + direction[i+1];
        if(xx>=0&&xx<row&&yy>=0&&yy<col&&mat[x][y] <= mat[xx][yy]&&visit[xx][yy] == 0){
            dfs(mat, row, col, xx, yy, visit);
        }
    }
    // debug(visit, row, col);
}
int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize,
                      int* returnSize, int** returnColumnSizes)
{
    if (matrixSize==0 || matrixColSize[0]==0){
        *returnSize = 0;
        return NULL;
    }
    int row = matrixSize, col = matrixColSize[0];

    char **visit, **visit2;
    visit = (char **)malloc(sizeof(char *) * row);
    visit2 = (char **)malloc(sizeof(char *) * row);
    for(int i=0;i<row; i++) {
        visit[i] = (char *)malloc(sizeof(char) * col);
        visit2[i] = (char *)malloc(sizeof(char) * col);
        memset(visit[i], 0, col);
        memset(visit2[i], 0, col);
    }

    // left
    for(int i=0;i<row;i++){
        dfs(matrix, row, col, i, 0, visit);
    }
    // top
    for(int i=0;i<col;i++){
        dfs(matrix, row, col, 0, i, visit);
    }
    // right
    for(int i=0;i<row;i++){
        dfs(matrix, row, col, i, col-1, visit2);
    }
    // bottom
    for(int i=0;i<col;i++){
        dfs(matrix, row, col, row-1, i, visit2);
    }

    *returnSize = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(visit[i][j] && visit2[i][j]){
                (*returnSize) ++;
            }
        }
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    int **returnArray = (int **)malloc(sizeof(int *) * (*returnSize));
    int count = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(visit[i][j] && visit2[i][j]){
                (*returnColumnSizes)[count] = 2;
                // printf("[%d, %d] ", i, j);
                returnArray[count] = malloc(sizeof(int) * 2);
                returnArray[count][0] = i;
                returnArray[count][1] = j;
                ++ count;
            }
        }
    }

    return returnArray;
}

int main()
{
    int input[] = {
        1,2,2,3,5,
        3,2,3,4,4,
        2,4,5,3,1,
        6,7,1,4,5,
        5,1,1,2,4,
    };
    int column=5;
    int size=sizeof(input)/sizeof(int);
    int row = size / column;
    int *mat[row];
    int matColSize[row];
    for(int i=0; i<row; ++i){
        mat[i] = (int *)(input+i * column);
        matColSize[i] = column;
    }

    int returnSize, *returnColSize, **result;
    result = pacificAtlantic(mat, row, matColSize, &returnSize, &returnColSize);

    printf("output:\n");
    for(int i=0;i<returnSize;i++){
        // printf("col: %d", returnColSize[i]);
        for(int j=0;j<returnColSize[i];j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
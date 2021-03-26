/*
 * @lc app=leetcode.cn id=566 lang=c
 *
 * [566] 重塑矩阵
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize,
    int r, int c, int* returnSize, int** returnColumnSizes)
{
    int row = numsSize, col = numsColSize[0];
    if(row * col != r * c){
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }

    // 3*4 <= 4*3   2,1 (2*4 + 1 = 9) <= (9/3, 9%3) = (3, 0)
    int **ret, index, x, y;
    *returnSize = r;
    ret = malloc(sizeof(int *) * r);
    *returnColumnSizes = malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++)
    {
        ret[i] = malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;

        for (int j = 0; j < c; j++)
        {
            index = i * c + j;
            x = index / col;
            y = index % col;
            ret[i][j] = nums[x][y];
        }
    }
    
    return ret;


}


// @lc code=end


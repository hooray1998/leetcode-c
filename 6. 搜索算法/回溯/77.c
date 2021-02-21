#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
排列回溯的是交换的位置, 而组合回溯的是是否把当前节点加入组合中
1. 结果int, 越界 因为阶乘很大; 直接申请指针, 用到哪个malloc哪个
2. 所以不需要计算结果一共有多少, 遍历多少就是多少
3. 注意边界范围, 申请10000个足够
*/

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtracking(int **ret, int *retSize, int *comb, int *count, int pos, int n, int k)
{
    if(*count == k){
        ret[*retSize] = (int*)malloc(sizeof(int) * k);
        memcpy(ret[*retSize], comb, sizeof(int)*k);
        (*retSize)++;
        return;
    }

    for(int i=pos; i<=n;i++){
        comb[(*count)++] = i; // 把当前位置加入栈中
        backtracking(ret, retSize, comb, count, i+1, n, k); // 遍历下一个位置
        -- (*count);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    int **ret;
    if(n == 0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (10001));
    ret = (int **)malloc(sizeof(int*) * (10001));

    int count = 0;
    int *comb = malloc(sizeof(int) * k);

    backtracking(ret, returnSize, comb, &count, 1, n, k);
    for(int i=0;i<(*returnSize);i++){
        (*returnColumnSizes)[i] = k;
    }

    return ret;
}

int main()
{
    int input[] = {1};
    int returnSize, *returnColSize;
    int **ret = combine(13, 3, &returnSize, &returnColSize);

    printf("output:\n");
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColSize[i];j++){
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
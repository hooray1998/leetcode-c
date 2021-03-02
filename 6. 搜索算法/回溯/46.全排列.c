#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1. 每次level加一, 不是位置
2. 全排列的计算方法不对
*/

/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void swap(int *nums, int a, int b)
{
    int temp;
    temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void backtracking(int *nums, int numsSize, int level, int **ret, int *retSize)
{
    // 从第level个节点开始回溯, 
    // 该节点需要依次与后续节点交换, 包括自己
    // 
    // 如果该节点为最后一个节点, 直接输出
    if(level == numsSize-1){
        memcpy(ret[*retSize], nums, sizeof(int)*numsSize);
        (*retSize)++;
        return;
    }

    for(int i=level; i<numsSize; i++){
        swap(nums, level, i);
        backtracking(nums, numsSize, level+1, ret, retSize); // level加一
        swap(nums, level, i);
    }

}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret;
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    } 
    *returnSize = 1;
    for(int i=2;i<=numsSize;i++){
        *returnSize *= i;
    }
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    ret = (int **)malloc(sizeof(int*) * (*returnSize));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = numsSize;
        ret[i] = malloc(sizeof(int) * numsSize);
    }

    int count = 0;
    backtracking(nums, numsSize, 0, ret, &count);
    return ret;
}

int main()
{
    int input[] = {1, 3, 4};
    int returnSize, *returnColSize;
    int **ret = permute(input, sizeof(input)/sizeof(int), &returnSize, &returnColSize);

    printf("output:\n");
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColSize[i];j++){
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
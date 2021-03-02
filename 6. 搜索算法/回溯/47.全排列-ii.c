/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

/*

NOTE: 剪枝的使用

FIXME: fasdf
TODO: fasdf 
0. 这种是遍历所有元素的通用方法
1. 遇到重复元素则需要先排序
2. 剪枝: 如果当前元素使用了, 跳过; 如果当前元素和上一个元素重复, 并且上一个元素用过了, 则跳过.  
        实际上: visit[i-1] 为0/1跳过均可以, 分别代表使用重复元素的第一个或最后一个
*/

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *nums, int a, int b)
{
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
void backtracking(int *nums, int numsSize, int *comb, int *visit, int level, int **ret, int *returnSize)
{
    if(level == numsSize){
        ret[*returnSize] = malloc(sizeof(int) * numsSize);
        // memcpy(ret[*returnSize], nums, sizeof(int) * numsSize);
        // printf("output:\n");
        for(int i=0;i<numsSize;i++){
            ret[*returnSize][i] = comb[i];
            printf(":%d ", comb[i]);
        }
        ++ (*returnSize);
        printf("\n");
    }

    for(int i=0;i<numsSize;i++){
        if (visit[i]){
            continue;
        }
        if(i>0 && nums[i] == nums[i-1] && visit[i-1]){
            continue;
        }
        // if(i != level && nums[i] == nums[level]){
            printf("skip level=%d i=%d\n", level, i);
            // continue;
        // }
        visit[i] = 1;
        comb[level] = nums[i];
        backtracking(nums, numsSize, comb, visit, level+1, ret, returnSize);
        visit[i] = 0;
    }
}

int cmp(const void *arg1, const void *arg2)
{
    int a = *(int *)arg1;
    int b = *(int *)arg2;
    return a>b;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(numsSize == 0){
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i=0;i<numsSize;i++){
        printf("%d ", nums[i]);
    }

    int *comb = malloc(sizeof(int) * numsSize);
    int *visit = malloc(sizeof(int) * numsSize);
    memset(visit, 0, sizeof(int) * numsSize);
    memset(comb, 0, sizeof(int) * numsSize);

    int **ret;
    ret = malloc(sizeof(int *) * 100000);
    backtracking(nums, numsSize, comb, visit, 0, ret, returnSize);

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    printf("size:%d", *returnSize);
    return ret;
}
// @lc code=end


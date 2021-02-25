/*
 * @lc app=leetcode.cn id=40 lang=c
 *
 * [40] 组合总和 II
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *arg1, const void *arg2)
{
    return (*(int *)arg1) < (*(int *)arg2);
}

void backtracking(int *nums, int size, int *comb, int *visit, int sum, int pos, int level, int target, int *colSize, int *retSize, int **ret)
{
    if(sum == target){
        printf("output:");
        ret[*retSize] = malloc(sizeof(int) * level);
        colSize[*retSize] = level;
        for(int i=0;i<level;i++){
            printf("%d ", comb[i]);
            ret[*retSize][i] = comb[i];
        }
        ++ *retSize;

        printf("\n");
        return;
    }
    if(sum > target){
        return;
    }
    // 例如:  [10,7,6,5,2,1,1], target = 8,
    // 允许出现611, 但不允许出现两次521
    // 所以如果循环的同一层里面使用过了这个数字, 则不必再遍历

    //每次从pos后继续遍历, 不能每次都从第一个, 不然重复
    for(int i=pos;i<size;i++){
        if(visit[i]){
            continue;
        }
        if(i>pos&&nums[i] == nums[i-1]){
            continue;
        }
        visit[i] = 1;
        comb[level] = nums[i];
        sum += nums[i];
        backtracking(nums, size, comb, visit, sum, i+1, level+1, target, colSize, retSize, ret);
        sum -= nums[i];
        visit[i] = 0;
    }

}
int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(candidatesSize == 0){
        return NULL;
    }

    int **ret;
    ret = malloc(sizeof(int *) * 10000);
    *returnColumnSizes = malloc(sizeof(int) * 10000);
    int *comb, *visit;
    comb = malloc(sizeof(int) * candidatesSize);
    visit = malloc(sizeof(int) * candidatesSize);
    memset(comb, 0, sizeof(int) * candidatesSize);
    memset(visit, 0, sizeof(int) * candidatesSize);

    qsort(candidates, candidatesSize, sizeof(int), cmp);
    for(int i=0;i<candidatesSize;i++){
        printf("%d ", candidates[i]);
    }

    backtracking(candidates, candidatesSize, comb, visit, 0, 0, 0, target, *returnColumnSizes, returnSize, ret);


    return ret;
}
// @lc code=end


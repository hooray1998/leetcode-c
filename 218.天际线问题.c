/*
 * @lc app=leetcode.cn id=218 lang=c
 *
 * [218] 天际线问题
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    int *aa = *(int **)a;
    int *bb = *(int **)b;

    if(aa[0] == bb[0]){
        if(aa[1] == bb[1]){
            return aa[2] > bb[2];
        }else{
            return aa[1] > bb[1];
        }
    }else{
        return aa[0] > bb[0];
    }
}
void pushLeft(int **s, int *sSize, int **b, int i)
{
    s[*sSize][0] = b[i][]

}
void pushRight(int **s, int **b, int i)
{
    s[i][0]

}
void pushLeftRight(int **s, int **b, int i)
{
    s[i][0]

}
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    int **stack = malloc(sizeof(int *) * buildingsSize * 2);
    int size1 = 0, size2 = 0;
    int **stack2 = malloc(sizeof(int *) * buildingsSize * 2);
    qsort(buildings, buildingsSize, sizeof(int *), cmp);

    *returnSize = 0;
    for (size_t i = 0; i < buildingsSize; i++){
        printf("%d,%d=%d\n", buildings[i][0], buildings[i][1], buildings[i][2]);
    }

    push(stack, buildings, i);

    for (size_t i = 1; i < buildingsSize; i++)
    {
        if() { // 重合
    //         if(){ // 变高了 出栈,入栈(左上加右下)
                
    //         }else{ // 相等或小于 出栈, 

    //         }
            

    //     }else{ // 相隔

    //     }
    // }
    
    return NULL;

}
// @lc code=end


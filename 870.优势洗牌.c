/*
 * @lc app=leetcode.cn id=870 lang=c
 *
 * [870] 优势洗牌
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *arg1, const void *arg2)
{
    int *a = *(int **)arg1;
    int *b = *(int **)arg2;
    return a[0] - b[0];
}
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int **AA = malloc(sizeof(int *) * ASize);
    int **BB = malloc(sizeof(int *) * ASize);
    int **ANS = malloc(sizeof(int *) * ASize);
    int j = 0, end = ASize - 1;
    for (int i = 0; i < ASize; i++) {
        AA[i] = malloc(sizeof(int) * 2);
        BB[i] = malloc(sizeof(int) * 2);
        ANS[i] = malloc(sizeof(int) * 2);
        AA[i][0] = A[i];
        AA[i][1] = i;
        BB[i][0] = B[i];
        BB[i][1] = i;
    }

    qsort(AA, ASize, sizeof(int*), cmp);
    qsort(BB, ASize, sizeof(int*), cmp);

    // for (int i = 0; i < ASize; i++)
    // {
    //     printf("%d=%d\n", AA[i][0], AA[i][1]);
    // }
    // for (int i = 0; i < ASize; i++)
    // {
    //     printf("%d=%d\n", BB[i][0], BB[i][1]);
    // }

    for (int i = 0; i < ASize; i++)
    {
        if(AA[i][0] > BB[j][0]){
            ANS[i][1] = AA[i][0];
            ANS[i][0] = BB[j][1];
            ++ j;
        }else{
            ANS[i][1] = AA[i][0];
            ANS[i][0] = BB[end][1];
            -- end;
        }
    }
    
    qsort(ANS, ASize, sizeof(int*), cmp);
    for (int i = 0; i < ASize; i++)
    {
        // printf("%d====>%d\n", ANS[i][0], ANS[i][1]);
        A[i] = ANS[i][1];
    }

    
    *returnSize = ASize;
    return A;
}


// @lc code=end


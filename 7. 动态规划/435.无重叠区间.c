/*
 * @lc app=leetcode.cn id=435 lang=c
 *
 * [435] 无重叠区间
 */

// @lc code=start


int cmp(const void *a, const void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    if(pa[1] == pb[1]){
        return pa[0] - pb[0];
    }else{
        return pa[1] - pb[1];
    }
}


// 同 646 最长数对链
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize==0){
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    // for (int i = 0; i < intervalsSize; i++)
    // {
        // printf("%d %d\n", intervals[i][0], intervals[i][1]);
    // }

    int sum = 1;
    int last = intervals[0][1];
    for (int i = 0; i < intervalsSize; i++)
    {
        if(intervals[i][0] >= last){
            ++ sum;
            last = intervals[i][1];
        }
    }
    
    
    return intervalsSize - sum;
}



// @lc code=end


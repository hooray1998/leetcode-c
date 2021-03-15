/*
 * @lc app=leetcode.cn id=646 lang=c
 *
 * [646] 最长数对链
 * 
 * // TODO: 1. 方法1: 类似300递增子序列, 按照后面的元素排序, 然后dp[i]等于前面所有满足条件的元素的dp的最大值, 只是判断的时候有区别, 其他没区别
 *                          依然可以使用二分法优化
 * 2. 方法2: 贪心算法, 通过[1]->[0]的关系进行排序, 直接拿数据即可
 * 
 * 
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


int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    if(pairsSize==0){
        return 0;
    }

    qsort(pairs, pairsSize, sizeof(pairs[0]), cmp);
    // for (int i = 0; i < pairsSize; i++)
    // {
        // printf("%d %d\n", pairs[i][0], pairs[i][1]);
    // }

    int sum = 1;
    int last = pairs[0][1];
    for (int i = 0; i < pairsSize; i++)
    {
        if(pairs[i][0] > last){
            ++ sum;
            last = pairs[i][1];
        }
    }
    
    
    return sum;
}


// @lc code=end


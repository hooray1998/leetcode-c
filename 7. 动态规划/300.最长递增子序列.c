/*
 * @lc app=leetcode.cn id=300 lang=c
 *
 * [300] 最长递增子序列
 * 方法1: 
 * 动态规划: dp[i] 代表以i结尾的最长序列的长度
 * 1. 两层for循环
 * 2. // TODO: 二分查找优化时间复杂度
 *          dp[i] 表示 长度为i的递增子序列的最后一个数字
 *          1. 如果当前数组大于数组的所有元素, 则加入dp最后面
 *          2. 如果当前数字大于a 小于b, 则把b替换掉, 这样以后通过b构成递增序列的可能性更大一些
 *       通过这种更新方式, 该数组一定是递增的, 所以判断的时候可以通过二分法搜索
 * 
 * // TODO: 方法2: 贪心算法
 * 
 */

// @lc code=start

#define MAX(a, b) ((a)>(b))? (a): (b)

// 找到第一个大于等于key的位置
int *bound(int *start, int size, int key, int gt){
    int p, q, mid;
    p = 0;
    q = size-1;
    if(size==0){
        return NULL;
    }
    if(gt && key > start[size-1]){
        return NULL;
    }else if(!gt && key < start[0]){
        return NULL;
    }

    while(p<=q){
        mid = (p + q)/2;
        if(start[mid] == key){
            return start + mid;
        } else if(start[mid] < key){
            p = mid + 1;
        }else{
            q = mid - 1;
        }
    }

    return start + q + gt;
}


int lengthOfLIS(int* nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * (numsSize + 1));
    int size=0;
    for (int i = 0; i < numsSize; i++) {
        if(size == 0 || dp[size-1] < nums[i]){
            dp[size] = nums[i];
            ++ size;
        }else{
        // }else if(dp[0] > nums[i]){
            // dp[0] = nums[i];
            int *iter = bound(dp, size, nums[i], 1);
            *iter = nums[i];
        }

        // for (int j = 0; j < size; j++)
        // {
            // printf("%d ", dp[i]);
        // }
        // printf("num=%d size=%d:\n", nums[i], size);
        
    }
    
    return size;
}

int lengthOfLIS2(int* nums, int numsSize){
    if(numsSize == 0){
        return 0;
    }
    int *dp = malloc(sizeof(int) * (numsSize + 1));
    int max = INT_MIN;

    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i]){
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > max){
            max = dp[i];
        }
        printf("i=%d -> %d\n", i, dp[i]);
    }

    return max;
}
// @lc code=end


/*
 * @lc app=leetcode.cn id=239 lang=c
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMax(int *nums, int start, int end){
    int maxi = start;
    for (int i = start; i < end; i++)
    {
        if(nums[i] > nums[maxi]){
            maxi = i;
        }
    }
    return maxi;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize < k) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int *ret = malloc(sizeof(int) * (*returnSize));

    int *deque = malloc(sizeof(int) * numsSize);
    int front = 0, back=0;

    int maxi = -1;
    
    for (size_t i = 0; i < k; i++)
    {
        while(back != front && nums[i] > nums[deque[back-1]]){
            -- back;
        }
        deque[back++] = i;
    }
    

    ret[0] = nums[deque[front]];
    // 每次新增一个
    for (int end = k+1, start = 1; end <= numsSize; end++, start++)
    {
        if(front !=back && deque[front] < start){
            // FIXME: 可能每次都需要重新get, 超时
            ++ front;
        }
        while(back != front && nums[end-1] > nums[deque[back-1]]){
            -- back;
        }
        deque[back++] = end-1;

        // 每次都是返回最大值
        ret[start] = nums[deque[front]];
    }
    
    return ret;
}
// @lc code=end


int main(){
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int retSize;
    int *ret = maxSlidingWindow(nums, sizeof(nums)/4, 3, &retSize);
    printf("output:%d", retSize);
    for (int i = 0; i < retSize; i++)
    {
        printf("[%d]: %d\n", i, ret[i]);
    }
    

    return 0;
}
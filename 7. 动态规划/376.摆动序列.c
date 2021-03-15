/*
 * @lc app=leetcode.cn id=376 lang=c
 *
 * [376] 摆动序列
 * // TODO: 摆动序列的动态规划做法
 */

// @lc code=start


int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2){
        return numsSize;
    }
    // 特殊情况: 并不是所有情况都是sum+2, 如果全相等 则返回1
    int equal = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] != nums[i-1]){
            equal = 0;
            break;
        }
    }
    if(equal){
        return 1;
    }

    int pre = nums[1]-nums[0];
    int cur;
    int sum = 0;
    for (int i = 2; i < numsSize; i++)
    {
        cur = nums[i] - nums[i-1];
        if(pre == 0){
            pre = cur;
        }else if(cur == 0){
            continue;
        }else if((pre < 0 && cur > 0) || (pre > 0 && cur < 0)){
            ++ sum;
            pre = cur;
        }
    }
    return sum + 2;
}


// @lc code=end


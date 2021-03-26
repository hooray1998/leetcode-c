/*
 * @lc app=leetcode.cn id=287 lang=c
 *
 * [287] 寻找重复数
 */

// @lc code=start

//二分查找方法：区间 [1, 7][1,7] 的中位数是 4，遍历整个数组，统计小于等于 4 的整数的个数，如果不存在重复元素，最多为 44 个。等于 44 的时候区间 [1, 4][1,4] 内也可能有重复元素。但是，如果整个数组里小于等于 4 的整数的个数严格大于 44 的时候，就可以说明重复的数存在于区间 [1, 4][1,4]。
// 快慢指针方法: 我们对 \textit{nums}nums 数组建图，每个位置 ii 连一条 i\rightarrow \textit{nums}[i]i→nums[i] 的边。由于存在的重复的数字 \textit{target}target，因此 \textit{target}target 这个位置一定有起码两条指向它的边，因此整张图一定存在环，且我们要找到的 \textit{target}target 就是这个环的入口，

int findDuplicate(int* nums, int numsSize){
    int fast, slow;
    slow = nums[0];
    fast = nums[nums[0]];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}
// @lc code=end


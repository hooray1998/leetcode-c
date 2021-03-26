/*
 * @lc app=leetcode.cn id=461 lang=c
 *
 * [461] 汉明距离
 */

// @lc code=start


int hammingDistance(int x, int y){
    // 先异或, 然后统计1的个数
    x ^= y;
    y = 0;
    while(x){
        // 方法1:
        y += x & 1;
        x >>= 1;
        // // 方法2:
        // ++ y;
        // x &= x-1;
    }
    return y;
}


// @lc code=end


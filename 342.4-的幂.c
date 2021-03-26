/*
 * @lc app=leetcode.cn id=342 lang=c
 *
 * [342] 4的幂
 */

// @lc code=start


bool isPowerOfFour(int n){
    // 1. n > 0
    // 2. n 是 2的幂, 即 n & (n-1) == 0
    // 3. 这个数的1的位置一定在二进制的偶数位上, 例如100或者10000等等
    // == 的优先级高于 & !!!!!!!!!!!!!!!!!!!!!, 不加括号会导致错误产生
    return  (n > 0) && ((n & (n-1)) == 0) && ((n & 0xaaaaaaaa) == 0);
}
// @lc code=end


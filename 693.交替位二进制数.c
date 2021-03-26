/*
 * @lc app=leetcode.cn id=693 lang=c
 *
 * [693] 交替位二进制数
 */

// @lc code=start


bool hasAlternatingBits(int n){
    int cur, last = -1;

    while(n){
        cur = n&1;
        if(cur == last){
            return false;
        }
        last = cur;
        n >>= 1;
    }
    return true;
}
// @lc code=end


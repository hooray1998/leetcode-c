/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 */

// @lc code=start


int findComplement(int num){
    // 1. 先颠倒顺序, 然后逐个处理
    // 注意第二次操作的次数徐鹤第一次一致

    int ans = 0;
    int count=0;
    while(num){
        ans <<= 1;
        ans += num & 1;
        num >>= 1;
        count ++;
    }
    // printf("mid: %d\n", ans);
    num = 0;
    for(int i=0;i<count;i++){
        num <<= 1;
        num += (ans&1) ^ 1;
        ans >>= 1;
    }
    return num;
}
// @lc code=end


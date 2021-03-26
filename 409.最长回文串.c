/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 */

// @lc code=start


int longestPalindrome(char * s){
    int count[256] = {0};
    int ans = 0;

    for (int i = 0; i < strlen(s); i++) {
        ++ count[s[i]];
    }

    int single = 0;
    for (int i = 0; i < 256; i++) {
        if(count[i]%2 == 1){
            single = 1;
        }
        ans += (count[i]/2)*2;
    }

    return ans + single;
}
// @lc code=end


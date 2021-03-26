/*
 * @lc app=leetcode.cn id=647 lang=c
 *
 * [647] 回文子串
 */

// @lc code=start

int CountFrom(char *s, int left, int right, int size)
{
    int count = 0;
    while(left >= 0 && right < size && s[left] == s[right]){
        ++ count;
        -- left;
        ++ right;
    }
    return count;
}


int countSubstrings(char * s){
    int ans = 0, slen = strlen(s);

    for (int i = 0; i < slen; i++)
    {
        ans += CountFrom(s, i, i+1, slen);
        ans += CountFrom(s, i, i, slen);
    }
    return ans;
}


// @lc code=end


/*
 * @lc app=leetcode.cn id=318 lang=c
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start

bool judge(int a, int b)
{
    return (a & b) == 0;
}

int alpha2int(char *str, int *nums)
{
    int cur;
    int ans = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        cur = str[i] - 'a';
        ans |= nums[cur];
    }
    return ans;
}

int maxProduct(char ** words, int wordsSize){
    if(wordsSize < 2 || words == NULL){
        return 0;
    }

    int nums[30];
    int cur = 1;
    for (size_t i = 0; i < 26; i++)
    {
        nums[i] = cur;
        cur <<= 1;
    }

    int max = 0;
    int tmp, curlen, tmplen;
    for (size_t i = 0; i < wordsSize; i++)
    {
        cur = alpha2int(words[i], nums);
        curlen = strlen(words[i]);
        for (size_t j = i+1; j < wordsSize; j++)
        {
            tmp = alpha2int(words[j], nums);
            tmplen = strlen(words[j]);
            if(judge(cur, tmp) && (curlen * tmplen > max)){
                max = curlen * tmplen;
            }
        }
        
    }
    return max;
}
// @lc code=end


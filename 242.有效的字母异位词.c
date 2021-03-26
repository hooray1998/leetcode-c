/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start


bool isAnagram(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen){
        return false;
    }
    char alpha[26] = {0};

    for (int i = 0; i < sLen; i++) {
        if(alpha[s[i] - 'a'] == 0){
            alpha[s[i] - 'a'] = t[i];
        }else if(alpha[s[i] - 'a'] != t[i]){
            return false;
        }
    }
    return true;
}
// @lc code=end


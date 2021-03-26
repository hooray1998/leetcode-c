/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// @lc code=start


bool isIsomorphic(char * s, char * t){
    char sloc[256];
    char tloc[256];
    // NOTE: 细心一点呀哥................
    
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen){
        return false;
    }
    for (int i = 0; i < 256; i++) {
        sloc[i] = -1;
        tloc[i] = -1;
    }

    for (int i = 0; i < sLen; i++) {
        if(sloc[s[i]] == -1){
            sloc[s[i]] = i;
        }
        if(tloc[t[i]] == -1){
            tloc[t[i]] = i;
        }

        if(sloc[s[i]] != tloc[t[i]]){
            return false;
        }
    }
    
    return true;
}

// @lc code=end


int main(int argc, char const *argv[])
{
    printf("%d", isIsomorphic("badc", "baba"));
    return 0;
}

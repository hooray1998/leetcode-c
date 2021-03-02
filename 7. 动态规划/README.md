# 背包问题的压缩方法


0-1背包:
1. 状态转移方程
2. 压缩方法

完全背包:



### 10-正则表达式

样例
```cpp
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < n + 1; ++i) {
        if (p[i-1] == ’*’) {
            dp[0][i] = dp[0][i-2];
        }
    }
    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (p[j-1] == ’.’) { // 当前匹配, 等于上一次比较
                dp[i][j] = dp[i-1][j-1];
            } else if (p[j-1] != ’*’) { // 都是字母, 匹配与否看当前
                dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1];
            } else if (p[j-2] != s[i-1] && p[j-2] != ’.’) { // *情况, 如果前一个字符不能和当前的匹配, 那么*只能取0
                dp[i][j] = dp[i][j-2];
            } else { // 如果*修饰的字符可以与前一个匹配, 那么*可以为0, 1, 或者>1
            // 如果*>1 那么相当于删掉当前字符, 比较前一个字符的情况
                dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
            }
        }
    }
    return dp[m][n];
}
```

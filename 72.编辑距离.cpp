class Solution {
  public:
    string s1, s2;
    int    minDistance(string word1, string word2)
    {
        // first
        // s1 = word1;
        // s2 = word2;
        // return dp(word1.size() - 1, word2.size() - 1);

        // second
        int                 m = word1.size();
        int                 n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) +
                        1;
            }
        }
        return dp[m][n];
    }
    int dp(int i, int j)
    {
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;
        if (s1[i] == s2[j])
            return dp(i - 1, j - 1);
        return min(dp(i, j - 1), min(dp(i - 1, j), dp(i - 1, j - 1))) + 1;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

/*

bug:
1. 初始dp的时候，直接提交size，但应该是string的最后一个index,即size-1
2.min的时候只考虑了dp(i-1,j)和dp(i,j-1)两种情况，即只考虑了增加和删除两种情况。但替换不能被增加删除包含。比如替换1次的，用增加删除要2次。因此替换的情况不可以省略。

dp初始化：
1.因为i和j都被平移了一格，原来i==-1或j==-1的情况被放在了第一行/第一列，而且原来的初值是|i-j|，现在i=0或j=0，直接设置为j或i

notes:
1. c++和java的min不支持提交多个参数，python的才支持。

*/

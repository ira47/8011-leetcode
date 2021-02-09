class Solution {
  public:
    int change(int amount, vector<int>& coins)
    {
        int         n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

/*

状态：到第几个了/一共要换多少钱(还剩多少钱没有换)
value：直接记录有几种
dp[i][j]=dp[i-1][j]+dp[i-1][j-w[i-1]]+dp[i-1][j-2w[i-1]]+...
而dp[i][j-w[i-1]]=dp[i-1][j-w[i-1]]+dp[i-1][j-2w[i-1]]+...
所以dp[i][j]=dp[i-1][j]+dp[i][j-w[i-1]]

base case:
1. dp[0]=1，认为不是0种(因为可以找0元)，也不是>1的(大于1就不自然了)

notes:
1. 对于int[],长度获得方式是.length；对于vector，长度是.size()

bug:
1. n应该只有coins数量的意思。结果又把它当成amount了。
2. 没有判断i - coin<0的事情了

*/

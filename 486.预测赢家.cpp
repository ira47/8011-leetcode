class Solution {
  public:
    struct Pair
    {
        int first;
        int second;
        Pair() : first(0), second(0) {}
        Pair(int first, int second) : first(first), second(second) {}
    };
    bool PredictTheWinner(vector<int>& nums)
    {
        int                  n = nums.size();
        vector<vector<Pair>> dp(n, vector<Pair>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = Pair(nums[i], 0);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int left  = dp[i + 1][j].second + nums[i];
                int right = dp[i][j - 1].second + nums[j];
                if (left > right) {
                    dp[i][j] = Pair(left, dp[i + 1][j].first);
                }
                else {
                    dp[i][j] = Pair(right, dp[i][j - 1].first);
                }
            }
        }
        return dp[0][n - 1].first >= dp[0][n - 1].second;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

/*

有参构造: node(int a, string b, char c) :data(a), str(b), x(c){}
这里集合了struct构造，倒着dp，以及有难度的构造状态转移方程为一体。

bug:
1. 注意struct/class构造后要加分号
2. Pair要大写。小写的pair在c++已经内置了。
*/

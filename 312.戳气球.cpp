class Solution {
  public:
    int maxCoins(vector<int>& nums)
    {
        // first
        // int                 n = nums.size();
        // vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // vector<int>         money(n + 2);
        // money[0] = money[n + 1] = 1;
        // for (int i = 0; i < n; i++) {
        //     money[i + 1] = nums[i];
        // }
        // for (int i = n; i >= 0; i--) {
        //     for (int j = i + 1; j < n + 2; j++) {
        //         for (int k = i + 1; k < j; k++) {
        //             dp[i][j] =
        //                 max(dp[i][j], dp[i][k] + dp[k][j] +
        //                                   money[i] * money[j] * money[k]);
        //         }
        //     }
        // }
        // return dp[0][n + 1];

        // second
        int n            = nums.size();
        int dp[505][505] = {};
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n + 2; j++) {
                int mul = nums[i] * nums[j];
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] =
                        max(dp[i][j], dp[i][k] + dp[k][j] + mul * nums[k]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

/*

答案：
1.
补充两个虚拟气球0和n+1，value=1。因为最后一个气球的得分是nums[i],引入money[0]和money[n+1]相当于还是沿用money[i]*money[j]*money[k]，不需要修改格式。
2. dp[i][j]不包括i和j。因此dp[i][i]=0
3. 因为不需要知道是哪个k令结果最大，只需要将最大的结果保存在dp[i][j]即可。用max

bug:
1.
原来没有引入money的时候，建立的dp是n×n的，所以i从n-2开始。现在money长度为n+2，因此i从n开始。
2. 方程第二项不是dp[i][j]+money，而是dp[i][k]+dp[k][j]+money，和左右的值都有关。
3. c++中，当n是常数时，申请初始化的二维数组可以直接写int
dp[n][n]={}。否则还是vector<vector<int>>申请好一些。如果是默认值，则可以不输入
4. vector在第一个元素之前insert：nums.insert(nums.begin(), 1)

但是还是好慢啊，奇怪
70/70 cases passed (196 ms)
Your runtime beats 59.45 % of cpp submissions
Your memory usage beats 92.22 % of cpp submissions (8.7 MB)

*/
class Solution {
  public:
    int superEggDrop(int K, int N)
    {
        // first
        // vector<vector<int>> dp(N + 1, vector<int>(K, INT_MAX));
        // for (int i = 0; i <= N; i++)
        //     dp[i][0] = i;
        // for (int i = 1; i < K; i++)
        //     dp[0][i] = 0;
        // for (int j = 1; j < K; j++) {
        //     for (int i = 1; i <= N; i++) {
        //         for (int k = 1; k <= i; k++) {
        //             dp[i][j] =
        //                 min(dp[i][j], max(dp[i - k][j], dp[k - 1][j - 1]) +
        //                 1);
        //         }
        //     }
        // }
        // return dp[N][K - 1];

        // second
        int m = 0;
        for (vector<int> dp(K + 1); dp[K] < N; m++) {
            for (int i = K; i >= 1; i--) {
                dp[i] = dp[i - 1] + dp[i] + 1;
            }
        }
        return m;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

/*

题设：从F层投下来是不会破的
状态：楼层 鸡蛋的个数 尝试次数
。注意没有F。题目从输入到输出都和F的具体信息没有关系。
楼层状态指high-low，代表结果的最大波动范围。

限制是尝试次数-鸡蛋个数<C
dp模型：
1. (楼层，鸡蛋个数)->max尝试次数。dp[i][j]=max(dp[n-k][j],dp[k][j-1])+1
max因为要考虑最坏情况。即默认要考虑往一边走要尝试很多次的情况。但是对于不同的方案，要选择最小的。
为什么是dp[n-k][j]而不是dp[n-k][j-1]：此时鸡蛋没有破，说明F结果可能是[n,k],一共n-k+1个可能，放在i=n-k格子中；而dp[k][j-1]代表鸡蛋破了，说明F结果在[0,k-1]中，一共k种可能，放在i=k-1格子中。
要一列一列计算。(N+1)×K。base case: dp[i][0]=i;dp[0][j]=0;


2. (尝试次数，楼层)->min鸡蛋个数。
只需要当楼层=n时，第一次鸡蛋个数<=题目给出的


3.(尝试次数,鸡蛋个数)->楼层。似乎不可以，因为并不知道他们之间的限制关系是什么。
打脸了，真的是这个
结束条件：鸡蛋个数=K，尝试次数=m时，dp[K][m]刚好>=N
条件方程：dp[m][k]=dp[m-1][k-1]+dp[m-1][k]+1。刚好是显然的条件，超级神奇。
base case:dp[0][k]=0或者dp[1][k]=1;


编程注意点：
1. c++int最大值：INT_MAX
2. dp的第一列被赋值了，不影响j的终止条件是j<K
*/

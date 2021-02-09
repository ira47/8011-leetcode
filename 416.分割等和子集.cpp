class Solution {
  public:
    bool canPartition(vector<int>& nums)
    {
        // first
        // int sum = 0;
        // for (int num : nums)
        //     sum += num;
        // if (sum % 2)
        //     return false;
        // int n = nums.size();
        // sum /= 2;
        // vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = true;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= sum; j++) {
        //         if (j - nums[i - 1] < 0)
        //             dp[i][j] = dp[i - 1][j];
        //         else
        //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        //     }
        // }
        // return dp[n][sum];

        // second
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2)
            return false;
        int n = nums.size();
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= 1; j--) {
                if (j - nums[i - 1] >= 0 && dp[j - nums[i - 1]])
                    dp[j] = true;
            }
        }
        return dp[sum];
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

/*

状态：前n个东西/背包的大小
dp[i][j]=true/false，且true的含义不是装的下，而是刚好装满。
true的必然继承：dp[i-1][j]=true->dp[i][j]=true
true必然是从旧的true来的，只是可能他们不在同一列。不可能false->true

初始化
1. dp[i][0]=true。因为重量为0也算一列，所以一共有w+1列。
2. 为了从第一个物品开始就可以迭代，设立“0号物品”的dp表格。

细节：
1. 如果和为奇数，则必然不可能
2. 把所有的数字加起来：for (int num : nums)
3. 二维数组初始化：vector<vector<bool>> dp(n+1,vector<bool>(w+1,false));

*/

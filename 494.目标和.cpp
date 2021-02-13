class Solution {
  public:
    int result = 0;
    int findTargetSumWays(vector<int>& nums, int S)
    {
        // first
        // backtrack(nums, 0, (long)S);
        // return result;

        // second
    }
    void backtrack(vector<int>& nums, int index, long S)
    {
        if (index == nums.size()) {
            if (S == 0)
                result++;
            return;
        }
        backtrack(nums, index + 1, S + nums[index]);
        backtrack(nums, index + 1, S - nums[index]);
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和：一些数字填入+或-号来得到target
 */

/*

回溯：
先判断回溯条件，再选择，执行子程序，再撤销选择。
这里选择和撤销选择，其实可以直接写在递归函数中。
回溯也是某种意义上的递归，只是没有使用任何“经验”(?)

dp
两个方程：
    sum(A) - sum(B) = target
    sum(A) + sum(B) = sum
要求A，使sum(A)=(target+sum)/2
所以回到了刚才写过的子集划分问题。

*/
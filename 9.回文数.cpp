class Solution {
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long r = 0;
        int  o = x;
        int  remains;
        while (o) {
            r = 10 * r + o % 10;
            o /= 10;
        }
        if ((int)r == x)
            return true;
        else
            return false;
    }
};
// @lc code=end
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

/*

11510/11510 cases passed (12 ms)
Your runtime beats 77.3 % of cpp submissions
Your memory usage beats 98.4 % of cpp submissions (5.6 MB)

*/
